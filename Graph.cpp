#include <iostream>
#include "graph.h"
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;
//Функция создания новой струтктуры типа вершина, возвращает созданную струкутуру
Apex* Graph::NewApex(vector<int> edge) {
	Apex* currentApex = new Apex;
	currentApex->edge = edge;
	return currentApex;
}
//Функция добавления экзэмпляра типа Вершина в конец вектора смежности, возвращает вектор вершин, он же граф
vector<Apex> Graph::PushGraph(vector<int> edge) {
	Apex* currentApex = NewApex(edge);
	currentApex->numApex = adjList.size();
	adjList.push_back(*currentApex);
	return adjList;
}
//Функция получения вектора вершин смежных с данной, возвращает вектор вершин смежных с данной
vector<Apex> Graph::GetAdjApex(int numApex) {
	vector<Apex> adjVector;
	if (numApex < adjList.size() + 1) {
		for (int i = 0; i < this->GetAp(numApex).edge.size(); i++) {
			adjVector.push_back(GetApex(GetAp(numApex).edge[i]));
		}
	}
	else {
		cout << "размер графа" << adjList.size() << endl;
	}
	return adjVector;
}
//Функция получения вершины, с данным номером, не по индексу в векторе, а именно по номеру вершины
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
//Функция получения вершины, с данным индексом
Apex Graph::GraphGetApByIndex(int indexAp) {
	Apex currApex = this->adjList[indexAp];
	return currApex;
}
//Функция получения индекса вершины с номером numapex
int Graph::GetApIndex(int numAp) {
	Apex currApex;
	int iter = 0;
	for (iter = 0; iter < this->adjList.size(); iter++) {
		if (this->adjList[iter].numApex == numAp) {
			return iter;
		}
	}
}
//Функция отображения списка смежности графа
void Graph::PrintGraph(vector<Apex> adjList) {
	cout << "список смежности" << endl;
	for (Apex n : adjList) {
		//-----Выводим номера смежных вершин-----//
		cout << n.numApex << " "; //номер вершины графа
		copy(n.edge.begin(),   // итератор начала массива
			n.edge.end(),     // итератор конца массива
			ostream_iterator<int>(cout, " "));   //итератор потока вывода
		cout << endl;

	}
}
//Функция удаляет вершину из графа...включая все ее исходящие! связи
void Graph::DeleteApex(int numApex) {
	DelAllInputAdjApex(numApex);
	adjList.erase(adjList.begin() + getApexIndex(numApex));
}
//Функция удаляет все входящие связи
void Graph::DelAllInputAdjApex(int numApex) {
	for (int i = 0; i < adjList.size(); i++) {
		for (int k = 0; k < adjList[i].edge.size(); k++) {
			if (adjList[i].edge[k] == numApex) {
				adjList[i].edge.erase(adjList[i].edge.begin() + k);
			};
		}
	}
}
//Функция получения вектора вершин-т.е. графа
vector<Apex> Graph::GetGraph() {
	return this->adjList;
}
//Функция удаления ребра, первым аргументом приниает номер вершины, вторым- номер смежной вершины
void Graph::DelEdge(int apex, int indexedge) {
	this->adjList[getApexIndex(apex)].edge.erase(this->adjList[getApexIndex(apex)].edge.begin() + indexedge);
}
//Функция проверки количества ребер
int Graph::CheckEdge() {
	int numEdge = 0;
	for (int i = 0; i < this->adjList.size(); i++) {
		for (int j = 0; j < this->adjList[i].edge.size(); j++) {
			numEdge++;
		}
	}
	//cout << "Количество ребер включая их направленность: " << numEdge << endl;
	return numEdge;
}
int Graph::GraphCheckQuantityApex() {
	return adjList.size();
}


//инициализация гарфа ребер
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
//печать графа ребер в консоли
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