#pragma once
#include <string>
#include <iostream>
#include <Mapping.h>
#include <Junction.h>
#include <Queue.h>
#include<vector>

namespace dot_lang{
class MakeConnection{
  public:
	MakeConnection()=default;
        ~MakeConnection()=default;
static void create_connection(const std::string &node_name,const std::string &source, const std::string &destination, dot_lang::Mapping &mapping);
static std::vector<double> Merging_flow(std::vector<double>injection_rates,std::vector<double>coeff_inter_arrival_time);
static void back_tracking(std::shared_ptr<dot_lang::Junc> node, std::shared_ptr<dot_lang::Queue> queue, dot_lang::Mapping &mapping);
};
}
