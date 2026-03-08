#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"
namespace dot_lang {

//class representing server
class Server : public Primitive{
        public:
                Server(double service_time,double coeff_service_time);
		virtual ~Server() = default;

		// Type identification
                bool isServer() const override;
                bool isQueue() const override;
                bool isInjector() const override;
                bool isArbiter() const override;
                bool isMerge() const override;
                bool isSplit() const override;
                bool isSink() const override;
                bool isRRarbiter() const override;
                bool isPRarbiter() const override;
		bool isHybridArbiter() const override;
                
		//active flag variable for server
                void activeFlag() override;


		//Get
                double getServiceTime() const;
                double getCoeffServiceTime() const;

		//Set
                void setServiceTime(double &new_service_time);
                void setCoeffServiceTime(double &new_coeff_service_time);


		std::vector<double> primitive() override;
    		std::string getGraphVizProperties() override;

                //active is_service_time_updated
                void activeServiceTimeFlag();
                bool isServiceTimeUpdated();


	 protected:
                std::string _shape() override;	
                double service_time;
                double coeff_service_time;
                bool isActive = false;
		bool is_service_time_updated = false;
};

}
