#pragma once
#include "graph.h"
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include <queue>
#include "restrictedArea.h"
#include <iostream>
using namespace std;

class ModifiedLeeAlgoritm {
private:
	NextNodeAlgorithm currGTN;
public:
	//возвращает конечную GTN
	GTN* SearchWay(Edge*, Edge*, int, int tactEnd=-1);//tactEnd=-1, это флаг поиска маршрута без привязки к конечному такту
	ModifiedLeeAlgoritm(NextNodeAlgorithm node) { this->currGTN = node; };
};

