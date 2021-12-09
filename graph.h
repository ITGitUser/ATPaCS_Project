#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include <vector>
#include "timeGraph.h"
using namespace std;

//������� ��� �������
struct Apex {
	int numApex = 0;
	vector<int> edge;
};
//���������� ������ ����� ���������� � 0!!!
class Graph {
private:
	vector<Apex> adjList;
	//������� �������� ����� ���������� ���� �������, ���������� ��������� ����������
	Apex* NewApex(vector<int>);
	//������� ���������� ���������� ���� ������� � ����� ������� ���������, ���������� ������ ������, �� �� ����
	vector<Apex> PushGraph(vector<int>);
	//������� ��������� ������� ������ ������� � ������, ���������� ������ ������ ������� � ������
	vector<Apex> GetAdjApex(int);
	//������� ��������� �������, � ������ �������, ���������� � 0, ���������� ��������� ���� �������
	Apex GetAp(int);
	//������� ��������� �������, � ������ ��������, ���������� � 0, ���������� ��������� ���� �������
	Apex GraphGetApByIndex(int);
	//������� ����������� ������ ��������� �����
	void PrintGraph(vector<Apex>);
	//������� �������� ������� �� �����...������� ��� �� �����
	void DeleteApex(int);
	//������� ������� ��� �������� ����� ������� � ������ �������
	void DelAllInputAdjApex(int);
	vector<Apex> GetGraph();
	//������� ��������� ������� ������� � ������� numapex
	int GetApIndex(int);
	//������� �������� �����, ������ ���������� �������� ����� �������, ������- ����� ������� �������
	void DelEdge(int, int);
	//������� �������� ���������� �����
	int CheckEdge();
	//������� �������� ���������� ������
	int GraphCheckQuantityApex();
public:
	void Push(vector<int> edge) { PushGraph(edge); };
	vector<Apex> GetAdj(int numApex) { return GetAdjApex(numApex); };
	Apex GetApex(int numApex) { return GetAp(numApex); };
	Apex GetApexByIndex(int indexApex) { return GraphGetApByIndex(indexApex); };
	void Print() { PrintGraph(adjList); }
	void DelApex(int numApex) { DeleteApex(numApex); }
	vector<Apex> getGraph() { return GetGraph(); };
	int getApexIndex(int apex) { return GetApIndex(apex); }
	void delEdge(int apex, int edge) { DelEdge(apex, edge); }
	int checkEdge() { return CheckEdge(); }
	int checkQuantityApex() { return GraphCheckQuantityApex(); }
	int getSizeGraph() { return this->adjList.size(); };
	Graph() { this->adjList; };
};

class GraphEdge {
private:
	vector<Edge> gEdge;
	void GraphEdgeInit(Graph);
public:
	void SetDistance(int indexEdge, double dist) { this->gEdge[indexEdge].setDistance(dist); };
	Edge* GetEdge(int index) { return &gEdge[index]; };
	void Print();
	GraphEdge(Graph g) { GraphEdgeInit(g); };
};

#endif