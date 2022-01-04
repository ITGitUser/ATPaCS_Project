#include <iostream>
#include "graph.h"
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;
//������� �������� ����� ���������� ���� �������, ���������� ��������� ����������
Apex* Graph::NewApex(vector<int> edge) {
	Apex* currentApex = new Apex;
	currentApex->edge = edge;
	return currentApex;
}
//������� ���������� ���������� ���� ������� � ����� ������� ���������, ���������� ������ ������, �� �� ����
vector<Apex> Graph::PushGraph(vector<int> edge) {
	Apex* currentApex = NewApex(edge);
	currentApex->numApex = adjList.size();
	adjList.push_back(*currentApex);
	return adjList;
}
//������� ��������� ������� ������ ������� � ������, ���������� ������ ������ ������� � ������
vector<Apex> Graph::GetAdjApex(int numApex) {
	vector<Apex> adjVector;
	if (numApex < adjList.size() + 1) {
		for (int i = 0; i < this->GetAp(numApex).edge.size(); i++) {
			adjVector.push_back(GetApex(GetAp(numApex).edge[i]));
		}
	}
	else {
		cout << "������ �����" << adjList.size() << endl;
	}
	return adjVector;
}
//������� ��������� �������, � ������ �������, �� �� ������� � �������, � ������ �� ������ �������
Apex Graph::GetAp(int numAp) {
	Apex currApex;
	vector<Apex> currVec = this->adjList;
	for (Apex n : currVec) {
		if (n.numApex == numAp) {
			currApex = n;
		}
	}
	return currApex;
}
//������� ��������� �������, � ������ ��������
Apex Graph::GraphGetApByIndex(int indexAp) {
	Apex currApex = this->adjList[indexAp];
	return currApex;
}
//������� ��������� ������� ������� � ������� numapex
int Graph::GetApIndex(int numAp) {
	Apex currApex;
	int iter = 0;
	for (iter = 0; iter < this->adjList.size(); iter++) {
		if (this->adjList[iter].numApex == numAp) {
			return iter;
		}
	}
}
//������� ����������� ������ ��������� �����
void Graph::PrintGraph(vector<Apex> adjList) {
	cout << "������ ���������" << endl;
	for (Apex n : adjList) {
		//-----������� ������ ������� ������-----//
		cout << n.numApex << " "; //����� ������� �����
		copy(n.edge.begin(),   // �������� ������ �������
			n.edge.end(),     // �������� ����� �������
			ostream_iterator<int>(cout, " "));   //�������� ������ ������
		cout << endl;

	}
}
//������� ������� ������� �� �����...������� ��� �� ���������! �����
void Graph::DeleteApex(int numApex) {
	DelAllInputAdjApex(numApex);
	adjList.erase(adjList.begin() + getApexIndex(numApex));
}
//������� ������� ��� �������� �����
void Graph::DelAllInputAdjApex(int numApex) {
	for (int i = 0; i < adjList.size(); i++) {
		for (int k = 0; k < adjList[i].edge.size(); k++) {
			if (adjList[i].edge[k] == numApex) {
				adjList[i].edge.erase(adjList[i].edge.begin() + k);
			};
		}
	}
}
//������� ��������� ������� ������-�.�. �����
vector<Apex> Graph::GetGraph() {
	return this->adjList;
}
//������� �������� �����, ������ ���������� �������� ����� �������, ������- ����� ������� �������
void Graph::DelEdge(int apex, int indexedge) {
	this->adjList[getApexIndex(apex)].edge.erase(this->adjList[getApexIndex(apex)].edge.begin() + indexedge);
}
//������� �������� ���������� �����
int Graph::CheckEdge() {
	int numEdge = 0;
	for (int i = 0; i < this->adjList.size(); i++) {
		for (int j = 0; j < this->adjList[i].edge.size(); j++) {
			numEdge++;
		}
	}
	//cout << "���������� ����� ������� �� ��������������: " << numEdge << endl;
	return numEdge;
}
int Graph::GraphCheckQuantityApex() {
	return adjList.size();
}


//������������� ����� �����
void GraphEdge::GraphEdgeInit(Graph g) {
	for (int i = 0; i < g.getSizeGraph(); i++)
	{
		for (int k = 0; k < g.GetApexByIndex(i).edge.size(); k++)
		{
			this->gEdge.push_back(Edge(g.GetApexByIndex(i).numApex, g.GetApexByIndex(i).edge[k]));
		}
	}
	for (int n = 0; n < this->gEdge.size(); n++)
	{
		vector<Edge*> vecEdge;
		for (int m = 0; m < gEdge.size(); m++)
		{
			if (gEdge[n].GetEnd()== gEdge[m].GetBegin()) {
				vecEdge.push_back(&gEdge[m]);
			}
		}
		gEdge[n].SetNext(vecEdge);
	}
}
//������ ����� ����� � �������
void GraphEdge::Print() {
	for (int i = 0; i < gEdge.size(); i++)
	{
		cout << "(" << gEdge[i].GetBegin() << ", " <<
			gEdge[i].GetEnd() << ") Dist:" <<
			gEdge[i].GetDistance() <<

			endl;
		for (int t = 0; t < gEdge[i].GetNext().size(); t++)
		{
			cout << "( " << gEdge[i].GetNext()[t]->GetBegin() << "," << gEdge[i].GetNext()[t]->GetEnd() << ") ";
		}
		cout << endl;
		cout << "--------------" << endl;
	}

}