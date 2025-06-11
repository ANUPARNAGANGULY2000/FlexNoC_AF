#pragma once

#include "Node.h"
#include <map>
#include <vector>
#include <string>
#include "Primitive.h"
#include <memory>

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

	void addPrimitive(std::string name, std::shared_ptr<Primitive> primitive){
		primitives[name] = primitive;
	}

    private:
        std::map<int, std::shared_ptr<Node>> nodes;
        std::map<int, std::vector<int>> adjacencyList;

	std::map<std::string, std::shared_ptr<Primitive>> primitives;
    };
}
