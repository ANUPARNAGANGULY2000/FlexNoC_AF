#pragma once

#include "DOTBaseVisitor.h"
#include "Node.h"
#include "network.h"

namespace dot_lang {
    class TypeCheckVisitor : public DOTBaseVisitor {
    private:
        Network* network;

    public:
        TypeCheckVisitor(Network* net) : network(net) {}
    };
}