#pragma once
#include "tactCalculation.h"
using namespace std;
struct Node {
	//номер вершины
	int numNode=0;
	//кол-во тактов
	int minTact = 10000000;//он же labelWeght 
	//номер вершины источника
	int edgeNode=0;
	//флаг посещения вершины
	bool visited = false;
};
class List {
private:
	vector<Node> list;
	//метод добавления узла в список
	void ListPushNode(int);
	//меод получения кол-во тактов у вершины с запрашиваемым номером
	int ListGetMinTact(int);
	//метод получения узла списка по номеру узла
	Node ListGetNodeByNum(int);
	//метод получения флага посещения узла
	bool ListGetLabelVisited(int);
	//вывод списка в консоль
	void ListPrintList();
	//метод установки источника, первый аргумент номер узла, второй номер источника
	void ListSetEdge(int, int);
	//метод установки кол-ва такта, первый аргумент номер узла, второй кол-во тактов
	void ListSetMinTact(int, int);
	//метод изменения флага посещения узла
	void ListChangeLabelVisited(int, bool);
	//метод получения индекс узла по нмеру узла
	int GetIndexNode(int);
	//метод получения номера смежной вершины с наименьшим кол-вом тактов, с условием не посещенности вершины
	int ListGetNumEdgeApexWithMinTactAndNotVisited(TactCalculation, int);
public:
	void PushNode(int numNode) { ListPushNode(numNode); };
	int GetMinTact(int numNode) { return ListGetMinTact(numNode); };
	Node GetNodeByNum(int num) { return ListGetNodeByNum(num); };
	bool GetLabelVisited(int numNode) { return ListGetLabelVisited(numNode); };
	void  PrintList() { ListPrintList(); };
	void SetEdge(int num, int edge) { ListSetEdge(num, edge); };
	void SetMinTact(int num, int tact) { ListSetMinTact(num, tact); };
	void SetLabelVisited(int numNode, bool label) { ListChangeLabelVisited(numNode, label); };
	int GetSize() { return list.size(); };
	int GetNumEdgeApexWithMinTactAndNotVisited(TactCalculation tactCalculation, int num) {
		return ListGetNumEdgeApexWithMinTactAndNotVisited(tactCalculation, num);
	};
	List() { this->list; };

};