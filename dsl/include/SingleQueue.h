#ifndef SINGLE_QUEUE_H
#define SINGLE_QUEUE_H

#include"Queue.h"
#include<memory>
#include<iostream>


void finding_queue(std::shared_ptr<dot_lang::Queue> queue);
double single_queue_waiting_time(double injection_rate, double service_time);

#endif
