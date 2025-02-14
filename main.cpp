#include "main.hpp"
#include "comparator.cpp"

//map from the name of primitive to its pointer 
map <string,Primitive*> primitive_map;
//maps the injector to the primitives in the flow
map<Primitive*,Injector*> primitive_flow;
//maps the injector to the queues in the flow
map<Injector*,vector<Queue*>> queue_flow;
//maps the name of the node to its pointer
map<string, Node*> node_data;
//maps the name of primitive_in to node and node_name to primitive_out names
map<string,string> node_connections;
//maps the primitive(RR,PR,S,M) to a vector of nodes in each case 
map<string,vector<string>> node_names;
//maps the node_in to node_out
map<Node*, Node*> node_files;
//maps the server is connected to which primitive
map<string, string> server_track;

//function declaration 
void back_tracking(Node*,Queue*);
//void set_Q_Sink(Primitive* primitive_in);
void update_arbiter_service_process(Primitive* server_primitive, double t_cap, double Cs_square_cap);
void update_injection_process(vector<double> lambda_a,vector<double> Ca_square, double t_cap, vector<int>BUFFER_SIZE,vector<Queue*>& queues, vector<Node*>& nodes);
void update_arbiter_service_process(Primitive* server_primitive, double t_cap, double Cs_square_cap);
void set_network_primitive(Primitive* primitive_in);
double single_queue_waiting_time(double injection_rate, double service_time);
double* update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size);
vector<double> Merging_flow(vector<double>injection_rates,vector<double>coeff_inter_arrival_time);

//reads the file statistics.txt and creates the primitives
void read_statistics(const string &filename){
    //opening the input file
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        string field,value;

        //primitive to be created 
        Primitive* primitive=nullptr;

        //read the field parts (F1,PR1,..)
        getline(ss,field,'=');

        //read the values part
        getline(ss,value);

        //split the values by comma
        int pos=value.find(',');
        string firstValue=value.substr(0,pos);
        string secondValue=value.substr(pos+1);

        //create the corresponding primitive according to field
        if(field[0]=='F'){
            //injector
            primitive= new Injector(stod(firstValue),stod(secondValue),0);
	    if(primitive){
            cout<<"Created an Injector: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
	    }
        }
        //queue
	else if(field[0]=='Q'){
            primitive= new Queue(stod(firstValue),0.0,0.0,0.0);
	    if(primitive){
            cout<<"Created a Queue: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
	    }
        }
	//Server
	else if(field.substr(0,2) == "SR"){
		primitive=new Server(stod(firstValue),stod(secondValue));
		if(primitive){
			primitive_map[field] = primitive;
			cout<<"Created a Server: "<<field<<"\n";
		}
	}
        //merge
        else if(field[0]=='M'){
            primitive= new Merge(stoi(firstValue));
	    if(primitive){
            cout<<"Created a Merge: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
	    }
        }
        //split primitive
        else if(field.substr(0,5)=="Split"){
            // vector to store the probabilities
            vector<double> Probabilities;
            //obtain by parsing {p1;p2;p3...} by ;
            string probability_str=secondValue.substr(1,secondValue.length()-2);
            stringstream ss(probability_str);
            string probability;
            while(getline(ss,probability,';')){
                Probabilities.push_back(stod(probability));
            }
            primitive= new Split(stoi(firstValue),Probabilities);
	    if(primitive){
            cout<<"Created a Split: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
	    }
        
	}
	else if(field.substr(0,2)=="RR"){
	        primitive=new RoundRobinArbiter(stod(firstValue));
                primitive->activeFlag();
                cout<<"Created a RoundRobinArbiter\n";
                primitive_map[field]=primitive;
           

	}
	else if(field.substr(0,2)=="PR"){
               // primitive=new PriorityArbiter(0.0,0.0);
	        primitive=new PriorityArbiter(stod(firstValue));
                primitive->activeFlag();
                cout<<"Created a PriorityArbiter\n";
                primitive_map[field]=primitive;
	}

	if(primitive!=nullptr){
	     primitive->activeFlag();
	}

    }  
    //close the input file
    infile.close();
}

