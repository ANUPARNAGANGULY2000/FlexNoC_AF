#ifndef PRIORITY_MODEL_H
#define PRIORITY_MODEL_H

#include<vector>
#include "Queue.h"
#include "Priority.h"
#include "Mapping.h"
#include <memory>
using namespace dot_lang;

void priority_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, std::shared_ptr<dot_lang::PriorityArbiter> PRarbiter, Mapping& mapping);

#endif
