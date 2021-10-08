#include <iostream>
#include "graph.h"
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;
//Функция создания новой струтктуры типа вершина, возвращает созданную струкутуру
Apex* Graph::NewApex(vector<int> edge, vector<float> length, vector<int> maxspeed) {
	Apex* currentApex = new Apex;
	currentApex->edge = edge;
	currentApex->length = length;
	currentApex->maxspeed = maxspeed;
	return currentApex;
}
//Функция добавления экзэмпляра типа Вершина в конец вектора смежности, возвращает вектор вершин, он же граф
vector<Apex> Graph::PushGraph(vector<int> edge, vector<float> length, vector<int> maxspeed) {
	Apex* currentApex = NewApex(edge, length, maxspeed);
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
		//-----Выводим длины вершины в зависимости от смежности-----//
		copy(n.length.begin(),
			n.length.end(),
			ostream_iterator<float>(cout, " "));
		//-----Выводим максимальные скорости вершины в зависимости от смежности-----//
		copy(n.maxspeed.begin(),
			n.maxspeed.end(),
			ostream_iterator<int>(cout, " "));
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
//Функция проверки посещения вершины
bool Graph::CheckVisited(int apex) {
	return GetAp(apex).visited;
}
//Функция изменения "флага" посещения вершины
void Graph::ChangeVisited(int apex) {
	this->adjList[getApexIndex(apex)].visited = true;
}


//Функция удаления ребра, первым аргументом приниает номер вершины, вторым- номер смежной вершины
void Graph::DelEdge(int apex, int indexedge) {
	this->adjList[getApexIndex(apex)].edge.erase(this->adjList[getApexIndex(apex)].edge.begin() + indexedge);
}
//Функция проверки количества ребер
void Graph::CheckEdge() {
	int numEdge = 0;
	for (int i = 0; i < this->adjList.size(); i++) {
		for (int j = 0; j < this->adjList[i].edge.size(); j++) {
			numEdge++;
		}
	}
	cout << "Количество ребер включая их направленность: " << numEdge << endl;
}


int Graph::GraphCheckQuantityApex() {
	return adjList.size();
}