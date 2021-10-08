
#include <iostream>
#include "scanGraph.h"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

//-------EdgeApexScan--------//
//метод установки номера смежной вершины
void EdgeApexScan::EdgeApexScanSetNumApex(int number) {
	this->numApex = number;
}
//меод получения номера смежной вершны
int EdgeApexScan::EdgeApexScanGetNumApex() {
	return this->numApex;
}
//метод получения конкретного TactPosition по индексу в векторе tactPosition
TactPosition EdgeApexScan::EdgeApexScanGetTactPosition(int index) {
	return this->tactPosition[index];
}
//метод добавления структуры типа TactPosition в вектор tactPosition
void EdgeApexScan::EdgeApexScanPushPathInVector(TactPosition tactPosition) {
	this->tactPosition.push_back(tactPosition);

}
//метод получения вектора тактов типа TactPosition
vector<TactPosition> EdgeApexScan::EdgeApexScanGetVectorPath() {
	return this->tactPosition;
}
//метод очистки смежной вершины
void EdgeApexScan::EdgeApexScanClear() {
	this->tactPosition.clear();
	int numApex = -1;
	int minTact = -1;
}
//---------RootScan--------//
//метод установки номера вершины типа rootScan, в аргумент передается номер вершины
void RootScan::RootScanSetNumRoot(int number) {
	this->numApex = number;
}
//метод получения номера вершины типа rootScan
int RootScan::RootScanGetNumRoot() {
	return this->numApex;
}
//метод получения вектора смежных root'ов 
vector<EdgeApexScan> RootScan::RootScanGetVectorEdge() {
	return this->Edge;
}
//метод получения смежной вершины типа EdgeApexScan у root'а по индексу
EdgeApexScan RootScan::RootScanGetEdgeApex(int index) {
	return this->Edge[index];
}
//метод добавления смежной вершны типа EdgeApexScan
void RootScan::RootScanPush(EdgeApexScan edge) {
	this->Edge.push_back(edge);
}
//метод очистки rootScan
void RootScan::RootScanClear() {
	this->Edge.clear();
}
//--------Scan--------//
//метод добавления вершины типа rootScan в Развертку
void Scan::ScanPush(RootScan root) {
	this->scan.push_back(root);
}
//вывод Развертки в консоль
void Scan::ScanPrint(vector<RootScan> scan) {
	cout << "__________________________" << endl;
	cout << "Развертка:" << endl;
	for (RootScan n : scan) {
		//-----Выводим номера вершин рутов-----//
		cout << "Вершина (" << n.GetNumRoot() << ") :"; //номер вершины-root
		for (int g = 0; g < n.GetVectorEdge().size(); g++) {
			cout << endl << "смежность: " << n.GetEdgeApex(g).GetNumApex();//номер смежной вершины и число тактов
			for (int k = 0; k < n.GetEdgeApex(g).GetVectorPath().size(); k++) {//выводим позиции
				cout << "(" << n.GetEdgeApex(g).GetPath(k).numberTrack << " ";
				cout << n.GetEdgeApex(g).GetPath(k).direction << " ";
				cout << n.GetEdgeApex(g).GetPath(k).position << " ";
				cout << n.GetEdgeApex(g).GetPath(k).labelfree << " ";
				cout << n.GetEdgeApex(g).GetPath(k).tact << ")";
			}
		}
		cout << endl;
	}
}
//метод получения вершины типа rootScan по номеру вершины
RootScan Scan::ScanGetRootByNum(int num) {
	bool label = false;
	for (int i = 0; i < this->scan.size(); i++)
	{
		if (scan[i].GetNumRoot() == num) {
			label = true;
			return scan[i];
		}
		
	}
	if (!label) {
		cout << "///////////Error-Scan(ScanGetRootByNum)///////////: вершины с номером: " << num << " не существует! " << this->scan.size() << endl;
	}
}

//инициализация Развертки на основе графа
vector<RootScan> Scan::ScanInitialization(Graph& graph) {
	RootScan currentRootScan;
	EdgeApexScan edgeApexScan;
	TactPosition currentTactPosition;
	int const Tact = 15;//требуемое количество тактов для развертки
	for (int i = 0; i < graph.checkQuantityApex(); i++) {//перебираем вершины
		currentRootScan.SetNumRoot(graph.GetApexByIndex(i).numApex);//записываем номер вершины
		for (int k = 0; k < graph.GetApexByIndex(i).edge.size(); k++) {//перебираем смежные вершины
			edgeApexScan.SetNumApex(graph.GetApexByIndex(i).edge[k]);//записываем номер смежной вершины
			for (int z = 0; z < Tact; z++)
			{
				currentTactPosition.direction = graph.GetApexByIndex(i).edge[k];
				currentTactPosition.tact = z;
				edgeApexScan.PushPathInVector(currentTactPosition);//записываем позицию в вектор
			}
			//обнуляем временные контейнеры
			currentRootScan.Push(edgeApexScan);//записываем развертку для смежной вершины
			edgeApexScan.Clear();
		}
		this->Push(currentRootScan);
		currentRootScan.Clear();
		
	}
	return scan;
}