//set notes for primitives(arbiter,merg,split)
void set_nodes_for_primitive(Primitive* primitive, const vector<string> &node_names){
      vector<Node*> nodes;
      size_t index=0;
      for(const auto& node_name: node_names){
          auto it_node = node_data.find(node_name);
          if(it_node != node_data.end()){
             nodes.push_back(it_node->second);
          }
      }
      primitive->setNodes(nodes);
      if(dynamic_cast<RoundRobinArbiter*>(primitive)){
	      RoundRobinArbiter* rr_arbiter = dynamic_cast<RoundRobinArbiter*>(primitive);
	     vector<double>waiting_time = rr_arbiter->arbiter();
	     double zero_load_latency = rr_arbiter->getZeroLoadLatency();
	     for(int i=0; i<waiting_time.size(); ++i){
	      waiting_time[i]=waiting_time[i] + zero_load_latency;
	     }
	     for(const auto& node:nodes){
		     Primitive* primitive_in = node->getPrimitiveIn();
		     if(primitive_in){
			     Queue* queue=dynamic_cast<Queue*>(primitive_in);
			     if(queue){
				     if(index<waiting_time.size()){
			     		    queue->setWaitingTime(waiting_time[index]);
			                     ++index;
			  }
			}
		     }
	     
	     }
	     
      }
      if(dynamic_cast<PriorityArbiter*>(primitive)){
		 PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(primitive);
		 vector<double>waiting_time = pr_arbiter->arbiter();
		 double zero_load_latency = pr_arbiter->getZeroLoadLatency();
		 for(int i=0;i<waiting_time.size();++i){
		 waiting_time[i] = waiting_time[i]+zero_load_latency;
		 }
		 for(const auto& node:nodes){
			 Primitive* primitive_in = node->getPrimitiveIn();
			 if(primitive_in){
				 Queue* queue = dynamic_cast<Queue*>(primitive_in);
				 if(queue){
					 if(index<waiting_time.size()){
						 queue->setWaitingTime(waiting_time[index]);
						 ++index;
				 } 
			      } 
			 }
		     } 
	         }
       	}

	//creates the nodes and makes the connections to primitives for a particular line of network.txt 
	void create_node(const string &node_name,const string &source, const string &destination){
	   
	    Primitive* primitive_out;
	    Primitive* primitive_in;
	    double injection_rate=0.0;
	    double coeff_interarrival_time=0.0;
	  

	    //if destination is not present already create corresponding primitive
	    if(destination.substr(0,4)=="Sink"){
		primitive_out=new Sink;
		primitive_out->activeFlag();
		cout<<"Created a Sink\n";
		primitive_map[destination]=primitive_out;
	    } 

	    //if source is already present just make the pointers to the node
	    if(primitive_map.find(source)!=primitive_map.end()){
	       primitive_in=primitive_map[source];
	    }
	 
	    //if destination is already present just make pointers to them
	    if(primitive_map.find(destination)!=primitive_map.end()){
		primitive_out=primitive_map[destination];
	    }
	    
	    //check for the primitives in the flow of injector
	    auto iter = primitive_flow.find(primitive_in);
	    //if present  
	    if(iter!=primitive_flow.end()){
		//if present and also it is a queue then add it to queue_flow map
		if(primitive_in->isQueue()){
		    Injector* injector = dynamic_cast<Injector*>(primitive_flow[primitive_in]);
		    if(injector){
			Queue* queue=dynamic_cast<Queue*>(primitive_in);
			if(queue){
				auto& queues = queue_flow[injector];
				if(find(queues.begin(),queues.end(),queue)==queues.end()){
					 (queue_flow[injector]).push_back(queue);
				}
		}
		    }
		}
	    }

	    //injection_rate and coeff_interrarrival_times for node obtained from that of injector
	    if(primitive_in->isInjector()){ 
		Injector* injector = dynamic_cast<Injector*>(primitive_in);
		if(injector){
		    injection_rate = injector->getInjectionRate();
		    coeff_interarrival_time = injector->getCoeffInterArrivalTime();   
		}
		//map the injector to the next primitive
		primitive_flow[primitive_out]=injector;
	    }
	    else if(!primitive_in->isInjector()){
		//also in each case update the next primitive
		primitive_flow[primitive_out]=primitive_flow[primitive_in];
		//primitive_flow.erase(primitive_in);
	    }
	    
	    //create the node
	    Node* node = new Node(primitive_in, primitive_out, injection_rate, coeff_interarrival_time);
            //update the node_data here
	    node_data[node_name]=node;
	 

	    //update the node_connections
	    node_connections[source]=node_name;
	    node_connections[node_name]=destination;
	    
	    //for Q,PR,RR,M
	      if(!primitive_in->isInjector()){
		Node* node_in = nullptr;
		//iterate over node_connections
	    	for(auto it=node_connections.begin(); it!=node_connections.end(); it++){
			if(it->second == source){
				string key = it->first;
				auto node_name = node_data.find(key);
				if(node_name!=node_data.end()){
					node_in = node_name->second;
					node_files[node_in]=node;
				}
			}
		}
	    }
   if(primitive_in->isInjector() && primitive_out->isQueue()){
	 Queue* queue = dynamic_cast<Queue*>(primitive_out);
	     if(queue){
		 queue->setInjectionRate(injection_rate);
		 queue->setCoeffInterArrivalTime(coeff_interarrival_time);
		 node->setInjectionRate(injection_rate);
		 node->setCoeffInterArrivalTime(coeff_interarrival_time);
	    }
	
    }
  //when source is a Queue and destination is Sink
  //if(primitive_in->isQueue() && primitive_out->isSink()){
  //} 
   if(primitive_in->isRRarbiter() || primitive_in->isPRarbiter() && primitive_out->isServer()){
	Server* server =  dynamic_cast<Server*>(primitive_out);
	if(server){
		double service_time=0.0;
		double coeff_service_time=0.0;
		service_time = server->getServiceTime();
		coeff_service_time = server->getCoeffServiceTime();
		if(primitive_in->isPRarbiter()){
			PriorityArbiter* PrArbiter = dynamic_cast<PriorityArbiter*>(primitive_in);
			PrArbiter->setServiceTime(service_time);
			PrArbiter->setCoeffServiceTime(coeff_service_time);
		}
		else if(primitive_in->isRRarbiter()){
			RoundRobinArbiter* RRarbiter = dynamic_cast<RoundRobinArbiter*>(primitive_in);
			RRarbiter->setServiceTime(service_time);
			RRarbiter->setCoeffServiceTime(coeff_service_time);
		}

	}
	server_track[destination]=source;
	//setting average injection rate and coeff_inter_arrival_time to the node.
	string key=source;
	double avg_injection_rate = 0.0,injection_rates=0.0;
	double avg_coeff_inter_arrival_time = 0.0,coeff_inter_arrival_times=0.0;
	vector<double>injection_rates_list;
	vector<double>coeff_inter_arrival_time_list;
	vector<double>merged_flows;
        auto it =  node_names.find(key);
	if(it!=node_names.end()){
		vector<string>& node_name = it->second;
		for(const auto& nodes:node_name){
			auto node_it = node_data.find(nodes);
			if(node_it!=node_data.end()){
				Node* N = node_it->second;
				injection_rates = N->getInjectionRate();
				coeff_inter_arrival_times = N->getCoeffInterArrivalTime();
				 injection_rates_list.push_back(injection_rates);
                                coeff_inter_arrival_time_list.push_back(coeff_inter_arrival_times);

			}
		}
		 	
                        merged_flows = Merging_flow(injection_rates_list,coeff_inter_arrival_time_list);
                        avg_injection_rate = merged_flows[0];
                        avg_coeff_inter_arrival_time = merged_flows[1];
			node->setInjectionRate(avg_injection_rate);
                        node->setCoeffInterArrivalTime(avg_coeff_inter_arrival_time);
		
	}
		
   }
    if(primitive_in->isQueue() && primitive_out->isRRarbiter() || primitive_out->isPRarbiter()|| primitive_out->isServer()){
	    Queue* queue = dynamic_cast<Queue*>(primitive_in);
	    if(queue){
		    injection_rate = queue->getInjectionRate();
		    coeff_interarrival_time = queue->getCoeffInterArrivalTime();
		    node->setInjectionRate(injection_rate);
		    node->setCoeffInterArrivalTime(coeff_interarrival_time);
	    }
    }
    //Single Queue is Connected with server
    if(primitive_in->isQueue() && primitive_out->isServer()){
	    Queue* queue = dynamic_cast<Queue*>(primitive_in);
	    Server* server = dynamic_cast<Server*>(primitive_out);
	    if(queue && server){
	    	double injection_rate = queue->getInjectionRate();
		double coeff_inter_arrival_rate = queue->getCoeffInterArrivalTime();
		node->setInjectionRate(injection_rate);
		node->setCoeffInterArrivalTime(coeff_inter_arrival_rate);
		double service_time = server->getServiceTime();
		double waiting_time = single_queue_waiting_time(injection_rate,service_time);
		queue->setWaitingTime(waiting_time);
	    }
	    server_track[destination]=source;
    }
    if(primitive_in->isServer() && primitive_out->isMerge()){
	for(auto it=node_connections.begin();it!=node_connections.end();it++){
		if(it->second==source){
	        auto& nodes = it->first;
		Node* node_address = node_data[nodes];
		injection_rate = node_address->getInjectionRate();
		coeff_interarrival_time = node_address->getCoeffInterArrivalTime();
		node->setInjectionRate(injection_rate);
		node->setCoeffInterArrivalTime(coeff_interarrival_time);

		}
	}	
    }
    if(primitive_out->isRRarbiter() ||primitive_out->isPRarbiter() ||primitive_out->isMerge()){
        //for RR,PR,M extract nodes which have them as destination primitive
        for(auto it=node_connections.begin();it!=node_connections.end();it++){
            if(it->second==destination){
		    auto& nodes = node_names[destination];
		    //check if that node is already added to the list of the queues
		    if(find(nodes.begin(),nodes.end(),it->first)==nodes.end()){
                node_names[destination].push_back(it->first);
	       }
            }
        }
    }
    
    //for split extract nodes which have them as source primitive
    if(primitive_in->isSplit()){
        for(auto it=node_connections.begin();it!=node_connections.end();it++){
            if(it->first==source){
                node_names[source].push_back(it->second);
            }
        }
    }
    //if(primitive_in->isRRarbiter() ||primitive_in->isPRarbiter() || primitive_in->isMerge() || primitive_in->isSplit() && primitive_out->isQueue()){
     if(primitive_in->isServer() || primitive_in->isMerge() || primitive_in->isSplit() && primitive_out->isQueue()){
	    string key = source;
	     if(primitive_in->isServer()){
		     auto iter = server_track.find(source);
		     if(iter!=server_track.end()){
		     	key = iter->second;
		     }
	    }
	    //auto it=node_names.find(source);
	    auto it = node_names.find(key);
	    double avg_injection_rate =0.0;
	    double avg_coeff_interarrival_time=0.0;
	   vector<double> injection_rates;
	    vector<double> coeff_inter_arrival_time;
	    vector<double> merged_flows;

	    //new function implementation start
	    Queue* queue = dynamic_cast<Queue*>(primitive_out);
	    for(auto itr=node_files.begin();itr!=node_files.end();++itr){
	    	if(itr->second == node){
		Node* prev_node = itr->first;
		back_tracking(prev_node,queue);
		}
	    }
	    if(it!=node_names.end()){
		    vector<string> &node_name = it->second;
		    for(const auto& nodes:node_name){
			auto node_it = node_data.find(nodes);
			if(node_it != node_data.end()){
				Node* N= node_it->second;
		    		injection_rate = N->getInjectionRate();
				coeff_interarrival_time = N->getCoeffInterArrivalTime();
				injection_rates.push_back(injection_rate);
				coeff_inter_arrival_time.push_back(coeff_interarrival_time);
			}
			merged_flows = Merging_flow(injection_rates,coeff_inter_arrival_time);
			avg_injection_rate = merged_flows[0];
			avg_coeff_interarrival_time = merged_flows[1];
		//go to node_connection and check whose second part is that node
		for(auto it=node_connections.begin();it!=node_connections.end();it++){
			//get the first part of that node
			if(it->second==nodes){
				string connected_queue = it->first;
				//just check if it is a queue
				if(connected_queue[0]=='Q'){
				// if it is a queue then check the primitive flow and get the corresponding injection rate.
				
						Primitive* primitive_new=primitive_map[connected_queue];
						if(primitive_new){
							Injector* injector = dynamic_cast<Injector*>(primitive_flow[primitive_new]);
							if(injector){
								auto& queues = queue_flow[injector];
								Queue* queue = dynamic_cast<Queue*>(primitive_out);
								if(queue && std::find(queues.begin(),queues.end(),queue)==queues.end()){
											queue_flow[injector].push_back(queue);
										
										}

									}		
								}
			 }
			}	
			}
			} 
		    node->setInjectionRate(avg_injection_rate);
		    node->setCoeffInterArrivalTime(avg_coeff_interarrival_time);
		    Queue* queue = dynamic_cast<Queue*>(primitive_out);
		    if(queue){
			    queue->setInjectionRate(avg_injection_rate);
			    queue->setCoeffInterArrivalTime(avg_coeff_interarrival_time);
		    }

	    }

    
    }
    //connections made from source to destination with the help of this node
    cout<<"Connected: "<<source<<" -> "<<destination<<"\n";
}

