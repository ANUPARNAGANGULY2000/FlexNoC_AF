#include "main.hpp"
#include "comparator.cpp"
#include<cassert>

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
void update_arbiter_service_process(Server* server_primitive, double t_cap, double Cs_square_cap);
void set_network_primitive(Primitive* primitive_in);
double single_queue_waiting_time(double injection_rate, double service_time);
double* update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size);
vector<double> Merging_flow(vector<double>injection_rates,vector<double>coeff_inter_arrival_time);
void modify_service_process_for_RRarbiter(vector<Queue*>& queues,double service_time);
void modify_service_process_for_PRarbiter(vector<Queue*>& queues, double service_time);
Server* getServer(Node* node);
void read_dot_file(const string &filename);
void read_statistics(const string &field, const string &firstValue, const string &secondValue);
void ValidateConnection(const string& source, const string& destination);
void node_update_forward(vector<Node*>& nodes);
void update_injection_process_after_saturation(vector<Queue*>& queues, double updated_injection_rate);
void update_node_from_Queue(vector<Queue*>& queues);
string getPrimitiveName(Primitive* primitive);
string getConnectedNode(string primitive_string);
void server_to_arbiter_track(Server* server);
void finding_queue(Queue* queue);

string getPrimitiveName(Primitive* primitive){
	string primitive_name;
	for(auto key=primitive_map.begin(); key!=primitive_map.end(); ++key){
	    if(key->second == primitive){
	        primitive_name = key->first;
	    }
	}
 return primitive_name;
}

string getConnectedNode(string primitive_string){
     string key_string;
     for(auto key=node_connections.begin(); key!=node_connections.end(); ++key){
         if(key->second == primitive_string){
	      key_string = key->first;
	 }
     }
     return key_string;
}
//reads the file statistics.txt and creates the primitives
void read_statistics(const string &field, const string &firstValue, const string &secondValue){

        //primitive to be created 
        Primitive* primitive=nullptr;

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
                cout<<"Created a RoundRobinArbiter: "<<field<<"\n";
                primitive_map[field]=primitive;
           

	}
	else if(field.substr(0,2)=="PR"){
               // primitive=new PriorityArbiter(0.0,0.0);
	        primitive=new PriorityArbiter(stod(firstValue));
                primitive->activeFlag();
                cout<<"Created a PriorityArbiter: "<<field<<"\n";
                primitive_map[field]=primitive;
	}

	if(primitive!=nullptr){
	     primitive->activeFlag();
	}

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
	      rr_arbiter->arbiter();
      }
      if(dynamic_cast<PriorityArbiter*>(primitive)){
		 PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(primitive);
		 pr_arbiter->arbiter();
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
    
     for(auto itr=server_track.begin(); itr!=server_track.end(); ++itr){	
     string server_name=itr->first;
     string connected_primitive_name=itr->second;
     if(primitive_map.find(server_name)!=primitive_map.end() && primitive_map.find(connected_primitive_name)!=primitive_map.end()){
     Primitive* server_primitive=primitive_map[server_name];
     Primitive* connected_primitive=primitive_map[connected_primitive_name];
     //RoundRobin Arbitration
     if(connected_primitive->isRRarbiter()){
     	RoundRobinArbiter* rr_arbiter=dynamic_cast<RoundRobinArbiter*>(connected_primitive);
	if(rr_arbiter){
	   for(auto it=node_names.begin(); it!=node_names.end(); ++it){
	       if(it->first == connected_primitive_name){
	        set_nodes_for_primitive(rr_arbiter,it->second);
	       }
	   }
	}
     }
     //Priority Arbiter
     else if(connected_primitive->isPRarbiter()){
     	PriorityArbiter* pr_arbiter=dynamic_cast<PriorityArbiter*>(connected_primitive);
	if(pr_arbiter){
	  for(auto it=node_names.begin(); it!=node_names.end(); ++it){
	     if(it->first == connected_primitive_name){
	      set_nodes_for_primitive(pr_arbiter,it->second);
	     }
	  }
	}
     }
     else if(connected_primitive->isQueue()){
     	Queue* queue=dynamic_cast<Queue*>(connected_primitive);
	Server* server=dynamic_cast<Server*>(server_primitive);
	if(queue && server){
	  double injection_rate=queue->getInjectionRate();
	  double service_time=server->getServiceTime();
	  double waiting_time=single_queue_waiting_time(injection_rate,service_time);
	  queue->setWaitingTime(waiting_time);
	}
     }
     }  	
     }
}
//validate source and destination
void ValidateConnection(const string& source, const string& destination){
	
	if(source[0] == 'F'){
	  if(destination[0] != 'Q'){
	      std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but is expected to connected with Queue "<<endl;
	      assert(false);
	  }
	}

	else if(source[0] == 'Q'){
	   if(destination.substr(0,2) != "RR" && destination.substr(0,2) != "SR" && destination.substr(0,2) != "PR"){
	   	std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with arbiter or server "<<endl;
		assert(false);
	   }
	}

	else if(source.substr(0,2) == "SR"){
	   if(destination.substr(0,4) != "Sink" && destination[0] != 'Q' && destination[0] != 'M'){
	        std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with either sink, Queue or Merge "<<endl;
		assert(false);
	   }
	}

        else if(source.substr(0,2) == "RR" || source.substr(0,2) == "PR"){
	    if(destination.substr(0,2) != "SR"){
	        std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with server "<<endl;
		assert(false);
	    }
	}
} 

