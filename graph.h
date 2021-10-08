#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include <vector>
using namespace std;

//создаем тип вершина
struct Apex {
	int numApex = 0;
	vector<int> edge;
	bool visited = false;
	vector<float> length;
	float begin=0, end=0;
	vector<int> maxspeed;
};
//ИНДЕКСАЦИЯ ВЕРШИН ГРАФА НАЧИНАЕТСЯ С 0!!!
class Graph {
private:
	vector<Apex> adjList;
	//Функция создания новой струтктуры типа вершина, возвращает созданную струкутуру
	Apex* NewApex(vector<int>, vector<float>, vector<int> maxspeed);
	//Функция добавления экзэмпляра типа Вершина в конец вектора смежности, возвращает вектор вершин, он же граф
	vector<Apex> PushGraph(vector<int>, vector<float>, vector<int> maxspeed);
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
	//Функция проверки посещения вершины
	bool CheckVisited(int);
	//Функция изменения "флага" посещения вершины
	void ChangeVisited(int);
	//Функция получения индекса вершины с номером numapex
	int GetApIndex(int);
	//Функция удаления ребра, первым аргументом приниает номер вершины, вторым- номер смежной вершины
	void DelEdge(int, int);
	//Функция проверки количества ребер
	void CheckEdge();
	//Функция проверки количества вершин
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