#ifndef FIND_QUEUE_H
#define FIND_QUEUE_H

#include "Queue.h"
#include <memory>
#include <iostream>
#include "Mapping.h"

namespace dot_lang{

	void finding_queue(std::shared_ptr<dot_lang::Queue> queue, Mapping& mapping);
};
#endif