//read dot file
void read_dot_file(const string &filename){
    
	ifstream infile(filename);
	string line;

	while(getline(infile,line)){
	bool isEdge = (line.find("->")!=string::npos);
	//for reading statistics 
	if(!isEdge){
		size_t position = line.find("label=\"");	
		if(position!=string::npos){
	            string field1 = line.substr(0,position);
		    size_t space_position = field1.find_first_not_of(" ");
		    size_t end_position = field1.find_first_of(" [", space_position);
		    string primitive_name = field1.substr(space_position, end_position - space_position);
		    size_t start = position + 7 ;
		    size_t end = line.find('"',start);
		    if(end!=string::npos){
		        string content = line.substr(start,end - start);
			std::istringstream labelStream(content);
			string key ;
			double first_value=0.0, second_value=0.0;
			while(labelStream >> key){
			   if(key == "rate"){
			       labelStream.ignore(2);
			       labelStream >> first_value;
			   }
			   else if(key == "coeff_interarrival_time"){
			   	labelStream.ignore(2);
				labelStream >> second_value;
			   }
			   else if(key == "buffer_size"){
			   	labelStream.ignore(2);
				labelStream >> first_value;
			   }
			   else if(key == "mode"){
			   	labelStream.ignore(2);
				labelStream >> second_value;
			   }
			   else if(key == "zero_load_latency"){
			   	labelStream.ignore(2);
				labelStream >> first_value;
			   }
			   else if(key == "Service_time"){
			   	labelStream.ignore(2);
				labelStream >> first_value;
			   }
			   else if(key == "coeff_service_time"){
			   	labelStream.ignore(2);
				labelStream >> second_value;
			   }
			   else if(key == "Sink"){
			   	labelStream >> first_value;
			   }
			
			}	
			 //call the read statistics function
		         read_statistics(primitive_name, to_string(first_value),to_string(second_value));
			  
	
		    }
		}
      	}

	// for reading network
	else{
		size_t arrowPosition = line.find("->");
		size_t labelPosition = line.find("[label=\"");
		size_t endPosition = line.find("\"];");

		if(arrowPosition != string::npos && labelPosition != string::npos && endPosition != string::npos){
			string source = line.substr(0,arrowPosition);
			source.erase(source.find_last_not_of(" ")+1);
			source.erase(0,source.find_first_not_of(" "));

			string destination = line.substr(arrowPosition+2,labelPosition-(arrowPosition + 2));
			destination.erase(destination.find_last_not_of(" ")+1);
			destination.erase(0,destination.find_first_not_of(" "));

			string nodename = line.substr(labelPosition + 8,endPosition-(labelPosition+8));
			
			//call the read network function
			ValidateConnection(source, destination);
			create_node(nodename,source,destination);
		}
	}
	}
	infile.close();
}

//To set network primitive
void set_network_primitive(Primitive* primitive){

    double injection_rate=0.0,coeff_interarrival_time=0.0;
    double service_time=0.0,coeff_service_time=0.0;
    int Buffer_size=0;
    double t_cap=0.0, Cs_square_cap=0.0;
    string source,source_new;
  
    //taking corresponding string of the primitive
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
       if(it->first == source){
             string connected_node = it->second;
	     Node* node = node_data[connected_node];
	     Server* server_primitive = getServer(node);
            // server_primitive is a server
	     if(server_primitive->isServer()){
 		 Primitive* primitive_inn = dynamic_cast<Primitive*>(server_primitive);
 		 if(primitive_inn){
	         for(auto it=primitive_map.begin();it!=primitive_map.end();++it){
       			 if(it->second == primitive_inn){
       			    source_new = it->first;
                         }
                   }
                 }
       service_time = server_primitive->getServiceTime();
       coeff_service_time = server_primitive->getCoeffServiceTime();
       double* service_process = update_service_process(injection_rate,coeff_interarrival_time,service_time,coeff_service_time,Buffer_size);
       t_cap = service_process[0];
       Cs_square_cap = service_process[1];
       for(auto itr=node_connections.begin();itr!=node_connections.end(); ++itr){
	    if(itr->second==source){
		 string prev_connected_node = itr->first;
		 Node* node_primitive= node_data[prev_connected_node];
		 Primitive* primitive_in = node_primitive->getPrimitiveIn();
		 if(primitive_in->isServer()){
		    Server* server = dynamic_cast<Server*>(primitive_in);
		    if(t_cap == service_time){
		                cout<<"service time not changed "<<endl;
				server_to_arbiter_track(server);
       		    }
      		    else if(t_cap!=service_time){
                	cout<<"service time has changed "<<endl;
		    	server->setServiceTime(t_cap);
		        server->setCoeffServiceTime(Cs_square_cap);
		        server->activeServiceTimeFlag();
  		    	//update the sevice time of the arbiter connected to that server
  		    	update_arbiter_service_process(server,t_cap,Cs_square_cap);
		   }
		  }
	       }
          }
 	} 

 	//primitive_in is a Injector
	// else if(primitive_in->isInjector()){}

 	//primitive_in is a merge
	// else if(primitive_in->isMerge()){}

	 //primitive_in is a split
       }	
    }
}
//service process updation if service_time of server is not change
void server_to_arbiter_track(Server* server){

	 string server_string = getPrimitiveName(server);
        //check which primitive(arbiter) is connected to that server
        string connected_primitive = server_track[server_string];
        Primitive* primitive = primitive_map[connected_primitive];
        if(primitive->isArbiter()){
          	//check node_names to get which nodes is connected to that arbiter
      		vector<string> nodes_list = node_names[connected_primitive];
     	        vector<Node*>nodes;
      		vector<Queue*>queues;
      		//taking list of the nodes connected to that arbiter
     		 for(const auto& node_name:nodes_list) {
        		auto node = node_data[node_name];
			Primitive* primitive_in = node->getPrimitiveIn();
			if(primitive_in->isQueue()){
				Queue* queue=dynamic_cast<Queue*>(primitive_in);
				if(queue->isInjectionRateUpdated()){
					finding_queue(queue);	
				}
			}
                  }
         }
}