//back tracking the nodes
void back_tracking(Node* node,Queue* queue){

	Primitive* primitive_in = node->getPrimitiveIn();
	string injector_name;
	for(auto it=primitive_map.begin();it!= primitive_map.end();++it){
		if(it->second == primitive_in){
			injector_name = it->first;
			break;
		}
	}
	if(injector_name[0]=='F'){
		Injector* injector = dynamic_cast<Injector*>(primitive_in);
		if(injector){
			auto& queues = queue_flow[injector];
			if(queue && std::find(queues.begin(),queues.end(),queue)==queues.end()){
				queue_flow[injector].push_back(queue);
			}
		}
	}
	else{
		for(auto it=node_files.begin();it!=node_files.end();++it){
			if(it->second == node){
				Node* prev_node = it->first;
				back_tracking(prev_node, queue);
			}
		}
	}
}

//set the nodes after reading of network.text file is done 
void set_nodes(){
    for(auto it=node_names.begin();it!=node_names.end();it++){
        Primitive* primitive=primitive_map[it->first];
	string str = it->first;
        //RoundRobinArbiter 
	if(str.substr(0,2)=="RR"){
            RoundRobinArbiter* rr_arbiter=dynamic_cast<RoundRobinArbiter*>(primitive);
            if(rr_arbiter){
		vector<string>string;
		string = it->second;
                set_nodes_for_primitive(rr_arbiter,it->second);
            }
        }
        //PriorityArbiter
	else if(str.substr(0,2)=="PR"){
            PriorityArbiter* pr_arbiter=dynamic_cast<PriorityArbiter*>(primitive);
            if(pr_arbiter){
		    vector<string>string;
		    string=it->second;
                    set_nodes_for_primitive(pr_arbiter,it->second);
            }
        }
        //Merge
	else if(str[0]=='M'){
            Merge* merge=dynamic_cast<Merge*>(primitive);
            if(merge){
                set_nodes_for_primitive(merge,it->second);
            }
        }

        //Split
	if(str.substr(0,5)=="Split"){ 
            Split* split=dynamic_cast<Split*>(primitive);
            if(split){
                set_nodes_for_primitive(split,it->second);
            }
        }
    }
}

