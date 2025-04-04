#pragma once

#include <Node.h>

namespace dot_lang {

class Injector : public Node {
    public:
        Injector();
        virtual ~Injector() = default;
        double getRate() {return _rate; };
        std::string getGraphVizProperties() override;
    
    protected:
        std::string _shape() override;

    private:
        double _rate;
};

class Queue : public Node {
    public:
        Queue();
        virtual ~Queue() = default;
        int getSize() { return _size; };
        std::string getGraphVizProperties() override;

    protected:
        std::string _shape() override;

    private:
        int _size;
};

}