//get the server which is connected to the Queue
Server* getServer(Node* node){

   Primitive* primitive_out = node->getPrimitiveOut();
   if(primitive_out->isServer()){
   	Server* server = dynamic_cast<Server*>(primitive_out);
	return server;
   }
   else{
   Node* next_node = node_files[node];
   if(next_node){
 	return getServer(next_node);}
   }
   return nullptr;
}


//void read_network(const string &filename){     
void read_network(){
    //open the second input file 
    /*cout<<" before Printing Primitive_map"<<endl;
    for(auto it=primitive_map.begin(); it!=primitive_map.end(); ++it){
        cout<<"Primitive: "<<it->first<<" Primitive* : "<<it->second;
	if(it->second->isInjector()){
        Injector* injector = dynamic_cast<Injector*>(it->second);
	cout<<"Injection_rate: "<<injector->getInjectionRate()<<" Coeff_inter: "<<injector->getCoeffInterArrivalTime()<<endl;
	}
        else if(it->second->isServer()){
        Server* server = dynamic_cast<Server*>(it->second);
	cout<<"Service_time: "<<server->getServiceTime()<<endl;
	}
	else if(it->second->isRRarbiter()){
	RoundRobinArbiter* rr_arbiter = dynamic_cast<RoundRobinArbiter*>(it->second);
	cout<<"Service_time: "<<rr_arbiter->getServiceTime()<<endl;
	}
	else if(it->second->isPRarbiter()){
	PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(it->second);
	cout<<"Service_time: "<<pr_arbiter->getServiceTime()<<endl;
	}
	else{
	 cout<<"\n";
	}
    }*/
    set_nodes();
    cout<<" after first set_nodes Printing Primitive_map"<<endl;
      for(auto it=primitive_map.begin(); it!=primitive_map.end(); ++it){
          cout<<"Primitive: "<<it->first<<" Primitive* : "<<it->second;
          if(it->second->isInjector()){
          Injector* injector = dynamic_cast<Injector*>(it->second);
          cout<<"Injection_rate: "<<injector->getInjectionRate()<<" Coeff_inter: "<<injector->getCoeffInterArrivalTime()<<endl;
          }
          else if(it->second->isServer()){
         Server* server = dynamic_cast<Server*>(it->second);
          cout<<"Service_time: "<<server->getServiceTime()<<endl;
          }
          else if(it->second->isRRarbiter()){
          RoundRobinArbiter* rr_arbiter = dynamic_cast<RoundRobinArbiter*>(it->second);
          cout<<"Service_time: "<<rr_arbiter->getServiceTime()<<endl;
          }
          else if(it->second->isPRarbiter()){
          PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(it->second);
          cout<<"Service_time: "<<pr_arbiter->getServiceTime()<<endl;
          }
             else if(it->second->isQueue()){
	     Queue* queue = dynamic_cast<Queue*>(it->second);
	     cout<<"Injection_rate: "<<queue->getInjectionRate()<<"\tCoeff_inter: "<<queue->getCoeffInterArrivalTime()<<"Waiting_time: "<<queue->getWaitingTime()<<endl;
	     }
          else{
           cout<<"\n";
          }
      }

      //printing node_data
      cout<<"printing node_data"<<endl;
      for(auto itr=node_data.begin(); itr!=node_data.end(); ++itr){
      cout<<"node: "<<itr->first<<" injection_rate: "<<itr->second->getInjectionRate()<<endl;
      }

    //check Sink is getting full or not
    for(auto it=node_connections.begin();it!=node_connections.end();++it){
    	if(it->second == "Sink"){
	 Node* get_node = node_data[it->first];
	 Primitive* primitive_in = get_node->getPrimitiveIn();//address of the connected Queue.
	 if(!primitive_in->isQueue()){
	    for(auto itr=node_files.begin(); itr!=node_files.end(); ++itr){
	 	if(itr->second == get_node){
		   Node* prev_node = itr->first;
		   primitive_in = prev_node->getPrimitiveIn();
		   if(primitive_in->isQueue()){
		        set_network_primitive(primitive_in);
		    }
		 }
	      }
	   }
	}
    }

     cout<<" after updating values Printing Primitive_map"<<endl;
      for(auto it=primitive_map.begin(); it!=primitive_map.end(); ++it){
          cout<<"Primitive: "<<it->first<<" Primitive* : "<<it->second;
          if(it->second->isInjector()){
          Injector* injector = dynamic_cast<Injector*>(it->second);
          cout<<"Injection_rate: "<<injector->getInjectionRate()<<" Coeff_inter: "<<injector->getCoeffInterArrivalTime()<<endl;
          }
          else if(it->second->isServer()){
         Server* server = dynamic_cast<Server*>(it->second);
          cout<<"Service_time: "<<server->getServiceTime()<<endl;
          }
          else if(it->second->isRRarbiter()){
          RoundRobinArbiter* rr_arbiter = dynamic_cast<RoundRobinArbiter*>(it->second);
          cout<<"Service_time: "<<rr_arbiter->getServiceTime()<<endl;
          }
          else if(it->second->isPRarbiter()){
          PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(it->second);
          cout<<"Service_time: "<<pr_arbiter->getServiceTime()<<endl;
          }
             else if(it->second->isQueue()){
             Queue* queue = dynamic_cast<Queue*>(it->second);
             cout<<"Injection_rate: "<<queue->getInjectionRate()<<"\tCoeff_inter: "<<queue->getCoeffInterArrivalTime()<<"Waiting_time: "<<queue->getWaitingTime()<<endl;
             }
          else{
           cout<<"\n";
          }
      }

    set_nodes();

  /*   cout<<" after second  set_nodes Printing Primitive_map"<<endl;
      for(auto it=primitive_map.begin(); it!=primitive_map.end(); ++it){
          cout<<"Primitive: "<<it->first<<" Primitive* : "<<it->second;
          if(it->second->isInjector()){
          Injector* injector = dynamic_cast<Injector*>(it->second);
          cout<<"Injection_rate: "<<injector->getInjectionRate()<<" Coeff_inter: "<<injector->getCoeffInterArrivalTime()<<endl;
          }
          else if(it->second->isServer()){
         Server* server = dynamic_cast<Server*>(it->second);
          cout<<"Service_time: "<<server->getServiceTime()<<endl;
          }
          else if(it->second->isRRarbiter()){
          RoundRobinArbiter* rr_arbiter = dynamic_cast<RoundRobinArbiter*>(it->second);
          cout<<"Service_time: "<<rr_arbiter->getServiceTime()<<endl;
          }
          else if(it->second->isPRarbiter()){
          PriorityArbiter* pr_arbiter = dynamic_cast<PriorityArbiter*>(it->second);
          cout<<"Service_time: "<<pr_arbiter->getServiceTime()<<endl;
          }
             else if(it->second->isQueue()){
             Queue* queue = dynamic_cast<Queue*>(it->second);
             cout<<"Injection_rate: "<<queue->getInjectionRate()<<"\tCoeff_inter: "<<queue->getCoeffInterArrivalTime()<<"Waiting_time: "<<queue->getWaitingTime()<<endl;
             }
          else{
           cout<<"\n";
          }
      }*/


   cout<<"printing node_names.."<<endl;
   for(auto it=node_names.begin();it!=node_names.end();++it){
	cout<<"primitive: "<<it->first<<" connected nodes: ";
	for(const auto& itr:it->second){
		cout<<itr<<" ";
	}
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
		                       }
				}
	                   }
                    }
	   }
	cout<<endl;
   }
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
    }
}

