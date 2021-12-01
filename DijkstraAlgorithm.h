#pragma once
#include "graph.h"
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include <queue>
using namespace std;



class DijkstraAlgoritm {
private:
	NextNodeAlgorithm currGTN;
public:
	//возвращает конечную GTN
	GTN SearchPath(Edge*, Edge*, int);
	DijkstraAlgoritm(NextNodeAlgorithm node) { this->currGTN = node; };
};