void read_network_line(const string &line){
    //read every line of network.txt
    stringstream ss(line);
    string node_name,src_dest;
    //parse every line 
    getline(ss,node_name,':');
    getline(ss,src_dest);
    int pos=src_dest.find(',');
    string source=src_dest.substr(0,pos);
    string destination=src_dest.substr(pos+1);
    create_node(node_name,source,destination);
}
void set_network_primitive(Primitive* primitive){

  double injection_rate=0.0,coeff_interarrival_time=0.0;
  double service_time=0.0,coeff_service_time=0.0;
  int Buffer_size=0;
  
  double t_cap=0.0, Cs_square_cap=0.0;
  string source;

  //taking corresponding string of the primitive_in
  if(primitive){
  for(auto it=primitive_map.begin();it!=primitive_map.end();++it){
  	if(it->second == primitive){
	source = it->first;
	}
    } 
  }

  //taking injection_rate,coeff_inter_arrival_time and buffersize from the queue.
  Queue* queue = dynamic_cast<Queue*>(primitive);
  injection_rate = queue->getInjectionRate();
  coeff_interarrival_time = queue->getCoeffInterArrivalTime();
  Buffer_size = queue->getBufferSize();

//checking which node is connected to that queue.
for(auto it=node_connections.begin();it!=node_connections.end();++it){
 if(it->second == source){
 string connected_node = it->first;
 Node* node = node_data[connected_node];
 Primitive* primitive_in = node->getPrimitiveIn();
 //primitive_in is a server
 if(primitive_in->isServer()){
    Server* server_primitive = dynamic_cast<Server*>(primitive_in);
    service_time = server_primitive->getServiceTime();
    coeff_service_time = server_primitive->getCoeffServiceTime();
    double* service_process = update_service_process(injection_rate,coeff_interarrival_time,service_time,coeff_service_time,Buffer_size);
    t_cap = service_process[0];
    Cs_square_cap = service_process[1];
    
    //update the sevice time of the arbiter connected to that server
    update_arbiter_service_process(primitive_in,t_cap,Cs_square_cap);
 
 }

 //primitive_in is a Injector
 else if(primitive_in->isInjector()){}

 //primitive_in is a merge
 else if(primitive_in->isMerge()){}

 //primitive_in is a split
     }
   }
}
void read_network(const string &filename){     
    //open the second input file
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        read_network_line(line);
    }    
    set_nodes();
    //check Sink is getting full or not
    for(auto it=node_connections.begin();it!=node_connections.end();++it){
    	if(it->second == "Sink"){
	 Node* get_node = node_data[it->first];
	 Primitive* primitive_in = get_node->getPrimitiveIn();//address of the connected Queue.
	 set_network_primitive(primitive_in);
	}
    }
    set_nodes();
   cout<<"printing node_names.."<<endl;
   for(auto it=node_names.begin();it!=node_names.end();++it){
	cout<<"primitive: "<<it->first<<" connected nodes: ";
	for(const auto& itr:it->second){
		cout<<itr<<" ";}
	cout<<endl;
   }
   
   cout<<"printing queue_flow..."<<endl;
   for(auto it=queue_flow.begin();it!=queue_flow.end();++it){

	   string s1,s2;
	   for(auto itr=primitive_map.begin();itr!=primitive_map.end();++itr){
		   if(itr->second==it->first){
	 		  s1=itr->first;
			  cout<<"Flow: "<<s1<<"  Queues: ";
			  for(const auto& itr:it->second){
				Primitive* new_primitive = dynamic_cast<Primitive*>(itr);
				if(new_primitive){
				for(auto iter=primitive_map.begin();iter!=primitive_map.end();iter++){
				if(iter->second == new_primitive){
					s2=iter->first;
					cout<<s2<<" ";
				}
		}}
	   }
        }}
	cout<<endl;
   }
   
    infile.close(); 
}

