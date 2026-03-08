#include <iostream>
#include <chrono>
#include <memory>
#include <dot_compiler.h>
#include "setNetwork.h"
#include "WaitingTime.h"
#include "Mapping.h"
#include "Injector.h"
#include "Primitive.h"
#include "Queue.h"
#include "UpdateNodeQueue.h"
#include <string>
#include <fstream>
#include <regex>
#include <cmath>


void compare_files(const std::string& file1, const std::string& file2, int caseNumber);
std::string trim(const std::string& str);
bool line_compare(const std::string& a, const std::string& b, double tol = 1e-6);


void regression_suite() {
  
 for (int i = 1; i <= 10; ++i) {
       
        // Construct file names for input and expected output
	 std::string inputFileName = "../test/graph" + std::to_string(i) + ".dot";
	 std::string expectedOutputFileName = "../test/goldenlog" + std::to_string(i) + ".txt";
	 std::string actualOutputFileName = "actual_output" + std::to_string(i) + ".txt";

        // Open the actual output file in write mode
        FILE* output_file = freopen(actualOutputFileName.c_str(), "w", stdout);
        if (!output_file) {
            std::cerr << "Error opening actual output file for case " << i << "." << std::endl;
            continue;
        }

        // Perform the main logic for each test case
	   //Phase 1: Parsing & set data structure
   	auto obj = new dot_lang::DOT(inputFileName);  
   
   	//phase 2:set injection_rate and coeff_inter_arrival_time
   	for(int iteration=0; iteration<10; iteration++){
   		dot_lang::Mapping& mapping=obj->getMapping();
   		for(auto iter=mapping.primitive_map.begin();iter!=mapping.primitive_map.end();++iter){
   			if(iter->second->isInjector()){
				std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(iter->second);
    				double injection_rate = injector->getInjectionRate();
				double coeff_inter_arrival_time = injector->getCoeffInterArrivalTime();
				injector->setInjectionRate(injection_rate);
				injector->setCoeffInterArrivalTime(coeff_inter_arrival_time);
				model::update_connected_node(iter->first,mapping, injection_rate);
	        	}
              } 
   	       //phase 3: invoke analytical model
        	model::Invoke_analytical_model(obj->getMapping());
       } 
    
       //phase 4: Aggregating waiting time
        model::waiting_time_calc(obj->getMapping());
    
      //Result Printing.
      dot_lang::Mapping& mapping=obj->getMapping();
      for(auto it=mapping.primitive_map.begin();it!=mapping.primitive_map.end();++it){
	      if(it->second->isInjector()){
		    std::shared_ptr<dot_lang::Injector> F = std::dynamic_pointer_cast<dot_lang::Injector>(it->second);
		    std::cout<<"Injector: "<<it->first<<'\t'<<"Waiting time: "<<F->getWaitingTime()<<std::endl;
               }
               if(it->second->isQueue()){
		    std::shared_ptr<dot_lang::Queue> Q = std::dynamic_pointer_cast<dot_lang::Queue>(it->second);
		    std::cout<<"Queue: "<<it->first<<'\t'<<"Waiting time: "<<Q->getWaitingTime()<<std::endl;
               }
      }
    delete obj;
    // Close the file stream and restore stdout
    fclose(stdout);
    if(!freopen("/dev/tty", "w", stdout)){
    	perror("freopen failed");
    } // Restore stdout to the console on Unix-like systems
     // Compare the outputs
     compare_files(actualOutputFileName, expectedOutputFileName, i);
    }
}

// Utility function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::string normalize_whitespace(const std::string& s) {
    return std::regex_replace(s, std::regex("\\s+"), " ");
}
bool line_compare(const std::string& sa, const std::string& sb, double tol){


	 std::string a = normalize_whitespace(sa);
         std::string b = normalize_whitespace(sb);
	if (a == b) return true;
	size_t posA=a.find_last_of(" ");
	size_t posB=b.find_last_of(" ");
	if(posA == std::string::npos || posB == std::string::npos){
		return a == b;
	}
	std::string prefixA = a.substr(0,posA);
	std::string prefixB = b.substr(0,posB);
	if(prefixA != prefixB) return false;

	double valA = std::stod(a.substr(posA + 1));
	double valB = std::stod(b.substr(posB + 1));

	return std::fabs(valA - valB) <= tol ;

}
//compares the file contents and returns true if same
void compare_files(const std::string& file1, const std::string& file2, int caseNumber) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);
std::string line1, line2;

    // Check if either file failed to open
    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Error opening one of the files in case " << caseNumber << "." << std::endl;
        return;
    }
    int line_number = 1;
    

    while (true) {
        bool got1 = static_cast<bool>(std::getline(f1, line1));
        bool got2 = static_cast<bool>(std::getline(f2, line2));

        // Skip blank lines in both files
        while (got1 && trim(line1).empty()) got1 = static_cast<bool>(std::getline(f1, line1));
        while (got2 && trim(line2).empty()) got2 = static_cast<bool>(std::getline(f2, line2));

        if (!got1 && !got2) break;  // both ended → success
        if (!got1 || !got2) {
            std::cout << "Case " << caseNumber << " failed at line " << line_number << "." << std::endl;
            if (!got1) std::cout << "Actual ended early, expected more lines." << std::endl;
            if (!got2) std::cout << "Expected ended early, actual has more lines." << std::endl;
            return;
        }

        // Trim and compare
        line1 = trim(line1);
        line2 = trim(line2);

        if (!line_compare(line1, line2)) {
            std::cout << "Case " << caseNumber << " failed at line " << line_number << "." << std::endl;
            std::cout << "Actual:   [" << line1 << "]" << std::endl;
            std::cout << "Expected: [" << line2 << "]" << std::endl;
            return;
        }

        line_number++;
    }
    std::cout << "Case " << caseNumber << " passed." << std::endl;

    f1.close();
    f2.close();
}

