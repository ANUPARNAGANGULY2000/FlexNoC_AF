#include <Server.h>
using namespace dot_lang;

dot_lang::Server:: Server(double service_time,double coeff_service_time):
                   service_time(service_time),coeff_service_time(coeff_service_time){}

                bool dot_lang::Server::isServer() const {return isActive;}
                bool dot_lang::Server::isQueue() const {return false;}
                bool dot_lang::Server::isInjector() const {return false;}
                bool dot_lang::Server::isArbiter() const {return false;}
                bool dot_lang::Server::isMerge() const  {return false;}
                bool dot_lang::Server::isSplit() const {return false;}
                bool dot_lang::Server::isSink() const {return false;}
                bool dot_lang::Server::isRRarbiter() const{return false;}
                bool dot_lang::Server::isPRarbiter() const{return false;}
                bool dot_lang::Server::isHybridArbiter() const{return false;}
	   	//active flag variable for server
                void dot_lang::Server::activeFlag() {isActive = true;}

                double dot_lang::Server::getServiceTime() const{return service_time;}
                double dot_lang::Server::getCoeffServiceTime() const{return coeff_service_time;}
                void dot_lang::Server::setServiceTime(double &new_service_time){
                        service_time = new_service_time;
                }
                void dot_lang::Server::setCoeffServiceTime(double &new_coeff_service_time){
                        coeff_service_time = new_coeff_service_time;
                }
               std::vector<double> dot_lang::Server::primitive(){
                        return{};
                }

                //active is_service_time_updated
                void dot_lang::Server::activeServiceTimeFlag() {
                        is_service_time_updated = true;
                }

                bool dot_lang::Server::isServiceTimeUpdated() { return is_service_time_updated; }

		std::string dot_lang::Server::getGraphVizProperties() {
     			std::string label = "label=\"ID: " + std::to_string(getID()) + " | t_serv: " + std::to_string(service_time) + "\"";
		        return label + ", " + _shape() + ", t_serv:" + std::to_string(service_time);
                 }

		std::string dot_lang::Server::_shape() {
   			 return "shape=\"box3d\"";
		}

