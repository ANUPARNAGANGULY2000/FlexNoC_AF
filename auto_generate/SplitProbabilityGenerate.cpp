#include<iostream>
#include<vector>
#include"SplitProbabilityGenerate.h"
#include<cmath>
#include<iomanip>
#include<string>


using namespace std;

enum port { N=0, S=1, E=2, W=3, L=4 };
const int NUM_PORTS = 5;

int getOutputPort(int currRow, int currCol, int nextRow, int nextCol){

	if(nextRow == currRow-1 && nextCol == currCol) return N;
	if(nextRow == currRow+1 && nextCol == currCol) return S;
	if(nextRow == currRow && nextCol == currCol-1) return W;
	if(nextRow == currRow && nextCol == currCol+1) return E;
	return L;
}

int getInputPort(int currRow, int currCol, int prevRow, int prevCol){

	if(prevRow == currRow-1 && prevCol == currCol) return S;
	if(prevRow == currRow+1 && prevCol == currCol) return N;
	if(prevRow == currRow && prevCol == currCol-1) return E;
	if(prevRow == currRow && prevCol == currCol+1) return W;
	return L;
}

int getUniqueId(int rowIndex, int colIndex, int size){

	return rowIndex * size + colIndex;
}

void RouteFinding(int srcRow, int srcCol, int destRow, int destCol, int N, const std::string& routingAlgo, std::vector<std::vector<std::vector<int>>> & splitCount){

	int currRow = srcRow, currCol = srcCol;
	int prevPort = L; //initially all packet coming from local port

	while(!(currRow == destRow && currCol == destCol)){
	
		int nextRow = currRow, nextCol = currCol;
		if(routingAlgo == "XY"){
		
			if(currCol != destCol) nextCol += (destCol > currCol ? 1 : -1); // first going to X direction
			else nextRow += (destRow > currRow ? 1 : -1); // then going to Y direction
		}else if(routingAlgo == "YX"){
		
			if(currRow != destRow) nextRow += (destRow > currRow ? 1 : -1); //first going to Y direction
			else nextCol += (destCol > currCol ? 1 : -1); // then going to X direction
		}

		int outputPort = getOutputPort(currRow, currCol, nextRow, nextCol); // getting the output port of the current router
		int inputPort = getInputPort(nextRow, nextCol, currRow, currCol); // getting the input port of the next router
		int CurrRowColId = getUniqueId(currRow, currCol, N);
		int NextRowColId = getUniqueId(nextRow, nextCol, N);

		splitCount[CurrRowColId][prevPort][outputPort]++; // for each router packet coming from which port and going to which port
		currRow = nextRow;
		currCol = nextCol;
		prevPort = inputPort; //for next router's input port
		

	}
	int destRowColId = getUniqueId(currRow, currCol, N);// as packet has arrived in the destination
	splitCount[destRowColId][prevPort][L]++; //after arriving it will go the sink through local port
}

std::vector<std::vector<std::vector<double>>> CountingProbability(const std::vector<std::vector<std::vector<int>>>& SplitCount){

	int count = SplitCount.size();
	std::vector<std::vector<std::vector<double>>> probability(count, std::vector<std::vector<double>>(NUM_PORTS, std::vector<double>(NUM_PORTS,0.0)));
	for(int i=0; i<count; ++i){
	
		for(int j=0; j<NUM_PORTS; ++j){
		
			int total = 0;
			for(int k=0; k<NUM_PORTS; ++k) total += SplitCount[i][j][k];
			if(total > 0){
			
				for(int k=0; k<NUM_PORTS; ++k)
					probability[i][j][k] = (double)SplitCount[i][j][k] / total;
			}
		}

	}
	return probability;

}

std::vector<std::vector<std::vector<double>>> Compute_Per_Router_Probability(int size, const std::string& routingAlgo){

	int totalRouters = size * size;
	std::vector<std::vector<std::vector<int>>> SplitCount(totalRouters,std::vector<std::vector<int>>(NUM_PORTS, std::vector<int>(NUM_PORTS,0)));
	
			for(int sourceRow=0; sourceRow < size; ++sourceRow){
			   for(int sourceCol=0; sourceCol < size; ++sourceCol){
			      for(int destRow=0; destRow < size; ++destRow){
			         for(int destCol=0; destCol < size; ++destCol){
				    if(sourceRow == destRow && sourceCol == destCol) continue;
				       RouteFinding(sourceRow,sourceCol, destRow, destCol, size, routingAlgo, SplitCount);
				 }
			      }
			   }
 			}
			return CountingProbability(SplitCount);
}
