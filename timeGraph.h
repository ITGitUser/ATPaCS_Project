#pragma once
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Limit {
	int beginTact;
	int endTact;
public:
	int GetTactBegin() { return beginTact; };
	int GetTactEnd() { return endTact; };
	Limit(int b, int end) { beginTact = b; endTact = end; };
};
//класс Ребро
class Edge {
private:
	int begin=NULL, end=NULL;
	double distance=NULL;
	vector<Edge*> next;
	vector<Limit> limit;
public:
	vector<Limit> GetLimit() {return this->limit;};
	Limit GetLimitbyIndex(int index) {return this->limit[index];};
	int GetBegin() { return this->begin; };
	int GetEnd() { return this->end; };
	double GetDistance() {return this->distance;};
	void setDistance(double dist) { this->distance = dist; };
	vector<Edge*> GetNext() { return this->next; };
	void AdLimit(int begin, int end) {
		Limit l(begin, end);
		limit.push_back(l);
	};
	void SetNext(vector<Edge*> nxt) { 
		for (Edge* n : nxt) {
			this->next.push_back(n);
		}
	};
	Edge(int beg, int end, double dist=0 ) {
		this->begin = beg;
		this->end = end;
		this->distance = dist;
	};
	bool operator== (const Edge& c1) {
		return (c1.begin == begin &&
			c1.end == end && c1.distance == distance);
	};

	Edge() {};
};

//класс узел в развертке-GraphTimeNode
class GTN {
private:
	Edge edge;
	double place;
	int time;
	GTN* prev;
	string status;
public:
	GTN* GetBegin() {
		GTN* res = this;
		while (res->GetPrev() != nullptr) {
			res = res->GetPrev();
		}
		return res;
	};
	void SetStatusGTN(string s) { this->status = s; };
	string GetStatusGTN() { return this->status; };
	Edge GetEdge() { return this->edge; };
	double GetPlace() { return this->place; };
	int GetTime() { return this->time;};
	GTN* GetPrev() { return this->prev; };
	void PrintPath() {
		GTN* res = this;
		while (res->GetPrev() != nullptr) {
			cout << "(" << res->GetEdge().GetBegin() << ", " << 
				res->GetEdge().GetEnd() << ") P:" << 
				res->GetPlace() << " T:" << 
				res->GetTime() << " S: " << 
				res->GetStatusGTN() << endl;
			res = res->GetPrev();
		}
		cout << "(" << res->GetEdge().GetBegin() << ", " <<
			res->GetEdge().GetEnd() << ") P:" <<
			res->GetPlace() << " T:" <<
			res->GetTime() << " S: " <<
			res->GetStatusGTN() << endl;
	};
	GTN(Edge e, double p, int t=0, GTN *prev=nullptr, string stat="go") {
		this->edge = e;
		this->place = p;
		this->time = t;
		this->prev = prev;
		this->status = stat;
	};
};


