#ifndef MESH_TOPOLOGY
#define MESH_TOPOLOGY
#include<fstream>
#include"SplitProbabilityGenerate.h"
#include<iomanip>
#include<vector>
void generateNextRouterPath(int source_row, int source_col, int dest_row, int dest_col, std::vector<std::vector<bool>> &visited, int totalRow, int totalCol, std::ofstream &fout, const std::vector<std::string> &directions, const std::string &InputPortDir);
int uniqueIndex(int row, int col, int size);
bool autoGenerateMesh(int row,int col, double zero_load, double t_serv, int buffer_size, double injection_rate, const std::string& arbitration, const std::string& routingAlgo, std::string& generatedfile){
 row=8;
 col=8;
	
	std::ofstream fout(generatedfile);
	if(!fout.is_open()){
	
		std::cerr<<"unable to open file: "<<generatedfile<<std::endl;
		return false;
	}
	
	fout<<"digraph G {\n";
	fout<<"   rankdir=\"LR\";\n\n";
       
	std::vector<std::string> directions = {"N", "S", "E", "W", "L"};
	int size = row;
	std::vector<std::vector<std::vector<double>>> ProbabilityMatrixPerRouter = Compute_Per_Router_Probability(size,routingAlgo);

	//define visited matrix to stop infine loop
	std::vector<std::vector<bool>> visited(row*col, std::vector<bool>(row*col, false));

	for(int rowIndex=0; rowIndex<row; ++rowIndex){
	
		for(int colIndex=0; colIndex<col; ++colIndex){
		
			std::string id = std::to_string(rowIndex) + std::to_string(colIndex);
			int uniqueRowColId = uniqueIndex(rowIndex, colIndex, size);

			//Source generator
			fout<<" PE_"<<id<<" [label=\"Source\", type=source, rate="<<injection_rate<<", shape=\"rarrow\"];"<<"\n";

			//arbiter declaration
			fout<<" R"<<id<<"_A_L"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
			fout<<" R"<<id<<"_A_N"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
			fout<<" R"<<id<<"_A_S"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
			fout<<" R"<<id<<"_A_E"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
			fout<<" R"<<id<<"_A_W"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";

			//server declaration
			fout<<" R"<<id<<"_SR_L"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" R"<<id<<"_SR_N"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" R"<<id<<"_SR_S"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" R"<<id<<"_SR_E"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" R"<<id<<"_SR_W"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";

			//server declaration
                        fout<<" Split"<<id<<"_SR_L"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
                        fout<<" Split"<<id<<"_SR_N"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
                        fout<<" Split"<<id<<"_SR_S"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
                        fout<<" Split"<<id<<"_SR_E"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
                        fout<<" Split"<<id<<"_SR_W"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";

			//input port buffer
			fout<<" R"<<id<<"_B_L"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			fout<<" R"<<id<<"_B_N"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			fout<<" R"<<id<<"_B_S"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			fout<<" R"<<id<<"_B_E"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			fout<<" R"<<id<<"_B_W"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";

			//Split buffer generate
			for(const auto&from : directions){
			
				for(const auto&to : directions){
				
					std::string directionToFrom = "SP_"+from + to +"_"+id;
					fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
				}
			}


			//Split generate
			for(int i=0; i<5; ++i){
			
				fout<<"Split_"<<directions[i]<<"_"<<id<<" [label=\"Split\", type=Split, shape=\"triangle\", out={";
				for(int j=0; j<5; ++j){
				
					double probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
					fout<<"SP_"<<directions[i]<<directions[j]<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
					if(j<4)
						fout<<", ";
				}
				fout<<"}];\n";
			}
			//sink buffer generate
			fout<<" Sink_B_"<<id<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			//sink server generate
			fout<<" Sink_SR_"<<id<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";

			//sink generate
			fout<<" Sink_"<<id<<" [label=\"sink\", type=sink];"<<"\n";

			

		}
	}

	//Edge generate
	for(int rowIndex=0; rowIndex<row; ++rowIndex){
	
		for(int colIndex=0; colIndex<col; ++colIndex){
		
			 std::string id = std::to_string(rowIndex) + std::to_string(colIndex);
			 //PE to Local Buffer
			 fout<<"PE_"<<id<<" -> R"<<id<<"_B_L"<<";\n";

			 //Local Buffer to Local Split server
			 fout<<"R"<<id<<"_B_L -> Split"<<id<<"_SR_L"<<";\n";
			 fout<<"Split"<<id<<"_SR_L -> Split_L_"<<id<<";\n";

			 //Split to all 5 queue
			 for(const auto&to : directions){
			 
				 fout<<"Split_L_"<<id<<" -> SP_L"<<to<<"_"<<id<<";\n";
			 }
			
			 //Queues to arbiter
			 for(const auto&to : directions){
			 
				 fout<<"SP_L"<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
			 }

			 //Arbiter to server
			 for(const auto&to : directions){
			 
				 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
			 }

			 //from Local server to Sink buffer
			 fout<<"R"<<id<<"_SR_L -> Sink_B_"<<id<<";\n";
			 fout<<"Sink_B_"<<id<<" -> Sink_SR_"<<id<<";\n";
			 fout<<"Sink_SR_"<<id<<" -> Sink_"<<id<<";\n";
			 int source_Index = uniqueIndex(rowIndex, colIndex, row);
			 int dest_Index = uniqueIndex(rowIndex, colIndex, col);
			 visited[source_Index][dest_Index] = true;

			 int source_row = rowIndex;
			 int source_col = colIndex;
			 int dest_row = 0;
			 int dest_col = 0;
			 //from server to N,S,E,W input buffer of next router
			 if(rowIndex > 0){
			 	
				 fout<<"R"<<id<<"_SR_N -> R"<<(rowIndex-1)<<colIndex<<"_B_S"<<";\n";
				 dest_row = rowIndex - 1;
				 dest_col = colIndex;
				 generateNextRouterPath(source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "S");
			 }
			 if(rowIndex < row-1){
			 
				 fout<<"R"<<id<<"_SR_S -> R"<<(rowIndex+1)<<colIndex<<"_B_N"<<";\n";
				 dest_row = rowIndex + 1;
				 dest_col = colIndex;
				 generateNextRouterPath(source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "N");
			 }
			 if(colIndex > 0){
			 
				 fout<<"R"<<id<<"_SR_W -> R"<<rowIndex<<(colIndex-1)<<"_B_E"<<";\n";
				 dest_row = rowIndex;
				 dest_col = colIndex - 1;
				 generateNextRouterPath(source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "E");
			 }
			 if(colIndex < col-1){
			 
				 fout<<"R"<<id<<"_SR_E -> R"<<rowIndex<<(colIndex+1)<<"_B_W"<<";\n";
				 dest_row = rowIndex;
				 dest_col = colIndex + 1;
				 generateNextRouterPath(source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "W");
			 }

		}
	}

	fout<<"}\n";
	fout.close();
	std::cout<<".dot file has been generared"<<std::endl;
	return true;
}

