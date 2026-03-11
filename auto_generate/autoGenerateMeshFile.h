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


















/*#ifndef MESH_TOPOLOGY
#define MESH_TOPOLOGY
#include<fstream>
#include"SplitProbabilityGenerate.cpp"
#include<iomanip>
#include<vector>
void generateNextRouterPath(int source_index, int source_row, int source_col, int dest_row, int dest_col, std::vector<std::vector<bool>> &visited, int totalRow, int totalCol, std::ofstream &fout, const std::vector<std::string> &directions, const std::string &InputPortDir, std::string routingAlgo);
int uniqueIndex(int row, int col, int size);
void splitBufferGeneratein(int rowIndex, int row, int colIndex, int col, std::string &direction, std::ofstream &fout, int buffer_size);
void splitGeneratein(int i, int j, std::ofstream &fout, int uniqueRowColId, std::string &from, int rowIndex, int row, int colIndex, int col, std::vector<std::vector<std::vector<double>>> ProbabilityMatrixPerRouter);
bool isOnValidRoute(int srcIndex, int currIndex, int destIndex, int size, std::string algo);
bool autoGenerateMesh(int row,int col, double zero_load, double t_serv, int buffer_size, double injection_rate, const std::string& arbitration, const std::string& routingAlgo, std::string& generatedfile){
	
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
			std::string direction = "L";
			//Source generator
			fout<<" PE_"<<id<<" [label=\"Source\", type=source, rate="<<injection_rate<<", shape=\"rarrow\"];"<<"\n";
			
			//local
			fout<<" R"<<id<<"_A_L"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
			fout<<" R"<<id<<"_SR_L"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" Split"<<id<<"_SR_L"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			fout<<" R"<<id<<"_B_L"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
			splitBufferGeneratein(rowIndex, row, colIndex, col, direction, fout, buffer_size);
			splitGeneratein(4, 4, fout, uniqueRowColId, direction, rowIndex, row, colIndex, col, ProbabilityMatrixPerRouter);

			//north side
			if((rowIndex - 1) >= 0){
				fout<<" R"<<id<<"_A_N"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
				fout<<" R"<<id<<"_SR_N"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				 fout<<" Split"<<id<<"_SR_N"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				 fout<<" R"<<id<<"_B_N"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
				 direction = "N";
				 splitBufferGeneratein(rowIndex, row, colIndex, col, direction, fout, buffer_size);
				 splitGeneratein(0, 4, fout, uniqueRowColId, direction, rowIndex, row, colIndex, col, ProbabilityMatrixPerRouter);
			}

			//south side
			if((rowIndex + 1) < row ){
				fout<<" R"<<id<<"_A_S"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
				fout<<" R"<<id<<"_SR_S"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				fout<<" Split"<<id<<"_SR_S"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
			 	fout<<" R"<<id<<"_B_S"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
				direction = "S";
				splitBufferGeneratein(rowIndex, row, colIndex, col, direction, fout, buffer_size);
				splitGeneratein(1, 4, fout, uniqueRowColId, direction, rowIndex, row, colIndex, col, ProbabilityMatrixPerRouter);
			}

			//west side
			if((colIndex - 1) >= 0){
				fout<<" R"<<id<<"_A_W"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
				fout<<" R"<<id<<"_SR_W"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				fout<<" Split"<<id<<"_SR_W"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				fout<<" R"<<id<<"_B_W"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
				direction = "W";
				splitBufferGeneratein(rowIndex, row, colIndex, col, direction, fout, buffer_size);
				splitGeneratein(3, 4, fout, uniqueRowColId, direction, rowIndex, row, colIndex, col, ProbabilityMatrixPerRouter);
			
			}

			//east side
			if((colIndex + 1) < col){
			
				fout<<" R"<<id<<"_A_E"<<" [label=\"arbiter\", type="<<arbitration<<", zero_load="<<zero_load<<", shape=\"trapezium\"];"<<"\n";
				fout<<" R"<<id<<"_SR_E"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				fout<<" Split"<<id<<"_SR_E"<<" [label=\"Server\", type=server, t_serv="<<t_serv<<", coeff_var=0.0, shape=\"circle\"];"<<"\n";
				fout<<" R"<<id<<"_B_E"<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
				direction = "E";
				splitBufferGeneratein(rowIndex, row, colIndex, col, direction, fout, buffer_size);
				splitGeneratein(2, 4, fout, uniqueRowColId, direction, rowIndex, row, colIndex, col, ProbabilityMatrixPerRouter);
			
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
			 fout<<"Split_L_"<<id<<" -> SP_LL"<<"_"<<id<<";\n";
                         fout<<"SP_LL"<<"_"<<id<<" -> R"<<id<<"_A_L"<<";\n";
                         fout<<"R"<<id<<"_A_L"<<" -> R"<<id<<"_SR_L"<<";\n";

			 //Split to all 5 queue
			 std::string to = "";
			 if((rowIndex - 1) >= 0){
				
				 //local to north
				 to = "N";
				 fout<<"Split_L_"<<id<<" -> SP_L"<<to<<"_"<<id<<";\n";
				 fout<<"SP_L"<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
				 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
			 }
			
			 if((rowIndex + 1) < row){

                                 //local to south
                                 to = "S";
                                 fout<<"Split_L_"<<id<<" -> SP_L"<<to<<"_"<<id<<";\n";
                                 fout<<"SP_L"<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
                                 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
                         }
			if((colIndex - 1) >= 0){

                                 //local to west
                                 to = "W";
                                 fout<<"Split_L_"<<id<<" -> SP_L"<<to<<"_"<<id<<";\n";
                                 fout<<"SP_L"<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
                                 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
                         }

                         if((colIndex + 1) < col){

                                 //local to east
                                 to = "E";
                                 fout<<"Split_L_"<<id<<" -> SP_L"<<to<<"_"<<id<<";\n";
                                 fout<<"SP_L"<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
                                 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
                         }

			 
			 //from Local server to Sink buffer
			 fout<<"R"<<id<<"_SR_L -> Sink_B_"<<id<<";\n";
			 fout<<"Sink_B_"<<id<<" -> Sink_SR_"<<id<<";\n";
			 fout<<"Sink_SR_"<<id<<" -> Sink_"<<id<<";\n";
			 int source_Index = uniqueIndex(rowIndex, colIndex, row);
			 int dest_Index = uniqueIndex(rowIndex, colIndex, col);
			 int start_index =  uniqueIndex(rowIndex, colIndex, row);
			 visited[start_index][dest_Index] = true;

			 int source_row = rowIndex;
			 int source_col = colIndex;
			 int dest_row = 0;
			 int dest_col = 0;
			 //from server to N,S,E,W input buffer of next router
			 if(rowIndex > 0 && ((rowIndex - 1) >= 0)){
			 	
				 fout<<"R"<<id<<"_SR_N -> R"<<(rowIndex-1)<<colIndex<<"_B_S"<<";\n";
				 dest_row = rowIndex - 1;
				 dest_col = colIndex;
				 generateNextRouterPath(start_index, source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "S", routingAlgo);
			 }
			 if(rowIndex < row-1 && ((rowIndex + 1) < row)){
			 
				 fout<<"R"<<id<<"_SR_S -> R"<<(rowIndex+1)<<colIndex<<"_B_N"<<";\n";
				 dest_row = rowIndex + 1;
				 dest_col = colIndex;
				 generateNextRouterPath(start_index, source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "N", routingAlgo);
			 }
			 if(colIndex > 0 && ((colIndex - 1) >= 0)){
			 
				 fout<<"R"<<id<<"_SR_W -> R"<<rowIndex<<(colIndex-1)<<"_B_E"<<";\n";
				 dest_row = rowIndex;
				 dest_col = colIndex - 1;
				 generateNextRouterPath(start_index, source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "E", routingAlgo);
			 }
			 if(colIndex < col-1 && ((colIndex + 1) < col)){
			 
				 fout<<"R"<<id<<"_SR_E -> R"<<rowIndex<<(colIndex+1)<<"_B_W"<<";\n";
				 dest_row = rowIndex;
				 dest_col = colIndex + 1;
				 generateNextRouterPath(start_index, source_row, source_col, dest_row, dest_col, visited, row, col, fout, directions, "W", routingAlgo);
			 }

		}
	}

	fout<<"}\n";
	fout.close();
	return true;
}

void generateNextRouterPath(int start_index, int source_row, int source_col, int dest_row, int dest_col, std::vector<std::vector<bool>> &visited, int totalRow, int totalCol, std::ofstream &fout, const std::vector<std::string> &directions, const std::string &InputPortDir, std::string routingAlgo){


	std::string id = std::to_string(dest_row) + std::to_string(dest_col);

	int source_Index = uniqueIndex(source_row, source_col, totalRow);
	int dest_Index = uniqueIndex(dest_row, dest_col, totalRow);
	if(visited[start_index][dest_Index]){
		return;
	}

	   //Buffer to split server
	   fout<<"R"<<id<<"_B_"<<InputPortDir<<" -> Split"<<id<<"_SR_"<<InputPortDir<<";\n";
	   fout<<"Split"<<id<<"_SR_"<<InputPortDir<<" -> Split_"<<InputPortDir<<"_"<<id<<";\n";
	   std::string to = "L";
	   fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
           fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
           fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
	   //From server to sink
           fout<<"R"<<id<<"_SR_L -> Sink_B_"<<id<<";\n";
           fout<<"Sink_B_"<<id<<" -> Sink_SR_"<<id<<";\n";
           fout<<"Sink_SR_"<<id<<" -> Sink_"<<id<<";\n";
	   visited[start_index][dest_Index]=true;

                         if((dest_row - 1) >= 0 && InputPortDir != "N"){

				 int unique_dest = uniqueIndex(dest_row - 1, dest_col, totalRow);
				 if(!visited[start_index][unique_dest]){
				     if(isOnValidRoute(start_index, dest_Index, unique_dest, totalRow, routingAlgo)){
                               		  //local to north
                                	 to = "N";
                                  	fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
                		  	fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
              			  	fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
					 fout<<"R"<<id<<"_SR_N -> R"<<(dest_row-1)<<dest_col<<"_B_S"<<";\n";
       				        generateNextRouterPath(start_index, dest_row, dest_col, dest_row-1, dest_col, visited, totalRow, totalCol, fout, directions, "S",routingAlgo);
				       }
				   }
                         }

                         if((dest_row + 1) < totalRow && InputPortDir != "S"){

				 int unique_dest = uniqueIndex(dest_row + 1, dest_col, totalRow);

                                 if(!visited[start_index][unique_dest]){
				     	 if(isOnValidRoute(start_index, dest_Index, unique_dest, totalRow, routingAlgo)){
	
        	                         //local to south
                	                 to = "S";
                        	         fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
              				 fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
               			 	fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
					fout<<"R"<<id<<"_SR_S -> R"<<(dest_row +1)<<dest_col<<"_B_N"<<";\n";
			                generateNextRouterPath(start_index, dest_row, dest_col, dest_row+1,dest_col, visited, totalRow, totalCol, fout, directions, "N",routingAlgo);

				     }
				 }     
                         }
                        if((dest_col - 1) >= 0 && InputPortDir != "W"){

				int unique_dest = uniqueIndex(dest_row, dest_col - 1, totalRow);

                                 if(!visited[start_index][unique_dest]){
                                     if(isOnValidRoute(start_index, dest_Index, unique_dest, totalRow, routingAlgo)){

                                 	//local to west
                                 	to = "W";
                                 	fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
                                 	fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
                               		 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
					 fout<<"R"<<id<<"_SR_W -> R"<<dest_row<<(dest_col-1)<<"_B_E"<<";\n";
			               generateNextRouterPath(start_index, dest_row, dest_col, dest_row, dest_col-1, visited, totalRow, totalCol, fout, directions, "E", routingAlgo);

				  }
				}
                         }

                         if((dest_col + 1) < totalCol && InputPortDir != "E"){
				

				 int unique_dest = uniqueIndex(dest_row, dest_col + 1, totalRow);

                                 if(!visited[start_index][unique_dest]){
                                     if(isOnValidRoute(start_index, dest_Index, unique_dest, totalRow, routingAlgo)){

                                 //local to east
                                 to = "E";
                                 fout<<"Split_"<<InputPortDir<<"_"<<id<<" -> SP_"<<InputPortDir<<to<<"_"<<id<<";\n";
                		 fout<<"SP_"<<InputPortDir<<to<<"_"<<id<<" -> R"<<id<<"_A_"<<to<<";\n";
                 		 fout<<"R"<<id<<"_A_"<<to<<" -> R"<<id<<"_SR_"<<to<<";\n";
				 fout<<"R"<<id<<"_SR_E -> R"<<dest_row<<(dest_col+1)<<"_B_W"<<";\n";
	                        generateNextRouterPath(start_index, dest_row, dest_col, dest_row, dest_col+1, visited, totalRow, totalCol, fout, directions, "W", routingAlgo);

                         }
			}
		     }

}

bool isOnValidRoute(int srcIndex, int currIndex, int destIndex, int size, std::string algo) {
    int sourceRow = srcIndex / size;
    int sourceCol = srcIndex % size;

    int currentRow = currIndex / size;
    int currentCol = currIndex % size;

    int destRow = destIndex / size;
    int destCol = destIndex % size;

    // Destination reached
    if (currentRow == destRow && currentCol == destCol)
        return true;

    if (algo == "XY") {

        // X phase: wheher source and dest in different col?
        if (sourceCol != destCol) {

            // must stay on source row
            if (currentRow != sourceRow) return false;

            // must move toward destination col
            if ((destCol > sourceCol && (currentCol < sourceCol || currentCol > destCol)) ||
                (destCol < sourceCol && (currentCol > sourceCol || currentCol < destCol)))
                return false;

            return true;
        }

        // Y phase: source and destination in same col but different row
        else {
            if (currentCol != destCol) return false;

            if ((destRow > sourceRow && (currentRow < sourceRow || currentRow > destRow)) ||
                (destRow < sourceRow && (currentRow > sourceRow || currentRow < destRow)))
                return false;

            return true;
        }
    }

    // YX ROUTING 
    else {

        // Y phase: moving in rows
        if (sourceRow != destRow) {
            // must stay on source column
            if (currentCol != sourceCol) return false;

            if ((destRow > sourceRow && (currentRow < sourceRow || currentRow > destRow)) ||
                (destRow < sourceRow && (currentRow > sourceRow || currentRow < destRow)))
                return false;

            return true;
        }

        // X phase: rows matched
        else {
            if (currentRow != destRow) return false;

            if ((destCol > sourceCol && (currentCol < sourceCol || currentCol > destCol)) ||
                (destCol < sourceCol && (currentCol > sourceCol || currentCol < destCol)))
                return false;

            return true;
        }
    }
}

//unique index generate
int uniqueIndex(int row, int col, int size){

	return row * size + col;
}

void splitBufferGeneratein(int rowIndex, int row, int colIndex, int col, std::string &direction, std::ofstream &fout, int buffer_size){

	//local side
	std::string id = std::to_string(rowIndex) + std::to_string(colIndex);
	std::string to = "L";
	std::string directionToFrom = "SP_"+direction + to +"_"+id;
        fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";


	//North Side
	if((rowIndex - 1) >= 0){
		to = 'N';
		if(direction != to){
        	std::string directionToFrom = "SP_"+direction + to +"_"+id;
        	fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
		}
	}

	//South Side
	if((rowIndex + 1) < row){
	
		 to = 'S';
		 if(direction != to){
       		 std::string directionToFrom = "SP_"+direction + to +"_"+id;
        	 fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
		 }
	}

	//west side
	if((colIndex - 1) >= 0){
	
		 to = 'W';
		 if(direction != to){
        	 std::string directionToFrom = "SP_"+direction + to +"_"+id;
        	 fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
		 }
	}

	//east side
	if((colIndex + 1) < col){
	
		 to = 'E';
		 if(direction != to){
        	 std::string directionToFrom = "SP_"+direction + to +"_"+id;
       		 fout<<directionToFrom<<" [label=\"Queue\", type=Queue, depth="<<buffer_size<<", shape=\"cylinder\"];"<<"\n";
		 }
	}

}

void splitGeneratein(int i, int j, std::ofstream &fout, int uniqueRowColId, std::string &from, int rowIndex, int row, int colIndex, int col, std::vector<std::vector<std::vector<double>>> ProbabilityMatrixPerRouter){

       std::string id = std::to_string(rowIndex) + std::to_string(colIndex);
       fout<<"Split_"<<from<<"_"<<id<<" [label=\"Split\", type=Split, shape=\"triangle\", out={";                          
	std::string to = "L";
	//local
	double probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
        fout<<"SP_"<<from<<to<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
	

	//North
	if((rowIndex - 1) >= 0){
	
		j=0;
		if(i != j){
		to = "N";
		probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
		fout<<", ";
                fout<<"SP_"<<from<<to<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
		}
	}

	//South
	if((rowIndex + 1) < row){
	
		j=1;
		if(i != j){
		to = "S";
		probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
		fout<<", ";
                fout<<"SP_"<<from<<to<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
		}
	}

	//East
	if((colIndex + 1) < col){
	
		j=2;
		if(i != j){
		to = "E";
		probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
		fout<<", ";
                fout<<"SP_"<<from<<to<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
		}
	}

	//West
	if((colIndex - 1) >= 0){
	
		j=3;
		if(i != j){
		to = "W";
		probabilityValue = ProbabilityMatrixPerRouter[uniqueRowColId][i][j];
		fout<<", ";
                fout<<"SP_"<<from<<to<<"_"<<id<<":"<<std::fixed<<std::setprecision(2)<<probabilityValue;
		}
	}
fout<<"}];\n";	
}
#endif
*/
