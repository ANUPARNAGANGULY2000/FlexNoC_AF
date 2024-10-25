#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

vector<double> roundrobin_model(vector<double> injection_rates, vector<double> interarrival_times, double service_time){return{0,0};}
vector<double> priority_model(vector<double> injection_rates, vector<double> interarrival_times, double service_time){return {0,0};}

//Forward declaration of node class
class Node;

//class representing a primitive
class Primitive{ 
    public:
       virtual ~Primitive()=default;
       virtual vector<double> primitive()=0;
       //virtual function for setting nodes
       virtual void setNodes(const vector<Node*> &nodes){}
};

//class representing node 
class Node{
    public:
        Node (Primitive* primitive_in , Primitive* primitive_out, double injection_rate, double coeff_interarrival_time):
            primitive_in(primitive_in),primitive_out(primitive_out),injection_rate(injection_rate),coeff_interarrival_time(coeff_interarrival_time){}

        //primitive_in --> source primitive
        Primitive* getPrimitiveIn() const {return primitive_in;}
        //primitive_out --> destination primitve
        Primitive* getPrimitiveOut() const {return primitive_out;}
        //node is also assigned some injection_rate and coeff_interarrival_time in the network flow
        double getInjectionRate() const{return injection_rate;}
        double getCoeffInterArrivalTime() const{return coeff_interarrival_time;}
                   
    protected:
        Primitive* primitive_in;
        Primitive* primitive_out; 
        double injection_rate;
        double coeff_interarrival_time;     
};

//class representing a queue  
class Queue : public Primitive{
    public:
        Queue(int buffer_size,double waiting_time):
           buffer_size(buffer_size),waiting_time(waiting_time){}
        //buffersize---> number of elements queue can contain
        int getBufferSize() const{return buffer_size;}
        double getWaitingTime() const {return waiting_time;}
        vector<double> primitive() override{
            return{};
        }

    protected:
        int buffer_size;
        double waiting_time;
};

//class representing an injector
class Injector: public Primitive{
    public:
        Injector(double injection_rate, double coeff_interarrival_time,double waiting_time):
           injection_rate(injection_rate), coeff_interarrival_time(coeff_interarrival_time),waiting_time(waiting_time) {}

        double getInjectionRate() const{return injection_rate;}
        //coeff_inter_arrival_time ---> Squared Coefficient of variation of interarrival time
        double getCoeffInterArrivalTime() const{return coeff_interarrival_time;}
        double getWaitingTime() const {return waiting_time;}
        void setWaitingTime(double &new_waiting_time){
            waiting_time=new_waiting_time;
        }

        vector<double> primitive() override{
            return{};
        }

    protected:
        double injection_rate;
        double coeff_interarrival_time;
        double waiting_time;
};

//class sink if there is no destination primitive for a node
class Sink : public Primitive{
    public:
        vector<double> primitive() override {
            // Return an empty vector for Sink primitive
            return {};
        }
};

//merge primitive 
class Merge : public Primitive{
    public:
        Merge(int node_count) : node_count(node_count){}

        vector<double> primitive() override{
            return{};
        }

        //to set the input nodes for already created merge
        void setNodes(const vector<Node*> &nodes){
            this->nodes=nodes;          
        }

    protected:
        vector<Node*> nodes;
        int node_count;
};

//split primitive
class Split : public Primitive{
    public:
        Split(int node_count,const vector<double> &probabilities):
            probabilities(probabilities),node_count(node_count){}

        vector<double> primitive() override{
            return{};
        }

        //to set nodes for already created split
        void setNodes(const vector<Node*> &nodes){
            this->nodes=nodes;   
        }

    protected:
        vector<Node*> nodes;
        vector<double> probabilities;
        int node_count;

};

//Base class arbiter 
class Arbiter : public Primitive {
    public:
        //more than one nodes get connected to arbiter
        Arbiter( double service_time , double coeff_service_time):
           service_time(service_time) , coeff_service_time(coeff_service_time){}
        
        virtual vector<double> arbiter()=0;

        //override the setnodes function for arbiter
        void setNodes(const vector<Node*> &nodes) override{
            this->nodes=nodes;
        }

    protected:
        vector<Node*> nodes; 
        double service_time;
        double coeff_service_time;
};

//derived class implementing round robin 
class RoundRobinArbiter : public Arbiter{
    public:
        
        RoundRobinArbiter(double service_time , double coeff_service_time):
          Arbiter( service_time , coeff_service_time){}

        vector<double> arbiter() override{
            vector<double> injection_rates;
            vector<double> coeff_interarrival_times;
 
        //extract injection rate and inter arrival times    
            for (const auto& node : nodes) {
                injection_rates.push_back(node->getInjectionRate());
                coeff_interarrival_times.push_back(node->getCoeffInterArrivalTime());
            }
            return roundrobin_model(injection_rates,coeff_interarrival_times,service_time);
        }
        vector<double> primitive() override{
            return{};
        }
};

//derived class implementing priority model
class PriorityArbiter :  public Arbiter{
    public:
        PriorityArbiter(double service_time , double coeff_service_time):
          Arbiter(service_time , coeff_service_time){}

        vector<double> arbiter() override{
            vector<double> injection_rates;
            vector<double> coeff_interarrival_times;

        //extract injection rate and inter arrival times from queues
        for (const auto& node : nodes) {
            injection_rates.push_back(node->getInjectionRate());
            coeff_interarrival_times.push_back(node->getCoeffInterArrivalTime());
        }
        return priority_model(injection_rates ,coeff_interarrival_times ,service_time);
        }   
        vector<double> primitive() override{
            return{};
        }
};   