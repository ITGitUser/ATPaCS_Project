#pragma once
#include "timeGraph.h"
using namespace std;

class RestrictedArea {
public:
	RestrictedArea(Edge* e, int tBeg, int tEnd) {
		e->SetLimit(tBeg, tEnd);
	}
};