void waiting_time_calc(){
    //iterate over the map to calculate waiting time of each injector
    for(auto it = queue_flow.cbegin(); it != queue_flow.cend(); ++it)
    {
        Injector* injector =it->first;
        //for every queue in the flow of the injector

        for(Queue* queue: it->second){
            double new_waiting_time= injector->getWaitingTime() + queue->getWaitingTime();
            injector->setWaitingTime(new_waiting_time);
        }
	//cout<<endl;
    }
}

void run_custom_input(const std::string &statistics_file, const std::string &network_file) {
    // Perform the main logic for a single custom input
    read_statistics(statistics_file);
    read_network(network_file);
    waiting_time_calc();
    //want to see after updation.
   // cout<<"priniting primitive_map"<<endl;
    for(auto it=primitive_map.begin();it!=primitive_map.end();++it){
	    if(it->first[0]=='F'){
		   
		    Injector* F = dynamic_cast<Injector*>(it->second);
	    	    cout<<"Injector: "<<it->first<<'\t'<<"Waiting time: "<<F->getWaitingTime()<<endl;
	    }
	    if(it->first[0]=='Q'){
		    Queue* Q = dynamic_cast<Queue*>(it->second);
		    cout<<"Queue: "<<it->first<<'\t'<<"Waiting time: "<<Q->getWaitingTime()<<endl;
	    }
    
    }
}

void regression_suite(){
    for (int i = 1; i <= 10; ++i) {
        //clear the maps for new set of inputs
        primitive_map.clear();
        primitive_flow.clear();
        queue_flow.clear();
        node_data.clear();
        node_connections.clear();
        node_names.clear();

        // Construct file names for input and expected output
        string inputFileName_1 = "statistics" + to_string(i) + ".txt";
        string inputFileName_2 = "network" + to_string(i) + ".txt";
        string expectedOutputFileName = "goldenlog" + to_string(i) + ".txt";
        string actualOutputFileName = "actual_output" + to_string(i) + ".txt";

        // Open the actual output file in write mode
        FILE* output_file = freopen(actualOutputFileName.c_str(), "w", stdout);
        if (!output_file) {
            std::cerr << "Error opening actual output file for case " << i << "." << std::endl;
            continue;
        }

        // Perform the main logic for each test case
        read_statistics(inputFileName_1);
        read_network(inputFileName_2);
        waiting_time_calc();

        // Close the file stream and restore stdout
        fclose(stdout);
        freopen("/dev/tty", "w", stdout); // Restore stdout to the console on Unix-like systems

        // Compare the outputs
        compare_files(actualOutputFileName, expectedOutputFileName, i);
    }
}

//Merging the flows
vector<double> Merging_flow(vector<double>injection_rates,vector<double>coeff_inter_arrival_time){
	vector<double> merging_flow;
	double avg_injection_rate =0.0;
	double avg_coeff_inter_arrival_time=0.0;
	for(int i=0;i<injection_rates.size();++i){
		avg_injection_rate += injection_rates[i];
		avg_coeff_inter_arrival_time += (injection_rates[i] * coeff_inter_arrival_time[i]);
	}
	avg_coeff_inter_arrival_time = avg_coeff_inter_arrival_time / avg_injection_rate ;
	merging_flow.push_back(avg_injection_rate);
	merging_flow.push_back(avg_coeff_inter_arrival_time);
return merging_flow;
}