void run_custom_input(const std::string &dot_file) {
    // Perform the main logic for a single custom input
    read_dot_file(dot_file);
    read_network();
    waiting_time_calc();
    //want to see after updation.
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
        //read_statistics(inputFileName_1);
        //read_network(inputFileName_2);
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

//update node's values in forward directions
void node_update_forward(vector<Node*>& nodes){
	//check is there single node or multiple node
	int node_size = nodes.size();
	vector<Node*> connected_node;

	//if there is single node then update previous  node's value to next
	if(node_size == 1){
          Node* prev_node = nodes[0];
	  Node* next_node = node_files[prev_node];
	  if(next_node){
	      double injection_rate = prev_node ->getInjectionRate();
	      double coeff_interarrival_time = prev_node -> getCoeffInterArrivalTime();
	      next_node ->setInjectionRate(injection_rate);
	      next_node ->setCoeffInterArrivalTime(coeff_interarrival_time);
	       Primitive* primitive_out = next_node->getPrimitiveOut();
               if(primitive_out->isQueue()){
            		 Queue* queue = dynamic_cast<Queue*>(primitive_out);
             		 queue->setInjectionRate(injection_rate);
             		 queue->setCoeffInterArrivalTime(coeff_interarrival_time);
         }

	      connected_node.push_back(next_node);
	      node_update_forward(connected_node);
	  }
	}

	//if there is multiple nodes then merge it and update that to next node.
	else if(node_size > 1){
	   vector<double> injection_rates;
	   vector<double> coeff_inter_arrival_times;
	   for(auto node_index=0; node_index<nodes.size(); ++node_index){
	      Node* node_address = nodes[node_index];
	      double injectionRate = node_address->getInjectionRate();
	      double coeffInterArrivalTime = node_address->getCoeffInterArrivalTime();
	      injection_rates.push_back(injectionRate);
	      coeff_inter_arrival_times.push_back(coeffInterArrivalTime);
	   } 
	 vector<double> merged_flows = Merging_flow(injection_rates, coeff_inter_arrival_times);
         double avg_injection_rate = merged_flows[0];
	 double avg_coeff_inter_arrival_time = merged_flows[1];
	 Node* prev_node = nodes[0];// as both nodes destination is same so we are taking only one node
	 Node* next_node = node_files[prev_node];
	 next_node -> setInjectionRate(avg_injection_rate);
	 next_node -> setCoeffInterArrivalTime(avg_coeff_inter_arrival_time);
	 Primitive* primitive_out = next_node->getPrimitiveOut();
	 if(primitive_out->isQueue()){
	     Queue* queue = dynamic_cast<Queue*>(primitive_out);
	     queue->setInjectionRate(avg_injection_rate);
	     queue->setCoeffInterArrivalTime(avg_coeff_inter_arrival_time); 
	 }
	 connected_node.push_back(next_node);
	 node_update_forward(connected_node);
	}

}
//update node from queue
void update_node_from_Queue(vector<Queue*>& queues){
	cout<<"it's coming to update node from queue "<<endl;
    vector<string> queue_string;//to get Queue_string of the corresponding queue address
    for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
    	for(auto primitive=primitive_map.begin(); primitive!=primitive_map.end(); ++primitive){
	    if(primitive->second == queues[queue_index]){
		    cout<<"string: "<<primitive->first<<endl;
		queue_string.push_back(primitive->first);		    
           }
	
	}
    }
  
   vector<Node*> nodes;
   for(auto queue_index=0; queue_index!=queues.size(); ++queue_index){
       string node_name = node_connections[queue_string[queue_index]];//node which is connected to the queue
       Node* node_address = node_data[node_name];//address of the node
       cout<<"node name: "<<node_name<<"   node_address: "<<node_address<<endl;
         if(node_address){
       		double injection_rate = queues[queue_index]->getInjectionRate();
		double coeff_inter_arrival_time = queues[queue_index]->getCoeffInterArrivalTime();
	        node_address->setInjectionRate(injection_rate);
		node_address->setCoeffInterArrivalTime(coeff_inter_arrival_time);
		nodes.push_back(node_address);
        }
   }

   node_update_forward(nodes);
}

