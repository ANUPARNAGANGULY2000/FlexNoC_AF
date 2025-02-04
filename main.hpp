
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
#include <math.h>
using namespace std;

vector<double> roundrobin_model(vector<double> injection_rates, vector<double> interarrival_times, double service_time, vector<int> buffer_sizes);
vector<double> priority_model(const vector<double>& lambda_a, const vector<double>& Ca_square, double service_time,vector<int>& BUFFER_SIZE);
//vector<double> priority_model(vector<double> injection_rates, vector<double> interarrival_times, double service_time){return {0,0};}

//Forward declaration of node class
class Node;

//class representing a primitive
class Primitive{
    public:
       virtual bool isServer() const = 0;
       virtual bool isQueue() const = 0;
       virtual bool isInjector() const = 0;
       virtual bool isArbiter() const = 0;
       virtual bool isMerge() const = 0;
       virtual bool isSplit() const = 0;
       virtual bool isSink() const = 0;
       virtual bool isRRarbiter() const = 0;
       virtual bool isPRarbiter() const = 0;

       //to activate flag variable
       virtual void activeFlag() = 0;
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
	void setInjectionRate(double &new_injection_rate){
		injection_rate = new_injection_rate;
	}
	void setCoeffInterArrivalTime(double &new_coeff_interarrival_time){
		coeff_interarrival_time = new_coeff_interarrival_time;
	}

    protected:
        Primitive* primitive_in;
        Primitive* primitive_out;
        double injection_rate;
        double coeff_interarrival_time;
};
//class representing server
class Server : public Primitive{
	public:
		Server(double service_time,double coeff_service_time):
		   service_time(service_time),coeff_service_time(coeff_service_time){}
		
		bool isServer() const override {return isActive;}
		bool isQueue() const override {return false;}
		bool isInjector() const override {return false;}
		bool isArbiter() const override{return false;}
		bool isMerge() const override {return false;}
		bool isSplit() const override{return false;}
		bool isSink() const override{return false;}
		bool isRRarbiter() const override{return false;}
		bool isPRarbiter() const override{return false;}
		//active flag variable for server
		void activeFlag() override {isActive = true;}

		double getServiceTime() const{return service_time;}
		double getCoeffServiceTime() const{return coeff_service_time;}
		void setServiceTime(double &new_service_time){
			service_time = new_service_time;
		}
		void setCoeffServiceTime(double &new_coeff_service_time){
			coeff_service_time = new_coeff_service_time;
		}
		vector<double> primitive() override{
			return{};
		}
	protected:
		double service_time;
		double coeff_service_time;
		bool isActive = false;
};


//class representing a queue
class Queue : public Primitive{
    public:
        Queue(int buffer_size,double waiting_time,double injection_rate,double coeff_interarrival_time):
           buffer_size(buffer_size),waiting_time(waiting_time),injection_rate(injection_rate),coeff_interarrival_time(coeff_interarrival_time){}

	bool isQueue() const override {return isActive;}
	bool isServer() const override{return false;}
	bool isInjector() const override{return false;}
	bool isArbiter() const override{return false;}
	bool isSplit() const override{return false;}
	bool isSink() const override{return false;}
	bool isMerge() const override {return false;}
	bool isRRarbiter() const override{return false;}
	bool isPRarbiter() const override{return false;}
	//active flag variable for Queue
	void activeFlag() override {isActive = true;}

        //buffersize---> number of elements queue can contain
        int getBufferSize() const{return buffer_size;}
        double getWaitingTime() const {return waiting_time;}
	double getInjectionRate() const{return injection_rate;}
	double getCoeffInterArrivalTime() const{return coeff_interarrival_time;}
	void setInjectionRate(double &new_injection_rate){
		injection_rate=new_injection_rate;
	}
	void setCoeffInterArrivalTime(double &new_coeff_interarrival_time){
		coeff_interarrival_time = new_coeff_interarrival_time;
	}
	void setWaitingTime(double &new_waiting_time){
		waiting_time=new_waiting_time;
	}
        vector<double> primitive() override{
            return{};
        }
        
    protected:
        int buffer_size;
        double waiting_time;
	double injection_rate;
	double coeff_interarrival_time;
	bool isActive =  false;
};

//class representing an injector
class Injector: public Primitive{
    public:
        Injector(double injection_rate, double coeff_interarrival_time,double waiting_time):
           injection_rate(injection_rate), coeff_interarrival_time(coeff_interarrival_time),waiting_time(waiting_time) {}

	bool isInjector() const override{return isActive;}
	bool isQueue() const override{return false;}
	bool isServer() const override{return false;}
	bool isArbiter() const override{return false;}
	bool isMerge() const override{return false;}
	bool isSplit() const override{return false;}
	bool isSink() const override{return false;}
	bool isRRarbiter() const override{return false;}
	bool isPRarbiter() const override{return false;}
	//active flag variable for Injector
	void activeFlag() override{isActive=true;}

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
	bool isActive = false;
};

//class sink if there is no destination primitive for a node
class Sink : public Primitive{
    public:
	bool isSink() const override {return isActive;}
	bool isServer() const override{return false;}
	bool isQueue() const override{return false;}
	bool isArbiter() const override{return false;}
	bool isInjector() const override{return false;}
	bool isSplit() const override{return false;}
	bool isMerge() const override{return false;}
	bool isPRarbiter() const override{return false;}
	bool isRRarbiter() const override{return false;}
	//active flag variable for Sink
	void activeFlag() override {isActive = true;}
        vector<double> primitive() override {
            // Return an empty vector for Sink primitive
            return {};
        }

   protected:
	bool isActive = false;
};

