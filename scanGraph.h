#pragma once

#include "graph.h"
using namespace std;
//path-струкура позиции в зависимости от времени
//root-корень рассматриваемых деревьев, содержит вектор путей
//scan-развертка, совокупность рассматриваемых рутов
struct TactPosition {
	int numberTrack = 0000;
	int direction = 0; //направление, т.е. одна из смежных вершин, к которой считаем позицию
	int position = 0; //от 0 до 100
	int tact = 0;
	bool labelfree = true;//метка свободности такта, true-использовать можно, такт свободен 
};
class EdgeApexScan {
private:
	//номер смежной вершины
	int numApex = -1;
	//развертка состоящая стрктуры типа TactPosition
	vector<TactPosition> tactPosition;
	//метод установки номера смежной вершины
	void EdgeApexScanSetNumApex(int);
	//метод получения номера смежной вершны
	int EdgeApexScanGetNumApex();
	//метод получения конкретного TactPosition по индексу в векторе tactPosition
	TactPosition EdgeApexScanGetTactPosition(int);
	//метод добавления структуры типа TactPosition в вектор tactPosition
	void EdgeApexScanPushPathInVector(TactPosition);
	//метод получения вектора тактов типа TactPosition
	vector<TactPosition> EdgeApexScanGetVectorPath();
	//метод очистки смежной вершины
	void EdgeApexScanClear();
public:
	void SetNumApex(int num) { EdgeApexScanSetNumApex(num); };
	int GetNumApex() { return EdgeApexScanGetNumApex(); };
	TactPosition GetPath(int index) { return EdgeApexScanGetTactPosition(index); };
	void PushPathInVector(TactPosition tactPosition) { EdgeApexScanPushPathInVector(tactPosition); };
	vector<TactPosition> GetVectorPath() { return EdgeApexScanGetVectorPath(); };
	void Clear() { EdgeApexScanClear(); };
};
class RootScan{
private:
	//classSector-класс участка от 1 до 5
	int classSector=5;
	//номер вершины типа rootScan
	int numApex = 0;
	//вектор смежных вершин типа EdgeApexScan
	vector<EdgeApexScan> Edge;
	//метод установки номера вершины типа rootScan, в аргумент передается номер вершины
	void RootScanSetNumRoot(int);
	//метод получения номера вершины типа rootScan
	int RootScanGetNumRoot();
	//метод получения вектора смежных root'ов 
	vector<EdgeApexScan> RootScanGetVectorEdge();
	//метод получения смежной вершины типа EdgeApexScan у root'а по индексу
	EdgeApexScan RootScanGetEdgeApex(int);
	//метод добавления смежной вершны типа EdgeApex
	void RootScanPush(EdgeApexScan);
	//метод очистки rootScan
	void RootScanClear();
public:
	void SetNumRoot(int num) { RootScanSetNumRoot(num); };
	int GetNumRoot() { return RootScanGetNumRoot(); };
	vector<EdgeApexScan> GetVectorEdge() { return RootScanGetVectorEdge(); };
	EdgeApexScan GetEdgeApex(int index) { return RootScanGetEdgeApex(index); }
	void Push(EdgeApexScan edge) { RootScanPush(edge); };
	void Clear() { RootScanClear(); };
};
class Scan {
private:
	vector<RootScan> scan;
	//метод добавления вершины типа rootScan в Развертку
	void ScanPush(RootScan);
	//вывод Развертки в консоль
	void ScanPrint(vector<RootScan>);
	//метод получения вершины типа rootScan по номеру вершины
	RootScan ScanGetRootByNum(int);
	//инициализация Развертки на основе графа
	vector<RootScan> ScanInitialization(Graph&);
public:
	vector<RootScan> Initialization(Graph& graph) { return ScanInitialization(graph); };
	void Push(RootScan root) { ScanPush(root); };
	void Print() { ScanPrint(scan); };
	RootScan GetRootByNum(int num) { return ScanGetRootByNum(num); };
	RootScan GetRootByIndex(int num) { return scan[num]; };
	int GetSizeScan() { return this->scan.size(); };
	Scan() { this->scan; };
};