//update arbiter's service process
void update_arbiter_service_process(Server* server_primitive, double t_cap, double Cs_square_cap){

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
      for(const auto& node_name:nodes_list) {	
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
//finding nodes connected to that queue
void finding_queue(Queue* queue){
        string queue_name= getPrimitiveName(queue);
	string connected_node = getConnectedNode(queue_name);
	Node* node = node_data[connected_node]; //get address of the node which is connected to that queue
	if(node){
	    Primitive* primitive_in = node->getPrimitiveIn();
	    if(primitive_in->isServer()){// if this is server then we will get connected arbiter
	       string server_name = getPrimitiveName(primitive_in);
	       string connected_primitive = server_track[server_name];// taking which primitive is connected to that server
               Primitive* primitive = primitive_map[connected_primitive];
               if(primitive->isArbiter()){
                  //check node_names to get which nodes is connected to that arbiter
                   vector<string> nodes_list = node_names[connected_primitive];
		   vector<Queue*>queues;
      		   //taking list of the nodes connected to that arbiter
      		   for(const auto& node_name:nodes_list) {
       			 Node* it_node = node_data[node_name];
        		 if(it_node){
				Primitive* primitive = it_node->getPrimitiveIn();
				if(primitive->isQueue()){
				   Queue* queue_address = dynamic_cast<Queue*>(primitive);
				   queues.push_back(queue_address);
				}
                          }
                   }
		   double injection_rate = queue->getInjectionRate();
		   update_injection_process_after_saturation(queues,injection_rate);
                }
	     }
	    else if(primitive_in->isInjector()){
	    	double injection_rate = queue->getInjectionRate();
		double coeff_inter_arrival_time = queue->getCoeffInterArrivalTime();
		Injector* injector = dynamic_cast<Injector*>(primitive_in);
		injector->setInjectionRate(injection_rate);
		injector->setCoeffInterArrivalTime(coeff_inter_arrival_time);
	    } 
	}
}


//update injection process after saturation
void update_injection_process_after_saturation(vector<Queue*>& queues, double updated_injection_rate){
   double sum_of_injection_rate = 0.0;
   //calculating total injection_rate
   for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
        double injection_rate_of_queue = queues[queue_index]->getInjectionRate();
	sum_of_injection_rate += injection_rate_of_queue;
   }

   //getting proportion of updated_injection_rate and set it to each queue
   for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
   	double injection_rate_of_queue = queues[queue_index]->getInjectionRate();
	double update_injection_rate_of_queue = (injection_rate_of_queue/sum_of_injection_rate) * updated_injection_rate;
	double update_coeff_inter_arrival_time_of_queue = 1 - update_injection_rate_of_queue;
	queues[queue_index]->setInjectionRate(update_injection_rate_of_queue);
	queues[queue_index]->setCoeffInterArrivalTime(update_coeff_inter_arrival_time_of_queue);
	queues[queue_index]->activeInjectionRateUpdateFlag();
	finding_queue(queues[queue_index]);
   }
   
}

