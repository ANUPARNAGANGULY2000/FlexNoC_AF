#ifndef UPDATE_NODE_QUEUE_H
#define UPDATE_NODE_QUEUE_H

#include<vector>
#include<Queue.h>
#include<Junction.h>
#include<memory>

void update_node_from_Queue(std::vector<std::shared_ptr<Queue>>& queues);
void node_update_forward(std::vector<std::shared_ptr<Junc>>& nodes);


#endif
