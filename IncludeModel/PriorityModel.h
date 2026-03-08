#ifndef PRIORITY_MODEL_H
#define PRIORITY_MODEL_H

#include<vector>
#include "Queue.h"
#include "Priority.h"
#include "Mapping.h"
#include <memory>
namespace model{

void priority_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double service_time, double zero_load_latency, dot_lang::Mapping& mapping);
}
#endif