//update service process
double* update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size){
	
	double n_sink=0.0, pi_sink=0.0,rho_sink=0.0,sum_p_sink=0.0;
        double t_cap =0.0,cs_square_cap=0.0;
        double* service_process = (double*)malloc(2*sizeof(double));
	vector<double> p_sink(buffer_size,0.0);
	cout<<"injection_rate: "<<lambda_a_sink<<" Ca_square_sink: "<<ca_square_sink<<endl;
	cout<<"service_time: "<<service_time<<" cs_square_sink: "<<cs_square_sink<<" buffer_size: "<<buffer_size<<endl;
        rho_sink = lambda_a_sink * service_time;

	if(rho_sink<=0.998){
     		   //The average occupancy of Q_sink
        	n_sink = rho_sink*(rho_sink - 1 + ca_square_sink + rho_sink*ca_square_sink)/(2-2*rho_sink)+rho_sink;

       		// occupancy equation from WRR paper
          	//n_sink = (rho_sink*(rho_sink - 1 + ca_square_sink)/(2-2*rho_sink)) + (rho_sink*rho_sink*cs_square_sink)/(2-2*rho_sink)+rho_sink;
        	//the probability that Q_sink contains k packets
        	for(int k=0; k<buffer_size; ++k){
               		double pow_val = (n_sink - rho_sink)/n_sink;
              		 p_sink[k] = (rho_sink * rho_sink)/(n_sink - rho_sink) * pow(pow_val,k+1);
			//p_sink[k]=(1-rho_sink)*pow(rho_sink,k);
			sum_p_sink = sum_p_sink + p_sink[k];
        	}
       		 //probability  that Qsink is full
        	 pi_sink = rho_sink - sum_p_sink;
	 	cout<<"rho_sink: "<<rho_sink<<" sum_p_sink "<<sum_p_sink<<"pi_sink: "<<pi_sink<<endl;

                //Modified service process
   		if(pi_sink<1.0){
        	       t_cap = service_time / (1 - pi_sink);
         	}
	}
       else if(rho_sink>=0.998){
	     t_cap = service_time;
	     pi_sink = 1.0;
	}
	cout<<"previous service time was: "<<service_time<<endl;
	cout<<"updated service time is : "<<t_cap<<endl;
        cs_square_sink = pi_sink + cs_square_sink*(1 - pi_sink);
        service_process[0]=t_cap;
	service_process[1]=cs_square_sink;
return service_process;
}
     
//Single Queue Waiting Time calculation
double single_queue_waiting_time(double injection_rate, double service_time){
	cout<<"it's in the single queue"<<endl;
	double rho = injection_rate * service_time;
	double waiting_time = 0.0;
	waiting_time = 0.5*rho*(service_time - 1)/(1-rho);
	//cout<<"Injection_rate: "<<injection_rate<<" service_time : "<<service_time<<endl;
	//cout<<"Waiting time: "<<waiting_time<<endl;
return waiting_time;
}
//Round Robin Arbitration 
void roundrobin_model(vector<Queue*>& queues, RoundRobinArbiter* RRarbiter){

    vector<double> injection_rates;
    vector<double> interarrival_times;
    vector<int> buffer_sizes;
   
    cout<<"It's now in the round robinarbiter "<<endl;
    //getting injection_rates,interarrival_times,buffer_sizes from queue
    for(auto queue_number=0; queue_number<queues.size(); ++queue_number){
    double injection_rate = queues[queue_number]->getInjectionRate();
    double coeff_interarrival_time = queues[queue_number]->getCoeffInterArrivalTime();
    double buffer_size = queues[queue_number]->getBufferSize();
    injection_rates.push_back(injection_rate);
    interarrival_times.push_back(coeff_interarrival_time);
    buffer_sizes.push_back(buffer_size);
    //cout<<"here injection_rate: "<<injection_rate<<"\t coeff_inter_arrival time: " <<coeff_interarrival_time<<endl;
    }

    //getting service_time, zero_load_latency from RoundRobin Arbiter
    double service_time = RRarbiter->getServiceTime();
    //cout<<"service time is : "<<service_time<<endl;
    double zero_load_latency = RRarbiter->getZeroLoadLatency();


    vector<double> waiting_times(injection_rates.size(), 0.0); // To store Waiting time of each queue
    // Initialization of intermediate parameters
    vector<double> lambda_a_cap = injection_rates;
    vector<double> ca_square_cap = interarrival_times;
    vector<double> rho(injection_rates.size(), 0.0);
    vector<double> n(injection_rates.size(), 0.0);
    vector<double> pi_j(injection_rates.size(), 0.0);
    vector<double> t_cap(injection_rates.size(), service_time);

    int total_iteration = 1; // Number of iterations for convergence
    double rate =0;
    double total_utilization = 0.0;
    
    for (int i=0;i<injection_rates.size();++i) {
        rate = injection_rates[i];
        total_utilization += rate;
    }
    if(total_utilization < 0.998){
    // Waiting time before saturation
        for (int iteration = 0; iteration < total_iteration; ++iteration) {
            for (int queue_number = 0; queue_number < queues.size(); ++queue_number) {
                if(injection_rates[queue_number] != 0){
                // Calculate utilization rho
                rho[queue_number] = t_cap[queue_number] * lambda_a_cap[queue_number];
		// Occupancy equation from finite WRR paper
                n[queue_number] = rho[queue_number] * (rho[queue_number] - 1 + ca_square_cap[queue_number] + ca_square_cap[queue_number] * rho[queue_number]) / (2 - 2 * rho[queue_number]) + rho[queue_number];
            }
        }
            for(int queue_number=0; queue_number<queues.size();++queue_number)
            {
               if(injection_rates[queue_number] != 0){
                     double sum_min_occupancy = 0.0;
                     for(int other_queue=0; other_queue<queues.size(); ++other_queue){
                        if(other_queue!=queue_number){
                                sum_min_occupancy += lambda_a_cap[other_queue];
                        }
                    }
		    //modified service process for each queues
                    t_cap[queue_number] = service_time + service_time *min(1.0,(t_cap[queue_number] * lambda_a_cap[queue_number])) * min(1.0,t_cap[queue_number]*sum_min_occupancy);
		    //cout<<"updated t_cap for queue "<<queue_number<<" is: "<<t_cap[queue_number]<<endl;
               }
            }

            // Calculate waiting times before saturation
            for(int queue_number=0; queue_number<queues.size(); ++queue_number){
                if(injection_rates[queue_number]!=0){
                        waiting_times[queue_number] = n[queue_number] / lambda_a_cap[queue_number] - t_cap[queue_number];
			waiting_times[queue_number] = waiting_times[queue_number] + zero_load_latency ;
			//cout<<"waiting time for queue "<<queue_number<<" is: "<<waiting_times[queue_number]<<endl;
                        queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
                }
            }
        }
    }
  // Check if the total injection rate leads to saturation
    else if (total_utilization >= 0.998) {

        // Calculate lambda_a_cap ensuring total utilization remains 1
        for (size_t index = 0; index < injection_rates.size(); ++index) {
                if(injection_rates[index]!= 0){
                    double other_sum = total_utilization - injection_rates[index];
                    lambda_a_cap[index] = min(injection_rates[index], max(0.5, 1 - other_sum));
		    queues[index]->setInjectionRate(lambda_a_cap[index]);
		    queues[index]->activeInjectionRateUpdateFlag();
                }
        }

        for(size_t index = 0;index < injection_rates.size() ; ++index){
                if(injection_rates[index] != 0){
                    t_cap[index] = 1/lambda_a_cap[index];
                }
        }

        // Calculate ca_square_cap for each class after determining p_full from lambda_cap
        for (size_t index = 0; index < injection_rates.size(); ++index) {
                if(injection_rates[index]!=0){
                    double p_full = 1 - lambda_a_cap[index] / injection_rates[index];
                    ca_square_cap[index] = (1 - p_full) * (1 - injection_rates[index]);
		    queues[index]->setCoeffInterArrivalTime(ca_square_cap[index]);
                }
        }

        // Model for waiting time after saturation for each class
        for (size_t queue_number = 0; queue_number < queues.size(); ++queue_number) {
                if(injection_rates[queue_number]!=0){
                    int buffer_size = buffer_sizes[queue_number];
                    waiting_times[queue_number] = (2 * buffer_size - 3) * (buffer_size + (2 - buffer_size) * ca_square_cap[queue_number]) / (2 * lambda_a_cap[queue_number] * buffer_size			) + t_cap[queue_number];
		    waiting_times[queue_number] = waiting_times[queue_number] + zero_load_latency ;
		    queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
                }
        }
	update_node_from_Queue(queues);
 }
   // return waiting_times;

}

