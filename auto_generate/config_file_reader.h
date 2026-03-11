#pragma once
#include<iostream>
#include<sstream>
#include<map>
#include<string>
#include<fstream>

class ConfigFileReader{

	private:
		std::map<std::string, std::string> configData;
		static void trim(std::string &str){
		
			size_t start = str.find_first_not_of(" \t\n\r");
			size_t end = str.find_last_not_of(" \t\r\n");
			str = (start == std::string::npos)? "": str.substr(start,end-start+1);
		
		}

	public:
		bool load_file(const std::string &filename){
		
			std::ifstream fin(filename);
			if(!fin.is_open()){
			
				std::cerr<<"Error: unable to open config file: "<<filename<<std::endl;
				return false;
			}
			std::string line;
			int line_number = 0;
			while(std::getline(fin,line)){
			
				++line_number;
				trim(line);
				if(line.empty() || line[0] == '#') 
					continue;
				auto position = line.find('=');
				if(position == std::string::npos){
				
					std::cerr<<"Warning:Invalid line in config file("<<line_number<<") "<<line<<std::endl;
				}
				std::string key = line.substr(0,position);
				std::string value = line.substr(position+1);
				trim(key);
				trim(value);
				if(!key.empty() && !value.empty()){
				
					configData[key] = value;
				}
			}
			return true;
		}

		std::string getStringValue(const std::string &key, const std::string &defaultValue = "") const{
		
			if(!configData.count(key)) return defaultValue;
			std::string KeyValue = configData.at(key);
			return KeyValue;
		}
		
		double getDoubleValue(const std::string &key, double defaultValue=0.0) const{
		
			if(!configData.count(key)) return defaultValue;
			double keyValue = std::stod(configData.at(key));
			return keyValue;
		}
		int getRowColumn(const std::string &key, int defaultValue=0) const {
		
			if(!configData.count(key)) return defaultValue;
			int keyValue = std::stoi(configData.at(key));
			return keyValue;
		}

};