//update arbiter's service process
void update_arbiter_service_process(Primitive* server_primitive, double t_cap, double Cs_square_cap){

string server;
for(auto it=primitive_map.begin(); it!=primitive_map.end(); ++it){
if(it->second==server_primitive){
	server = it->first;
     }
 }

//check which arbiter is connected to that server
string connected_primitive = server_track[server];

Primitive* primitive = primitive_map[connected_primitive];

if(primitive->isArbiter()){
  if(primitive->isRRarbiter()){
  RoundRobinArbiter* arbiter = dynamic_cast<RoundRobinArbiter*>(primitive);
  //update the service process of the RoundRobin arbiter
  arbiter->setServiceTime(t_cap);
  arbiter->setCoeffServiceTime(Cs_square_cap);
  }
  else if(primitive->isPRarbiter()){
  PriorityArbiter* arbiter = dynamic_cast<PriorityArbiter*>(primitive);
  //update the service_process od the Priority arbiter
  arbiter->setServiceTime(t_cap);
  arbiter->setCoeffServiceTime(Cs_square_cap);
  }

  //check node_names to get which nodes is connected to that arbiter
  vector<string> nodes_list = node_names[connected_primitive];
  vector<Node*>nodes;
  vector<Queue*>queues;
  vector<double> injection_rate_list;
  vector<double>Ca_square_list;
  vector<int>Buffer_size_list;

  double injection_rate=0.0, Ca_square=0.0;
  int buffer_size = 0;

  //taking list of the nodes connected to that arbiter
 for(const auto& node_name:nodes_list)
 {
	auto it_node = node_data.find(node_name);
	if(it_node!=node_data.end()){
		nodes.push_back(it_node->second);
	}
 } 

 //taking list of the queues connected to that arbiter
 for(const auto& node:nodes){
	Primitive* primitive_in=node->getPrimitiveIn();
	if(primitive_in->isQueue()){
	Queue* queue = dynamic_cast<Queue*>(primitive_in);
	injection_rate = queue->getInjectionRate();
	Ca_square = queue->getCoeffInterArrivalTime();
	buffer_size = queue->getBufferSize();
	queues.push_back(queue);
	injection_rate_list.push_back(injection_rate);
	Ca_square_list.push_back(Ca_square);
	Buffer_size_list.push_back(buffer_size);	
	}
 } 
 update_injection_process(injection_rate_list, Ca_square_list, t_cap, Buffer_size_list, queues, nodes);
 //check the node_files
 for(const auto& node_name:nodes){
 	for(auto it=node_files.begin(); it!=node_files.end(); ++it){
	if(it->second == node_name){
	Node* node_prev = it->first;
	injection_rate = node_name->getInjectionRate();
	Ca_square = node_name->getCoeffInterArrivalTime();
	node_prev->setInjectionRate(injection_rate);
	node_prev->setCoeffInterArrivalTime(Ca_square);
	Primitive* primitive_in_node = node_prev->getPrimitiveIn();
	Primitive* primitive_out_node = node_prev->getPrimitiveOut();

	//if server is connected to the Queue
	if(primitive_in_node->isServer() && primitive_out_node->isQueue()){
		set_network_primitive(primitive_out_node);
	}

	//if Injector is connected to the Queue
	else if(primitive_in_node->isInjector() && primitive_out_node->isQueue()){
		Injector* injector = dynamic_cast<Injector*>(primitive_in_node);
		double updated_injection_rate=0.0, updated_Ca_square =0.0;
		updated_injection_rate = node_prev->getInjectionRate();
		updated_Ca_square = node_prev->getCoeffInterArrivalTime();
		injector->setInjectionRate(updated_injection_rate);
		injector->setCoeffInterArrivalTime(updated_Ca_square);
	}
	}
	}
 }
}
else if(primitive->isQueue()){}
}

