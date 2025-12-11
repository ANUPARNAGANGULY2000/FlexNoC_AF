#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"autoGenerateMeshFile.h"

class AutoDotFileGenerator{

	public:
		static void filegenerate(const std::string& topology, const std::string& arbitration, int row, int col, std::string routingAlgo, std::string& generatedfile, double injection_rate, int buffer_size, double service_time, double zero_load){
		
			if(topology == "mesh"){
			
				autoGenerateMesh(row, col, zero_load, service_time, buffer_size, injection_rate, arbitration, routingAlgo, generatedfile);
			}
			else if (topology == "torus"){
			
				//will be declared 
			}
			else if(topology == "ring"){
			
				//will be declared
			}
			else{
			
				std::cerr<<"Unsupported topology: "<<topology<<std::endl;
			}
		}
};
