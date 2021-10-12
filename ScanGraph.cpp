
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
TactPosition& EdgeApexScan::EdgeApexScanGetTactPosition(int index) {
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
vector<EdgeApexScan>& RootScan::RootScanGetVectorEdge() {
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
				cout << "(" << n.GetEdgeApex(g).GetTactPosition(k).GetNumberTrack() << " ";
				cout << n.GetEdgeApex(g).GetTactPosition(k).GetDirection() << " ";
				cout << n.GetEdgeApex(g).GetTactPosition(k).GetPosition() << " ";
				cout << n.GetEdgeApex(g).GetTactPosition(k).GetLabelFree() << " ";
				cout << n.GetEdgeApex(g).GetTactPosition(k).GetTact() << ")";
			}
		}
		cout << endl;
	}
}
//метод получения вершины типа rootScan по номеру вершины
RootScan& Scan::ScanGetRootByNum(int num) {
	bool label = false;
	for (int i = 0; i < this->scan.size(); i++)
	{
		if (scan[i].GetNumRoot() == num) {
			label = true;
			return this->scan[i];
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
	for (int i = 0; i < graph.checkQuantityApex(); i++) {//перебираем вершины
		currentRootScan.SetNumRoot(graph.GetApexByIndex(i).numApex);//записываем номер вершины
		for (int k = 0; k < graph.GetApexByIndex(i).edge.size(); k++) {//перебираем смежные вершины
			edgeApexScan.SetNumApex(graph.GetApexByIndex(i).edge[k]);//записываем номер смежной вершины
			for (int z = 0; z < this->tact; z++)
			{
				currentTactPosition.SetDirection(graph.GetApexByIndex(i).edge[k]);
				currentTactPosition.SetTact(z);
				edgeApexScan.PushPathInVector(currentTactPosition);//записываем позицию в вектор
			}
			currentRootScan.Push(edgeApexScan);//записываем развертку для смежной вершины
			edgeApexScan.Clear();//обнуляем временный контейнер
		}
		this->Push(currentRootScan);
		currentRootScan.Clear();//обнуляем временный контейнер
		
	}
	return scan;
}
//Установка препятствия
void Scan::ScanSetBarrier(int tactBegin, int tactEnd, int position, int positionDirection, int type) {
	if (tactBegin<this->ScanGetTact()&&tactBegin>=0&&tactBegin<=tactEnd)
	{
		for (int i = tactBegin; i <= tactEnd; i++)
		{
			cout << this->GetRootByNum(position).GetEdgeApex(positionDirection).GetTactPosition(i).GetLabelFree() << endl;
			this->GetRootByNum(position).GetEdgeApex(positionDirection).GetTactPosition(i).SetLabelFree(false);
			cout << this->GetRootByNum(position).GetEdgeApex(positionDirection).GetTactPosition(i).GetLabelFree() << endl;
		}
		
			//this->GetRootByNum(position).GetEdgeApex(positionDirection).GetVectorPath().size();
		
	}
	else {
		cout << "///////////Error-Scan(ScanSetBarrier)///////////: такта или позиции не существует"<< endl;
	}
}