void generateNextRouterPath(int source_row, int source_col, int dest_row, int dest_col, std::vector<std::vector<bool>> &visited, int totalRow, int totalCol, std::ofstream &fout, const std::vector<std::string> &directions, const std::string &InputPortDir){


	std::string id = std::to_string(dest_row) + std::to_string(dest_col);

	int source_Index = uniqueIndex(source_row, source_col, totalRow);
	int dest_Index = uniqueIndex(dest_row, dest_col, totalRow);
	
	if(visited[source_Index][dest_Index]){
	
		return;
	}
	//Buffer to split server
	 fout<<"R"<<id<<"_B_"<<InputPortDir<<" -> Split"<<id<<"_SR_"<<InputPortDir<<";\n";
	fout<<"Split"<<id<<"_SR_"<<InputPortDir<<" -> Split_"<<InputPortDir<<"_"<<id<<";\n";

	//Split to all 5 queue
	for(const auto&to : directions){
	
		fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
	}

	//From each Queue to corresponding Arbiter
	for(const auto&to : directions){
	
		fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
	}

	//From Arbiter to server
	for(const auto&to : directions){
	
		fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
	}

	//From server to sink
	fout<<"R"<<id<<"_SR_L -> Sink_"<<id<<";\n";
	visited[source_Index][dest_Index]=true;

	//From server to N,E,W,S input buffer of next router
	if(dest_row > 0){
	       	fout<<"R"<<id<<"_SR_N -> R"<<(dest_row-1)<<dest_col<<"_B_S"<<";\n";
                generateNextRouterPath(dest_row, dest_col, dest_row-1, dest_col, visited, totalRow, totalCol, fout, directions, "S");
         }
        if(dest_row < totalRow-1){

                fout<<"R"<<id<<"_SR_S -> R"<<(dest_row +1)<<dest_col<<"_B_N"<<";\n";
                generateNextRouterPath(dest_row, dest_col, dest_row+1,dest_col, visited, totalRow, totalCol, fout, directions, "N");
         }
        if(dest_col > 0){
		 
	         fout<<"R"<<id<<"_SR_W -> R"<<dest_row<<(dest_col-1)<<"_B_E"<<";\n";
                 generateNextRouterPath(dest_row, dest_col, dest_row, dest_col-1, visited, totalRow, totalCol, fout, directions, "E");
        }
        if(dest_col < totalCol-1){

                fout<<"R"<<id<<"_SR_E -> R"<<dest_row<<(dest_col+1)<<"_B_W"<<";\n";
                generateNextRouterPath(dest_row, dest_col, dest_row, dest_col+1, visited, totalRow, totalCol, fout, directions, "W");
        }



}

//unique index generate
int uniqueIndex(int row, int col, int size){

	return row * size + col;
}
#endif

