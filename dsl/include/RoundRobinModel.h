#ifndef ROUND_ROBIN_MODEL_H
#define ROUND_ROBIN_MODEL_H

#include <vector>
#include "Queue.h"
#include "RoundRobin.h"
#include "Mapping.h"
#include<memory>

using namespace dot_lang;
void roundrobin_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, std::shared_ptr<dot_lang::RoundRobinArbiter> RRarbiter, Mapping& mapping);

#endif