//merge primitive
class Merge : public Primitive{
    public:
        Merge(int node_count) : node_count(node_count){}
	bool isMerge() const override{return isActive;}
	bool isServer() const override{return false;}
	bool isInjector() const override{return false;}
	bool isQueue() const override{return false;}
	bool isArbiter() const override{return false;}
	bool isSink() const override{return false;}
	bool isSplit() const override{return false;}
	bool isPRarbiter() const override{return false;}
	bool isRRarbiter() const override{return false;}
	// active flag variable for Merge
	void activeFlag() override{isActive=true;}

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
	bool isActive = false;
};
 //split primitive
class Split : public Primitive{
    public:
        Split(int node_count,const vector<double> &probabilities):
            probabilities(probabilities),node_count(node_count){}
	
	bool isSplit() const override{return isActive;}
	bool isServer() const override{return false;}
	bool isQueue() const override{return false;}
	bool isInjector() const override{return false;}
	bool isArbiter() const override{return false;}
	bool isMerge() const override{return false;}
	bool isSink() const override{return false;}
	bool isRRarbiter() const override{return false;}
	bool isPRarbiter() const override{return false;}

	//active flag variable for Split
	void activeFlag() override{isActive=true;}

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
	bool isActive = false;

};

//Base class arbiter
class Arbiter : public Primitive {
    public:
        //more than one nodes get connected to arbiter
        Arbiter( double service_time , double coeff_service_time):
           service_time(service_time) , coeff_service_time(coeff_service_time){}

	bool isArbiter() const override{return isActive;}
	bool isSplit() const override{return false;}
        bool isServer() const override{return false;}
        bool isQueue() const override{return false;}
        bool isInjector() const override{return false;}
        bool isMerge() const override{return false;}
        bool isSink() const override{return false;}
        bool isRRarbiter() const override{return false;}
        bool isPRarbiter() const override{return false;}

	//active flaf variable for Arbiter
	void activeFlag() override{isActive = true;}
        virtual vector<double> arbiter()=0;
	virtual void setServiceTime(double& new_service_time) = 0;
	virtual void setCoeffServiceTime(double& new_coeff_service_time) = 0;

        //override the setnodes function for arbiter
        void setNodes(const vector<Node*> &nodes) override{
            this->nodes=nodes;
        }

    protected:
        vector<Node*> nodes;
        double service_time;
        double coeff_service_time;
	bool isActive = false;
};

//derived class implementing round robin
class RoundRobinArbiter : public Arbiter{
    public:
	   RoundRobinArbiter(double service_time , double coeff_service_time):
          Arbiter( service_time , coeff_service_time){}

        bool isRRarbiter() const override{return isActive;}
	bool isSplit() const override{return false;}
        bool isServer() const override{return false;}
        bool isQueue() const override{return false;}
        bool isInjector() const override{return false;}
        bool isArbiter() const override{return false;}
        bool isMerge() const override{return false;}
        bool isSink() const override{return false;}
        bool isPRarbiter() const override{return false;}

       //active flag for RoundRobinArbiter 
       	void activeFlag() override{isActive = true;}

	

        vector<double> arbiter() override{
            vector<double> injection_rates;
            vector<double> coeff_interarrival_times;
            vector<int> buffer_sizes;
      
        //extract injection rate and inter arrival times
       for (const auto& node : nodes) {
                injection_rates.push_back(node->getInjectionRate());
                coeff_interarrival_times.push_back(node->getCoeffInterArrivalTime());

            // Attempt to cast the input primitive to a Queue
            Queue* queue_in = dynamic_cast<Queue*>(node->getPrimitiveIn());
            if (queue_in) {
                     buffer_sizes.push_back(queue_in->getBufferSize());
            }
         
       }
     
        return roundrobin_model(injection_rates,coeff_interarrival_times,service_time,buffer_sizes);
        }
        vector<double> primitive() override{
            return{};
        }
	void setServiceTime(double& new_service_time) override{
		service_time = new_service_time;
	}
	void setCoeffServiceTime(double& new_coeff_service_time) override{
		coeff_service_time = new_coeff_service_time;
	}
    protected:
	bool isActive = false;
};

//derived class implementing priority model
class PriorityArbiter :  public Arbiter{
    public:
        PriorityArbiter(double service_time , double coeff_service_time):
          Arbiter(service_time , coeff_service_time){}

        bool isPRarbiter() const override{return isActive;}
	bool isSplit() const override{return false;}
        bool isServer() const override{return false;}
        bool isQueue() const override{return false;}
        bool isInjector() const override{return false;}
        bool isArbiter() const override{return false;}
        bool isMerge() const override{return false;}
        bool isSink() const override{return false;}
        bool isRRarbiter() const override{return false;}

       //active flag for RoundRobinArbiter
        void activeFlag() override{isActive = true;}
        vector<double> arbiter() override{
            vector<double> injection_rates;
            vector<double> coeff_interarrival_times;
            vector<int> buffer_sizes;

        //extract injection rate and inter arrival times from queues
        for (const auto& node : nodes) {
            injection_rates.push_back(node->getInjectionRate());
            coeff_interarrival_times.push_back(node->getCoeffInterArrivalTime());

            // Attempt to cast the input primitive to a Queue
            Queue* queue_in = dynamic_cast<Queue*>(node->getPrimitiveIn());
            if (queue_in) {
                     buffer_sizes.push_back(queue_in->getBufferSize());
            }
        }
        return priority_model(injection_rates ,coeff_interarrival_times ,service_time,buffer_sizes);
        }
        vector<double> primitive() override{
            return{};
        }
	void setServiceTime(double& new_service_time) override{
		service_time = new_service_time;
	}
	void setCoeffServiceTime(double& new_coeff_service_time) override{
		coeff_service_time = new_coeff_service_time;
	}

   protected:
	bool isActive=false;
};

                                                                                                                     
