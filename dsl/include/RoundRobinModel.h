#ifndef ROUND_ROBIN_MODEL_H
#define ROUND_ROBIN_MODEL_H

#include <vector>
#include <Queue.h>
#include <RoundRobin.h>
#include<memory>

void roundrobin_model(std::vector<std::shared_ptr<Queue>>& queues, std::shared_ptr<RoundRobinArbiter> RRarbiter);

#endif