//Priority Arbitration 
void priority_model(vector<Queue*>& queues, PriorityArbiter* PRarbiter){ 
	//getting service_time and zero_load_latency from the Priority arbiter
	double service_time = PRarbiter->getServiceTime();
	cout<<"service_time of priority_model is : "<<service_time<<endl;
	double zero_load_latency = PRarbiter->getZeroLoadLatency();
	// Initialization of intermediate parameters
        vector<double> lambda;
	vector<double> lambda_a_cap(queues.size(),0.0);
	vector<double> Ca_square_cap(queues.size(),0.0);
        vector<double> t(queues.size(),service_time);
        vector<double> t_cap(queues.size(),service_time);
        vector<double> rho(queues.size(),0.0);
        vector<double> R(queues.size(),0.0);//residual time of each queue
        vector<double> rho_cap(queues.size(),0.0);
        vector<double> R_cap(queues.size(),0.0);
        vector<double> waiting_time(queues.size(),0.0);
	vector<int> Buffer_Size(queues.size(),0);
	vector<double> n(queues.size(),0.0);

	//taking injection rates from queues
        for(auto queue_index=0;queue_index<queues.size(); ++queue_index){
           double injection_rate = queues[queue_index]->getInjectionRate();
	   int buffer_size = queues[queue_index]->getBufferSize(); 
	   cout<<"injection_rate: "<<injection_rate<<endl;
           lambda.push_back(injection_rate);
	   Buffer_Size.push_back(buffer_size);
        }

    //calculating total injection rate
    double total_utilization = 0.0, rate = 0.0;
    for(int queue_index=0; queue_index<queues.size(); ++queue_index){
    	rate = lambda[queue_index];
	total_utilization += rate ;
    }

    total_utilization = total_utilization * service_time;
   
    // calculating waiting time before saturation
   if(total_utilization < 0.998){    
	 cout<<"before saturation"<<endl;
   	//calculate utilization of each queue
        for(auto queue_index=0;queue_index<lambda.size(); ++queue_index){
           rho[queue_index]=lambda[queue_index] * t[queue_index];
        }

        //calculate residual time of each queue
        for(int queue_index=0;queue_index<queues.size(); ++queue_index){
           //for higher priority class
            if(queue_index==0){
                R[0] = 0.5*rho[0]*(service_time-1);
            }
           //for lower priority class
            else{
                R[queue_index] = 0;
                for(int high_priority_queue_index=0; high_priority_queue_index<queue_index; ++high_priority_queue_index){
                   R[queue_index] += 0.5*rho[high_priority_queue_index]*(t[high_priority_queue_index]+1);
                }
                R[queue_index] = R[queue_index]+(0.5*rho[queue_index]*(t[queue_index] - 1));
              }
        }

	//calculate the probability of blocking and modify service time
      for(auto queue_index=0;queue_index<queues.size(); ++queue_index){
	  
      if(queue_index!=0){
        double P = 0.0, delta_t=0.0;
        double sum_rho=0.0, sum_lambda=0.0, sum_t = 0.0;
        for(auto high_priority_queue_index=0; high_priority_queue_index<queue_index; ++high_priority_queue_index){
           sum_rho += rho[high_priority_queue_index];
           sum_lambda += lambda[high_priority_queue_index];
           sum_t += t[high_priority_queue_index];
        }
        P = sum_rho + sum_lambda * R[queue_index];
        delta_t = sum_t * P/(1-P);
        t_cap[queue_index]=t[queue_index] + delta_t;
	
        //modified utilization
        rho_cap[queue_index]=lambda[queue_index]*t_cap[queue_index];

        //modified residual time
        R_cap[queue_index]=0.5*rho_cap[queue_index]*(t_cap[queue_index]-1);

        //modified waiting time
        waiting_time[queue_index]=R_cap[queue_index]/(1-rho_cap[queue_index]) + delta_t;

        //add zero load latency
        waiting_time[queue_index] = waiting_time[queue_index] + zero_load_latency;

        //set that waiting time to each queue
        queues[queue_index]->setWaitingTime(waiting_time[queue_index]);
	cout<<"set wait"<<waiting_time[queue_index]<<endl;
        }

     else if(queue_index==0){
          //modified utilization
        rho_cap[queue_index]=lambda[queue_index]*t_cap[queue_index];

        //modified residual time
        R_cap[queue_index]=0.5*rho_cap[queue_index]*(t_cap[queue_index]-1);

        //modified waiting time
        waiting_time[queue_index]=R_cap[queue_index]/(1-rho_cap[queue_index]);

        //add zero load latency
        waiting_time[queue_index] = waiting_time[queue_index] + zero_load_latency;

        //set that waiting time to each queue
        queues[queue_index]->setWaitingTime(waiting_time[queue_index]);
	cout<<"wait for high "<<waiting_time[queue_index]<<endl;
        }
      }
  }
 // calculating waiting time after saturation
if(total_utilization >=0.998){
	 cout<<" it's in the priority model after saturation "<<endl;
	 // effective injection rate of the lower priority class
     for(int priority_queue = 0; priority_queue < lambda.size(); ++priority_queue){
	 if(priority_queue == 0){
	 	rho[0]=lambda[0]*t_cap[0];
		lambda_a_cap[0] = 1.0/service_time * min(1.0,rho[0]);
		Ca_square_cap[0]=1.0 - lambda_a_cap[0];
		queues[priority_queue]->setInjectionRate(lambda_a_cap[0]);
		queues[priority_queue]->setCoeffInterArrivalTime(Ca_square_cap[0]);
		queues[priority_queue]->activeInjectionRateUpdateFlag();
		rho[0] = lambda_a_cap[0] * service_time;
		R[0] = 0.5 * rho[0] * (t_cap[0] - 1);
		waiting_time[0] = R[0] / (1 - rho[0] );
		waiting_time[0] = waiting_time[0] + zero_load_latency;
        	queues[priority_queue]->setWaitingTime(waiting_time[0]);
	 }
	 else{
		double total_rho = 0.0,temp=0.0;
		for(int high_priority_queue = 0; high_priority_queue  < priority_queue ; ++high_priority_queue){
		    //rho[high_priority_queue] = lambda_a_cap[high_priority_queue] * t_cap[high_priority_queue];
		    rho[high_priority_queue] = lambda_a_cap[high_priority_queue] * t[high_priority_queue];
         	    total_rho += rho[high_priority_queue];

		}
		temp = 1.0/service_time * total_rho;
        	lambda_a_cap[priority_queue] = min(lambda[priority_queue],(1.0-temp));
		queues[priority_queue]->setInjectionRate(lambda_a_cap[priority_queue]);
		double p_full = 1 - lambda_a_cap[priority_queue]/lambda[priority_queue];
		Ca_square_cap[priority_queue] = (1-p_full)*(1 - lambda_a_cap[priority_queue]);
		queues[priority_queue]->setCoeffInterArrivalTime(Ca_square_cap[priority_queue]);
		queues[priority_queue]->activeInjectionRateUpdateFlag();
		double X = 1.0 / Buffer_Size[priority_queue];
		n[priority_queue] = Ca_square_cap[priority_queue] / X + 1.0;
		waiting_time[priority_queue] = n[priority_queue] / lambda_a_cap[priority_queue] - service_time;
		waiting_time[priority_queue] = waiting_time[priority_queue] + zero_load_latency;
		queues[priority_queue]->setWaitingTime(waiting_time[priority_queue]);
 	}
    }
     update_node_from_Queue(queues);
  }
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
	if(argc<3){
		std::cerr<<"Error: Please provide both statistics and network files.\n";
		return 1;
	}
	std::string dot_file = argv[2];
	//std::string network_file = argv[3];
        run_custom_input(dot_file);
    } else if (mode == "regression_suite") {
        regression_suite();
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    return 0;
}
