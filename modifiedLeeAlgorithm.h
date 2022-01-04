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
	//���������� �������� GTN
	GTN* SearchWay(Edge*, Edge*, int, int tactEnd=-1);//tactEnd=-1, ��� ���� ������ �������� ��� �������� � ��������� �����
	ModifiedLeeAlgoritm(NextNodeAlgorithm node) { this->currGTN = node; };
};

