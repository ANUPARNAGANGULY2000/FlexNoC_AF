#ifndef UPDATE_PROCESS_H 
#define UPDATE_PROCESS_H
#include "Server.h"
#include "Queue.h"
#include "Junction.h"
#include "Mapping.h"
#include <iostream>
#include <memory>
#include <vector>

//using namespace dot_lang;
namespace dot_lang{

void server_to_arbiter_track(std::shared_ptr<dot_lang::Server> server, Mapping& mapping);
void update_arbiter_service_process(std::shared_ptr<dot_lang::Server> server_primitive, double t_cap, double Cs_square_cap, Mapping& mapping);
void update_injection_process(std::vector<double> lambda_a, std::vector<double> Ca_square, double t_cap, std::vector<int>BUFFER_SIZE, std::vector<std::shared_ptr<dot_lang::Queue>>& queues, std::vector<std::shared_ptr<dot_lang::Junc>>& nodes);
void update_injection_process_after_saturation(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double updated_injection_rate, Mapping& mapping);
std::shared_ptr<double[]> update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size, Mapping& mapping);
};

#endif
