#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include <vector>
#include "timeGraph.h"
using namespace std;

//создаем тип вершина
struct Apex {
	int numApex = 0;
	vector<int> edge;
};
//ИНДЕКСАЦИЯ ВЕРШИН ГРАФА НАЧИНАЕТСЯ С 0!!!
class Graph {
private:
	vector<Apex> adjList;
	//Функция создания новой струтктуры типа вершина, возвращает созданную струкутуру
	Apex* NewApex(vector<int>);
	//Функция добавления экзэмпляра типа Вершина в конец вектора смежности, возвращает вектор вершин, он же граф
	vector<Apex> PushGraph(vector<int>);
	//Функция получения вектора вершин смежных с данной, возвращает вектор вершин смежных с данной
	vector<Apex> GetAdjApex(int);
	//Функция получения вершины, с данным номером, индексация с 0, возвращает структуру типа вершина
	Apex GetAp(int);
	//Функция получения вершины, с данным индексом, индексация с 0, возвращает структуру типа вершина
	Apex GraphGetApByIndex(int);
	//Функция отображения списка смежности графа
	void PrintGraph(vector<Apex>);
	//Функция удаления вершины из графа...включая все ее связи
	void DeleteApex(int);
	//Функция удаляет все входящие связи вершины с данным номером
	void DelAllInputAdjApex(int);
	vector<Apex> GetGraph();
	//Функция получения индекса вершины с номером numapex
	int GetApIndex(int);
	//Функция удаления ребра, первым аргументом приниает номер вершины, вторым- номер смежной вершины
	void DelEdge(int, int);
	//Функция проверки количества ребер
	int CheckEdge();
	//Функция проверки количества вершин
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