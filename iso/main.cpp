#include <iostream>
#include <chrono>
#include <memory>
#include "test_suite.cpp"
#include <cassert>
#include "dot_file_generator.h"
#include "config_file_reader.h"
#include "RunRegular.cpp"
#include "RundotFile.cpp"



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage:\n";
	std::cerr <<" "<< argv[0]<<"regular <input.dot> - to explore regular topology\n";
	std::cerr <<" "<< argv[0]<<"irregular <input.txt> - to explore irregular topology\n"; 
        std::cerr << " "<<argv[0]<<"regression - Run regression suite logic\n";
        return 1;
    }

    std::string mode = argv[1];

    if(mode == "irregular"){
    	if(argc != 3){
		std::cerr<< "Error: Please provide .dot input file\n";
		return 1;
	}

    const char* file_path = argv[2];
    std::string file = file_path;
    DotFileProcess(file);
   
}
else if(mode == "regular"){

	if(mode == "regular"){
	
		if(argc != 3){
		
			std::cerr<<"Error: Please provide .txt input file\n";
		}
	const char* file_path = argv[2];
	std::string txtFile = file_path;
	ConfigFileReader reader;
	if(!reader.load_file(txtFile)) return 1;
	
	std::string topology = reader.getStringValue("topology","mesh");
	std::string routingAlgo = reader.getStringValue("routing","XY");
	int size = reader.getRowColumn("size",3);
	std::string arbitration = reader.getStringValue("arbiter","roundrobin");
	double injection_rate = reader.getDoubleValue("rate", 1.0);
	int buffer_size = reader.getRowColumn("buffer", 4);
	double service_time = reader.getDoubleValue("t_serv",1.0);
	double zero_load = reader.getDoubleValue("load", 0.0);

	std::string generatedDotFile = "auto_generated.dot";
	AutoDotFileGenerator fileGenerator;
	auto start = std::chrono::high_resolution_clock::now();
	fileGenerator.filegenerate(topology, arbitration, size, size, routingAlgo, generatedDotFile, injection_rate, buffer_size, service_time, zero_load);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout<<"Time taken to generate auto .dot file: "<<elapsed.count()<<" seconds\n";
//	DotFileProcess(generatedDotFile);
	RunRegular(generatedDotFile);
	}
}
else if( mode == "regression"){
	regression_suite();
}
else{
	std::cerr<< "Unknown mode: " <<mode<< "\n";
	return 1;
}

return 0;

}
