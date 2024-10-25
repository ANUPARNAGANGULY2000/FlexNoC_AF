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
            cout<<"Created an Injector: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
        }
        //queue
        else if(field[0]=='Q'){
            primitive= new Queue(stod(firstValue),0.5);
            cout<<"Created a Queue: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
        }
        //round robin arbiter
        else if(field.substr(0,2)=="RR"){
            primitive= new RoundRobinArbiter(stod(firstValue),stod(secondValue));
            cout<<"Created a Roundrobin Arbiter: "<<field<<"\n";
            primitive_map[field]=primitive;
        }
        //priority arbiter 
        else if(field.substr(0,2)=="PR"){
            primitive= new PriorityArbiter(stod(firstValue),stod(secondValue));
            cout<<"Created a Priority Arbiter: "<<field<<"\n";
            primitive_map[field]=primitive;
        }
        //merge
        else if(field[0]=='M'){
            primitive= new Merge(stoi(firstValue));
            cout<<"Created a Merge: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
        }
        //split primitive
        else if(field[0]=='S'){
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
            cout<<"Created a Split: "<<field<<"\n";
            //map the field to the pointer created
            primitive_map[field]=primitive;
        }

    }  
    //close the input file
    infile.close();
}

//set notes for primitives(arbiter,merg,split)
void set_nodes_for_primitive(Primitive* primitive, const vector<string> &node_names){
      vector<Node*> nodes;
      for(const auto& node_name: node_names){
          auto it_node = node_data.find(node_name);
          if(it_node != node_data.end()){
             nodes.push_back(it_node->second);
          }
      }
      primitive->setNodes(nodes);
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
        if(source[0]=='Q'){
            Injector* injector = dynamic_cast<Injector*>(primitive_flow[primitive_in]);
            if(injector){
                Queue* queue=dynamic_cast<Queue*>(primitive_in);
                if(queue){
                    (queue_flow[injector]).push_back(queue);
                }
            }
        }
    }

    //injection_rate and coeff_interrarrival_times for node obtained from that of injector
    if(source[0]=='F'){ 
        Injector* injector = dynamic_cast<Injector*>(primitive_in);
        if(injector){
            injection_rate = injector->getInjectionRate();
            coeff_interarrival_time = injector->getCoeffInterArrivalTime();
        }
        //map the injector to the next primitive
        primitive_flow[primitive_out]=injector;
    }
    
    else if(source[0]!='F'){
        //also in each case update the next primitive
        primitive_flow[primitive_out]=primitive_flow[primitive_in];
        primitive_flow.erase(primitive_in);
    }
    
    //create the node
    Node* node = new Node(primitive_in, primitive_out, injection_rate, coeff_interarrival_time);

    //update the node_data here
    node_data[node_name]=node;

    //update the node_connections
    node_connections[source]=node_name;
    node_connections[node_name]=destination;
    
    if(destination.substr(0,2)=="RR" || destination.substr(0,2)=="PR" ||destination[0]=='M'){
        //for RR,PR,M extract nodes which have them as destination primitive
        for(auto it=node_connections.begin();it!=node_connections.end();it++){
            if(it->second==destination){
                node_names[destination].push_back(it->first);
            }
        }
    }

    //for split extract nodes which have them as source primitive
    if(source[0]=='S'){
        for(auto it=node_connections.begin();it!=node_connections.end();it++){
            if(it->first==source){
                node_names[source].push_back(it->second);
            }
        }
    }

    //connections made from source to destination with the help of this node
    cout<<"Connected: "<<source<<" -> "<<destination<<"\n";
}


//set the nodes after reading of network.text file is done 
void set_nodes(){
    for(auto it=node_names.begin();it!=node_names.end();it++){
        Primitive* primitive=primitive_map[it->first];
        //RoundRobinArbiter 
        if(it->first.substr(0,2)=="RR"){
            RoundRobinArbiter* rr_arbiter=dynamic_cast<RoundRobinArbiter*>(primitive);
            if(rr_arbiter){
                set_nodes_for_primitive(rr_arbiter,it->second);
            }
        }
        //PriorityArbiter
        else if(it->first.substr(0,2)=="PR"){
            PriorityArbiter* pr_arbiter=dynamic_cast<PriorityArbiter*>(primitive);
            if(pr_arbiter){
                set_nodes_for_primitive(pr_arbiter,it->second);
            }
        }
        //Merge
        else if(it->first[0]=='M'){
            Merge* merge=dynamic_cast<Merge*>(primitive);
            if(merge){
                set_nodes_for_primitive(merge,it->second);
            }
        }

        //Split
        if(it->first[0]=='S'){  
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

void read_network(const string &filename){     
    //open the second input file
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        read_network_line(line);
    }    
    set_nodes(); 
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
    }
}

void run_custom_input() {
    // Perform the main logic for a single custom input
    read_statistics("statistics1.txt");
    read_network("network1.txt");
    waiting_time_calc();
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <mode>\n";
        std::cerr << "Modes:\n";
        std::cerr << "  custom - Run custom input logic\n";
        std::cerr << "  compare - Run comparison logic\n";
        return 1;
    }

    std::string mode = argv[1];
    if (mode == "custom") {
        run_custom_input();
    } else if (mode == "regression_suite") {
        regression_suite();
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    return 0;
}