//update the Injection process
void update_injection_process(vector<double> lambda_a,vector<double> Ca_square, double t_cap, vector<int>BUFFER_SIZE,vector<Queue*>& queues, vector<Node*>& nodes){
vector<double> lambda_a_cap = lambda_a;
vector<double> Ca_square_cap = Ca_square;
vector<double> rho(lambda_a.size(), 0.0);
vector<double> n(lambda_a.size(), 0.0);
vector<double> pi_j(lambda_a.size(), 0.0);

  for (size_t l = 0; l < lambda_a.size(); ++l) {
           // rho[l] = t_cap[l] * lambda_a_cap[l];
            rho[l] = t_cap * lambda_a[l];
            // Average occupancy calculation
            n[l] = rho[l] * (rho[l] - 1 + Ca_square_cap[l] + Ca_square_cap[l] * rho[l]) / (2 - 2 * rho[l]) + rho[l];

            // Probability of full queue using maximum entropy
                double sum_p_j = 0.0;
                for (int k = 0; k < BUFFER_SIZE[l]; ++k) {
                    double pow_val = (n[l] - rho[l]) / n[l];
                    sum_p_j += rho[l] * rho[l] * pow(pow_val, k + 1) / (n[l] - rho[l]);
                }
                pi_j[l] = rho[l] - sum_p_j;
            // Update lambda_a_cap and Ca_square_cap based on pi_j
            lambda_a_cap[l] =lambda_a[l]* (1 - pi_j[l]);
            Ca_square_cap[l] = Ca_square_cap[l] * (1 - pi_j[l]) + pi_j[l];
	    queues[l]->setInjectionRate(lambda_a_cap[l]);
	    queues[l]->setCoeffInterArrivalTime(Ca_square_cap[l]);
	    nodes[l]->setInjectionRate(lambda_a_cap[l]);
	    nodes[l]->setCoeffInterArrivalTime(Ca_square_cap[l]);
        }


}
double* update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size){
	
	double n_sink=0.0, p_sink=0.0, pi_sink=0.0,rho_sink=0.0,sum_p_sink=0.0;
        double t_cap =0.0,cs_square_cap=0.0;
        double* service_process;

        rho_sink = lambda_a_sink * service_time;
        //The average occupancy of Q_sink
        n_sink = rho_sink*(rho_sink - 1 + ca_square_sink + rho_sink*ca_square_sink)/(2-2*rho_sink)+rho_sink;

        //the probability that Q_sink contains k packets
        for(int k=0; k<buffer_size; ++k){
                double pow_val = (n_sink - rho_sink)/n_sink;
                sum_p_sink = rho_sink * rho_sink * pow(pow_val,k+1)/(n_sink - rho_sink);
        }
        //probability  that Qsink is full
        pi_sink = rho_sink - sum_p_sink;

        //Modified service process
        t_cap = service_time / (1 - pi_sink);
        cs_square_sink = pi_sink + cs_square_sink*(1 - pi_sink);
        service_process[0]=t_cap;
	service_process[1]=cs_square_sink;
return service_process;
}

//Single Queue Waiting Time calculation
double single_queue_waiting_time(double injection_rate, double service_time){
	double rho = injection_rate * service_time;
	double waiting_time = 0.0;
	waiting_time = 0.5*rho*(service_time - 1)/(1-rho);
return waiting_time;
}
//Round Robin Arbitration 
vector<double> roundrobin_model(vector<double> injection_rates, vector<double> interarrival_times, double service_time, vector<int> buffer_sizes){
   
    vector<double> waiting_times(injection_rates.size(), 0.0); // To store Waiting time of each queue
    // Initialization of intermediate parameters
    vector<double> lambda_a_cap = injection_rates;
    vector<double> ca_square_cap = interarrival_times;
    vector<double> rho(injection_rates.size(), 0.0);
    vector<double> n(injection_rates.size(), 0.0);
    vector<double> pi_j(injection_rates.size(), 0.0);
    vector<double> t_cap(injection_rates.size(), service_time);

    int iter = 12; // Number of iterations for convergence
    double rate =0;
    double total_injection_rate = 0.0;
    
    for (int i=0;i<injection_rates.size();++i) {
        rate = injection_rates[i];
        total_injection_rate += rate;
    }
    if(total_injection_rate < 0.998){
    // Waiting time before saturation
        for (int i = 0; i < iter; ++i) {
            for (int l = 0; l < injection_rates.size(); ++l) {
                if(injection_rates[l] != 0){
                // Calculate utilization rho
                rho[l] = t_cap[l] * lambda_a_cap[l];
		// Occupancy equation from finite WRR paper
                n[l] = rho[l] * (rho[l] - 1 + ca_square_cap[l] + ca_square_cap[l] * rho[l]) / (2 - 2 * rho[l]) + rho[l];
            }
        }
            for(int l=0; l<injection_rates.size();++l)
            {
               if(injection_rates[l] != 0){
                     double sum_min_occupancy = 0.0;
                     for(int m=0; m<injection_rates.size(); ++m){
                        if(m!=l){
                                sum_min_occupancy += lambda_a_cap[m];
                        }
                    }
                    t_cap[l] = service_time + service_time *min(1.0,(t_cap[l] * lambda_a_cap[l])) * min(1.0,t_cap[l]*sum_min_occupancy);
               }
            }

            // Calculate waiting times before saturation
            for(int l=0; l<injection_rates.size(); ++l){
                if(injection_rates[l]!=0){
                        waiting_times[l] = n[l] / lambda_a_cap[l] - service_time;
                }
            }
        }
    }
  // Check if the total injection rate leads to saturation
    else if (total_injection_rate >= 0.998) {

        // Calculate lambda_a_cap ensuring total utilization remains 1
        for (size_t i = 0; i < injection_rates.size(); ++i) {
                if(injection_rates[i]!= 0){
                    double other_sum = total_injection_rate - injection_rates[i];
                    lambda_a_cap[i] = min(injection_rates[i], max(0.5, 1 - other_sum));
                }
        }

        for(size_t i = 0;i < injection_rates.size() ; ++i){
                if(injection_rates[i] != 0){
                    t_cap[i] = 1/lambda_a_cap[i];
                }
        }

        // Calculate ca_square_cap for each class after determining p_full from lambda_cap
        for (size_t i = 0; i < injection_rates.size(); ++i) {
                if(injection_rates[i]!=0){
                    double p_full = 1 - lambda_a_cap[i] / injection_rates[i];
                    ca_square_cap[i] = (1 - p_full) * (1 - injection_rates[i]);
                }
        }

        // Model for waiting time after saturation for each class
        for (size_t i = 0; i < injection_rates.size(); ++i) {
                if(injection_rates[i]!=0){
                    int buffer_size = buffer_sizes[i];
                    waiting_times[i] = (2 * buffer_size - 3) * (buffer_size + (2 - buffer_size) * ca_square_cap[i]) / (2 * lambda_a_cap[i] * buffer_size) + t_cap[i];
                }
        }
 }
    return waiting_times;
}

