#pragma once

#include "DOTBaseVisitor.h"
#include "Node.h"
#include "network.h"

namespace dot_lang {
    class EdgeVisitor : public DOTBaseVisitor {
    private:
        Network* network;

    public:
        EdgeVisitor(Network* net) : network(net) {}
    };
}