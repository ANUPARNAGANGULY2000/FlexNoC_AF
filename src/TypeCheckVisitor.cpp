#include<TypeCheckVisitor.h>

namespace dot_lang{

     void TypeCheckVisitor::isValidConnection(std::string source, std::string destination){
	
		if(source == "SOURCE"){
			if(destination != "QUEUE") {
			    std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but is expected to connected with Queue "<<std::endl;
        	            assert(false);
			}
	        }
		else if(source == "QUEUE" ){
			if(destination != "ARBITER" && destination !="ROUNDROBIN" && destination!= "PRIORITY" && destination!= "HYBRID" && destination != "SERVER"){
		   	    std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with arbiter or server "<<std::endl;
                           assert(false);
		        }
		}
		else if(source == "SERVER"){
			if(destination != "SINK" && destination != "QUEUE" && destination != "MERGE" && destination != "SPLIT"){
		   	   std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with either sink, Queue or Merge "<<std::endl;
                  	    assert(false);
    	                }
		}
		if(source == "SPLIT"){
                        if(destination != "QUEUE") {
                            std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but is expected to connected with Queue "<<std::endl;
                            assert(false);
                        }
                }
		else if(source == "ARBITER"){ 
			if(destination != "SERVER"){
         	   	    std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with server "<<std::endl;
                            assert(false);
		  }
		}
		 else if(source == "ROUNDROBIN"){
                        if(destination != "SERVER"){
                            std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with server "<<std::endl;
                            assert(false);
                  }
                }
		else if(source == "HYBRID"){
		
			if(destination != "SERVER"){
			
				std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with server "<<std::endl;
				assert(false);
			}
		}
		 else if(source == "PRIORITY"){
                        if(destination != "SERVER"){
                            std::cerr<<"Error: "<<source<<" is connected to "<<destination<<" but it is expected to connected with server "<<std::endl;
                            assert(false);
                  }
                }

	}
}
