#pragma once
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include "modifiedLeeAlgorithm.h"
class Route {
private:
	int numRoute;
	//TypeRoute:
	//10-high speed train
	//11-electric train
	//12-passenger train
	//13-freight train
	int typeRoute;
	bool fixedEndTact;
	GTN *endPoint, *beginPoint;
	Edge* beginEdge;
	int tactBegin, tactEnd;
public:
	void SetEndPoint(GTN* gtne) { this->endPoint = gtne; };
	void SetBeginPoint(GTN* gtnb) { this->beginPoint = gtnb; };
	void SetNumRoute(int num) { this->numRoute = num; };
	void SetType(int type) { this->typeRoute = type; };
	void SetTact(int beg, int end) { 
		this->tactBegin = beg;
		this->tactEnd = end;
	};
	void SetFlagFixedEndTact(int flag) { 
		if (flag < 0) {
			this->fixedEndTact = false;
		}
		else {
			this->fixedEndTact = true;
		}
		  };
	void SetBeginEdge(Edge* beg) { this->beginEdge = beg; };
	int GetNumRoute() { return this->numRoute; };
	int GetTactBegin() { return tactBegin; };
	int GetTactEnd() { return tactEnd; };
	Edge* GetBeginEdge() { return this->beginEdge; };
	int GeType() { return this->typeRoute; };
	GTN* GetEndPoint() { return this->endPoint;; };
	GTN* GetBeginPoint() { return this->beginPoint; };
	Route(int num, int type, Edge* B, int tactB, int tactE, GTN* EP, GTN* BP) {
		this->SetNumRoute(num);
		this->SetType(type);
		this->SetBeginEdge(B);
		this->SetTact(tactB, tactE);
		this->SetFlagFixedEndTact(tactE);
		this->SetEndPoint(EP);
		this->SetBeginPoint(BP);
	};
	~Route() {
		//delete endPoint;
		//delete beginPoint;
		//delete beginEdge;
	}
	//Route() {};
};

class RouteManager {
private:
	GraphEdge* gEdge;
	vector<Route*> allRoute;
	NextNodeAlgorithm alg;
	ModifiedLeeAlgoritm finder = ModifiedLeeAlgoritm(alg);
	void makeTransparentRoute(int);
	Route* findRoute(int);
public: 
	void AddRoute(int, Edge*, Edge*, int, int EndTact=-1);
	void DeleteRoute(int);
	int SetNumRoute() { return 10; };
	void ReBuildRoutes() {};
	RouteManager(GraphEdge *g) { this->gEdge = g; };
	RouteManager() {};
};