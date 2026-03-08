#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"

namespace dot_lang {

//class sink if there is no destination primitive for a node
class Sink : public Primitive{
    public:
	    Sink();
	    virtual ~Sink()= default;
        bool isSink() const override;
        bool isServer() const override;
        bool isQueue() const override;
        bool isArbiter() const override;
        bool isInjector() const override;
        bool isSplit() const override;
        bool isMerge() const override;
        bool isPRarbiter() const override;
        bool isRRarbiter() const override;
	bool isHybridArbiter() const override;
        void activeFlag() override;
	std::vector<double> primitive() override;

	std::string getGraphVizProperties() override;

   protected:
    std::string _shape() override;


   private:
        bool isActive = false;

};
}