//Priority Arbitration 
vector<double> priority_model(const vector<double>& lambda_a, const vector<double>& Ca_square, double service_time,vector<int>& BUFFER_SIZE){
   
   // Initialization of intermediate parameters
    vector<double> lambda_a_cap = lambda_a;
    vector<double> Ca_square_cap = Ca_square;
    vector<double> rho(lambda_a.size(), 0.0);
    vector<double> n(lambda_a.size(), 0.0);
    vector<double> pi_j(lambda_a.size(), 0.0);
    vector<double> t_cap(lambda_a.size(), service_time);
    vector<double> waiting_times(lambda_a.size(), 0.0); // To store W1 and W2
    vector<double> residual_time(lambda_a.size(), 0.0); //To store residual time
    double den = 0,num = 0, utilization = 0;

    int iter = 12;// Number of iterations for convergence
    double rate=0.0;
    double total_injection_rates=0.0;
    double lambda_a_sink=0.0, Ca_square_sink=0.0, rho_sink=0.0,n_sink=0.0,pi_j_sink=0.0,sum_lambda_a_cap=0.0,sum_injection_rates=0.0;

    //calculating total injection rate
    for(int i=0; i<lambda_a.size(); ++i){
    	rate = lambda_a[i];
	total_injection_rates += rate ;
    }

    total_injection_rates = total_injection_rates * service_time;
   
    // calculating waiting time before saturation
   if(total_injection_rates < 0.998){    
   for (int i = 0; i < iter; ++i) {

        for (size_t l = 0; l < lambda_a.size(); ++l) {
	    rho[l] = t_cap[l] * lambda_a[l];
        }

 	 //  Residual time calculation
     	 for(int i=0;i<lambda_a.size(); ++i){
	 //for higher priority class
	 if(i==0){
	 	residual_time[0] = 0.5*rho[0]*(service_time-1);
	  }
	 //for lower priority class
	 else{
		residual_time[i] = 0;
	 	for(int l=0;l<i;++l){
		residual_time[i] += 0.5*rho[l]*(service_time+1);
		}
		residual_time[i] = residual_time[i]+(0.5*rho[i]*(service_time - 1));
	     } 
       }
       
        //Waiting time calculation W = R/1-rho 
 	for (size_t l = 0; l < lambda_a.size(); ++l){
    	//for higher priority queues
         if(l==0)
         {
             waiting_times[0] =residual_time[0] / (1 - rho[0]);
	 }
        //for lower_priority queues
        else{
            utilization = 0;
            for (size_t k = 0;k < l; ++k){
                   utilization += rho[k]*waiting_times[k];
             } 
            den = 0;
            for(size_t i=0;i<= l; ++i){
       	      den +=rho[i];
            }
           waiting_times[l] = (residual_time[l] + utilization) / (1 - den); 
          }
        } 
      }
  }
 // calculating waiting time after saturation
 if(total_injection_rates >=0.998){
	 cout<<"this is after saturation"<<endl;
// effective injection rate of the lower priority class
 for(int i=0; i<lambda_a.size(); ++i){
	 if(i==0){
	 	rho[0]=lambda_a[0]*service_time;
		lambda_a_cap[0] = 1.0/service_time * min(1.0,rho[0]);
	 }
	 else{
		double sum_rho_j = 0.0,temp=0.0,delay = 0.0;
		double P=0.0;
		for(int j=0; j <i ; ++j){
			rho[j] = lambda_a_cap[j] * t_cap[j];
			sum_rho_j += rho[j];

		}
		temp = 1.0/service_time * sum_rho_j;
	lambda_a_cap[i] = min(lambda_a[i],(1.0-temp));
	 }
}
	//rho[i] = lambda_a_cap[i] * t_cap[i];
	// probability that a lower_priority_class flit is delayed due to higher_priority_class
	//P = rho[0] +  lambda_a_cap[0] * (0.5 * rho[i] * (service_time-1.0));	
	//delay = t_cap[0] * P / (1.0-P);

	//calculating updated service time for lower priority class
	//t_cap[i] = t_cap[i] + delay;
	//Ca_square_cap[i] = 1.0 - lambda_a_cap[i];

	//Ca_square_cap[i] = 1 - lambda_a_cap[i];
	//double X = 1.0 / BUFFER_SIZE[i];
        //double X= BUFFER_SIZE[i];
	//n[i] = Ca_square_cap[i] / X + 1.0;
	//waiting_times[i] = n[i] / lambda_a_cap[i] - t_cap[i];

// }
 }
return waiting_times;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        
	std::cerr<<"Usage: "<<argv[0]<<" <mode> [statistics_file] [network_file]\n";
        std::cerr << "Modes:\n";
        std::cerr<<" custom <statistics_file> <network_file> - Run custom input logic\n";
        std::cerr << "  compare - Run comparison logic\n";

        return 1;
    }

    std::string mode = argv[1];
    if (mode == "custom") {
	if(argc<4){
		std::cerr<<"Error: Please provide both statistics and network files.\n";
		return 1;
	}
	std::string stats_file = argv[2];
	std::string network_file = argv[3];
        run_custom_input(stats_file,network_file);
    } else if (mode == "regression_suite") {
        regression_suite();
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    return 0;
}
