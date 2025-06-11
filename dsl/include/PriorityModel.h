#ifndef PRIORITY_MODEL_H
#define PRIORITY_MODEL_H

#include<vector>
#include<Queue.h>
#include<Priority.h>
#include<memory>

void priority_model(std::vector<std::shared_ptr<Queue>>& queues, std::shared_ptr<PriorityArbiter> PRarbiter);

#endif
