#ifndef UPDATE_NODE_QUEUE_H
#define UPDATE_NODE_QUEUE_H

#include<vector>
#include "Queue.h"
#include "Junction.h"
#include "Mapping.h"
#include <memory>

namespace model{

void update_node_from_Queue(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, dot_lang::Mapping& mapping);
void node_update_forward(std::vector<std::shared_ptr<dot_lang::Junc>>& nodes, dot_lang::Mapping& mapping);
void update_connected_node(std::string Injector, dot_lang::Mapping& mapping, double Injection_rate);
}

#endif
