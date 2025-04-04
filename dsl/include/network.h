#pragma once

#include "Node.h"
#include <map>
#include <vector>

namespace dot_lang {
    class Network {
    public:
        void addNode(std::shared_ptr<Node> newNode) {
            nodes[newNode->getID()] = newNode;
        }

        void addEdge(int sourceId, int destinationId) {
            adjacencyList[sourceId].push_back(destinationId);
            adjacencyList[destinationId].push_back(sourceId);
        }

    private:
        std::map<int, std::shared_ptr<Node>> nodes;
        std::map<int, std::vector<int>> adjacencyList;
    };
}