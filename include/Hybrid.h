#pragma once
#include <vector>
#include "Arbiter.h"
#include "Queue.h"

namespace dot_lang {

//derived class implementing round robin
class HybridArbiter : public Arbiter{
    public:
       HybridArbiter(double zero_load_latency);
        virtual ~HybridArbiter() = default;


        bool isRRarbiter() const override;
	bool isHybridArbiter() const override;
        bool isServer() const override;
        bool isQueue() const override;
        bool isInjector() const override;
        bool isArbiter() const override;
        bool isMerge() const override;
        bool isSink() const override;
        bool isSplit() const override;
        bool isPRarbiter() const override;
        void activeFlag() override;

         void arbiter(Mapping& mapping) override;
         std::vector<double> primitive() override;

        double getZeroLoadLatency() override;
        double getServiceTime() override;
        double getCoeffServiceTime() override;

        void setZeroLoadLatency(double& new_zero_load_latency) override;
        void setServiceTime(double& new_service_time) override;
        void setCoeffServiceTime(double& new_coeff_service_time) override;

         std::string getGraphVizProperties() override;

   protected:
            std::string _shape() override;
           bool isActive = false;

};
}

