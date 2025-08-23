#ifndef FIND_QUEUE_H
#define FIND_QUEUE_H

#include "Queue.h"
#include <memory>
#include <iostream>
#include "Mapping.h"

namespace model{

	void finding_queue(std::shared_ptr<dot_lang::Queue> queue, dot_lang::Mapping& mapping);
};
#endif
