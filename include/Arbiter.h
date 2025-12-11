#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"
#include "Junction.h"
#include "Mapping.h"

namespace dot_lang {

//Base class arbiter
class Arbiter : public Primitive {
    public:
       Arbiter(double zero_load_latency);
       virtual ~Arbiter() = default;

       // Type identification
        bool isArbiter() const override;
        bool isServer() const override;
        bool isQueue() const override;
        bool isInjector() const override;
        bool isMerge() const override;
        bool isSink() const override;
	bool isSplit() const override;
        bool isRRarbiter() const override;
        bool isPRarbiter() const override;
	bool isHybridArbiter() const override;
        void activeFlag() override;
        virtual void arbiter(Mapping& mapping) = 0;

        //get
        virtual double getServiceTime()=0;
	virtual double getCoeffServiceTime()=0;
        virtual double getZeroLoadLatency()=0;

	virtual void setServiceTime(double& new_service_time) = 0;
        virtual void setCoeffServiceTime(double& new_coeff_service_time) = 0;
        virtual void setZeroLoadLatency(double& new_zero_load_latency) = 0;
        //override the setnodes function for arbiter
        void setJunction(const std::vector<std::shared_ptr<dot_lang::Junc>> &junction) override;
	 std::string getGraphVizProperties() override;

   protected:
      std::string _shape() override;
    std::vector<std::shared_ptr<dot_lang::Junc>> junction;
        //vector<Queue*> queues;
        double service_time;
        double coeff_service_time;
        double zero_load_latency;
        bool isActive = false;
};
                      
}
