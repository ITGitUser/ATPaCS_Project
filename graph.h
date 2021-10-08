#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include <vector>
using namespace std;

//������� ��� �������
struct Apex {
	int numApex = 0;
	vector<int> edge;
	bool visited = false;
	vector<float> length;
	float begin=0, end=0;
	vector<int> maxspeed;
};
//���������� ������ ����� ���������� � 0!!!
class Graph {
private:
	vector<Apex> adjList;
	//������� �������� ����� ���������� ���� �������, ���������� ��������� ����������
	Apex* NewApex(vector<int>, vector<float>, vector<int> maxspeed);
	//������� ���������� ���������� ���� ������� � ����� ������� ���������, ���������� ������ ������, �� �� ����
	vector<Apex> PushGraph(vector<int>, vector<float>, vector<int> maxspeed);
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
	//������� �������� ��������� �������
	bool CheckVisited(int);
	//������� ��������� "�����" ��������� �������
	void ChangeVisited(int);
	//������� ��������� ������� ������� � ������� numapex
	int GetApIndex(int);
	//������� �������� �����, ������ ���������� �������� ����� �������, ������- ����� ������� �������
	void DelEdge(int, int);
	//������� �������� ���������� �����
	void CheckEdge();
	//������� �������� ���������� ������
	int GraphCheckQuantityApex();
public:
	void Push(vector<int> edge, vector<float> length, vector<int> maxspeed) { PushGraph(edge, length, maxspeed); };
	vector<Apex> GetAdj(int numApex) { return GetAdjApex(numApex); };
	Apex GetApex(int numApex) { return GetAp(numApex); };
	Apex GetApexByIndex(int indexApex) { return GraphGetApByIndex(indexApex); };
	void Print() { PrintGraph(adjList); }
	void DelApex(int numApex) { DeleteApex(numApex); }
	vector<Apex> getGraph() { return GetGraph(); };
	bool checkVisted(int apex) { return CheckVisited(apex); }
	void changeVisited(int apex) { ChangeVisited(apex); }
	int getApexIndex(int apex) { return GetApIndex(apex); }
	void delEdge(int apex, int edge) { DelEdge(apex, edge); }
	void checkEdge() { CheckEdge(); }
	int checkQuantityApex() { return GraphCheckQuantityApex(); }
	
	Graph() { this->adjList; };
};
#endif