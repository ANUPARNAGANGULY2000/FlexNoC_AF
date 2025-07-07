#ifndef UPDATE_NODE_QUEUE_H
#define UPDATE_NODE_QUEUE_H

#include<vector>
#include "Queue.h"
#include "Junction.h"
#include "Mapping.h"
#include <memory>

namespace dot_lang{

void update_node_from_Queue(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, Mapping& mapping);
void node_update_forward(std::vector<std::shared_ptr<dot_lang::Junc>>& nodes, Mapping& mapping);
}

#endif
