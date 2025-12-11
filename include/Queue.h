#pragma once

#include <vector>
#include <string>
#include <iostream> 
#include "Primitive.h"

namespace dot_lang {

class Queue : public Primitive {
public:
    Queue(int buffer_size, double waiting_time, double injection_rate, double coeff_interarrival_time, int priority = 0);
    virtual ~Queue() = default;

    // Type identification
    bool isQueue() const override;
    bool isServer() const override;
    bool isInjector() const override;
    bool isArbiter() const override;
    bool isSplit() const override;
    bool isSink() const override;
    bool isMerge() const override;
    bool isRRarbiter() const override;
    bool isPRarbiter() const override;
    bool isHybridArbiter() const override;
    
    void activeFlag() override;

    // Get
    int getBufferSize() const;
    double getWaitingTime() const;
    double getInjectionRate() const;
    double getCoeffInterArrivalTime() const;
    double getServiceTime() const;
    int getPriorityValue() const;

    // Set
    void setInjectionRate(double &new_injection_rate);
    void setCoeffInterArrivalTime(double &new_coeff_interarrival_time);
    void setWaitingTime(double &new_waiting_time);
    void setServiceTime(double &new_service_time);
    void setPriorityValue(int &new_priority);

    std::vector<double> primitive() override;


    void activeInjectionRateUpdateFlag();
    bool isInjectionRateUpdated();
    // GraphViz override from Node → Primitive → Queue
    std::string getGraphVizProperties() override;

protected:
    std::string _shape() override;
    int buffer_size;
    double waiting_time;
    double injection_rate;
    double coeff_interarrival_time;
    double service_time;
    int priority;
    bool isActive = false;
    bool is_injection_rate_updated_after_saturation = false;
};
}
