#pragma once
#include <cstddef>
#include <vector>
using namespace std;

//класс Ребро
class Edge {
private:
	int begin=NULL, end=NULL;
	double distance=NULL;
	vector<Edge*> next;
public:
	 int GetBegin() { return this->begin; };
	 int GetEnd() { return this->end; };
	 double GetDistance() {return this->distance;};
	 vector<Edge*> GetNext() { return this->next; };
	void SetNext(vector<Edge*> nxt) { 
		for (Edge* n : nxt) {
			this->next.push_back(n);
		}
		//this->next = nxt;
	};
	Edge(int beg, int end, double dist ) {
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
public:

	Edge GetEdge() { return this->edge; };
	double GetPlace() { return this->place; };
	int GetTime() { return this->time;};
	GTN* GetPrev() { return this->prev; };
	GTN(Edge e, double p, int t, GTN *prev=nullptr) {
		this->edge = e;
		this->place = p;
		this->time = t;
		this->prev = prev;
	};
};