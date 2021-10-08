#include <iostream>
#include <vector>
#include "list.h"

using namespace std;
//-------------List-----------//
//метод добавления узла в список
void List::ListPushNode(int numNode) {
	Node currentNode;
	currentNode.numNode = numNode;
	this->list.push_back(currentNode);
}
//меод получения кол-во тактов у вершины с запрашиваемым номером
int List::ListGetMinTact(int numNode) {
	return this->list[GetIndexNode(numNode)].minTact;
}
//метод получения узла списка по номеру узла
Node List::ListGetNodeByNum(int num) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (list[i].numNode == num)
		{
			return list[i];
		}
	}
	//ERROR-узел в списке не существует!
	cout << "//////////Error-List(ListGetNodeByNum)///////////: узел в списке не существует!" << endl;
}
//метод получения флага посещения узла
bool List::ListGetLabelVisited(int numNode) {
	return this->list[GetIndexNode(numNode)].visited;
	//вывод списка в консоль
}
//вывод списка в консоль
void List::ListPrintList() {
	cout << "__________________________" << endl;
	cout << "Список узлов:" << endl;
	for (int i = 0; i < this->GetSize(); i++)
	{
		cout << "Вершина (" << list[i].numNode << ")" << " Такты: " << list[i].minTact << " Источник: " << list[i].edgeNode << endl;

	}
}
//метод установки источника, первый аргумент номер узла, второй номер источника
void List::ListSetEdge(int num, int edge) {
	this->list[GetIndexNode(num)].edgeNode = edge;
}
//метод установки кол-ва такта, первый аргумент номер узла, второй кол-во тактов
void List::ListSetMinTact(int num, int tact) {
	this->list[GetIndexNode(num)].minTact = tact;
}
//метод изменения флага посещения узла
void List::ListChangeLabelVisited(int numNode, bool label) {
	this->list[GetIndexNode(numNode)].visited = label;
}
//метод получения индекс узла по нмеру узла
int List::GetIndexNode(int numNode) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (list[i].numNode == numNode)
		{
			return i;
		}
	}
	//ERROR-узел в списке не существует!
	cout << "///////////Error-List(GetIndexNode)///////////: узел в списке не существует!" << endl;
}
//метод получения номера смежной вершины с наименьшим кол-вом тактов, с условием не посещенности вершины
int List::ListGetNumEdgeApexWithMinTactAndNotVisited(Scan scan, int numApex) {
	int sizeVectorEdge = scan.GetRootByNum(numApex).GetVectorEdge().size();
	int minTact = 10000000;
	int num = -1;
	for (int i = 0; i < sizeVectorEdge; i++)
	{
		int tact = scan.GetRootByNum(numApex).GetEdgeApex(i).GetMinTact();

		if (!this->GetLabelVisited(scan.GetRootByNum(numApex).GetEdgeApex(i).GetNumApex()) && minTact > tact) {
			num = scan.GetRootByNum(scan.GetRootByNum(numApex).GetEdgeApex(i).GetNumApex()).GetNumRoot();
			minTact = tact;
		}
	}
	return num;
}

