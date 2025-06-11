#pragma once

#include <vector>
#include <string>
#include <iostream> 
#include "Primitive.h"

namespace dot_lang {

class Queue : public Primitive {
public:
    Queue(int buffer_size, double waiting_time, double injection_rate, double coeff_interarrival_time);
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

    void activeFlag() override;

    // Get
    int getBufferSize() const;
    double getWaitingTime() const;
    double getInjectionRate() const;
    double getCoeffInterArrivalTime() const;
    double getServiceTime() const;

    // Set
    void setInjectionRate(double &new_injection_rate);
    void setCoeffInterArrivalTime(double &new_coeff_interarrival_time);
    void setWaitingTime(double &new_waiting_time);
    void setServiceTime(double &new_service_time);

    std::vector<double> primitive() override;

    // GraphViz override from Node → Primitive → Queue
    std::string getGraphVizProperties() override;

protected:
    std::string _shape() override;
    int buffer_size;
    double waiting_time;
    double injection_rate;
    double coeff_interarrival_time;
    double service_time;
    bool isActive = false;
};
}
