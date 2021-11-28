#pragma once
#include "timeGraph.h"
#include <vector>
class NextNodeAlgorithm {
private:
	double speed=1;// 1 κμ/χ
public:
	vector<GTN*> Next(GTN*) ;
};