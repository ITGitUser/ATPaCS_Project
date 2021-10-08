#pragma once
#include "graph.h"
using namespace std;
//path-струкура позиции в зависимости от времени
//root-корень рассматриваемых деревьев, содержит вектор путей
//scan-развертка, совокупность рассматриваемых рутов
struct Path {
	int direction = 0; //направление, т.е. одна из смежных вершин, к которой считаем позицию
	int position = 0; //от 0 до 100
	int tact = 0;
};
class EdgeApex {
private:
	//номер смежной вершины
	int numApex = -1;
	//наименьшее количество тактов пройденых до достижения смежной вершины
	int minTact=-1;
	//путь состоящий из вершины направления, позициии за такт, и номер тактов
	vector<Path> path;
	//метод установки номера смежной вершины
	void EdgeApexSetNumApex(int);
	//меод получения номера смежной вершны
	int EdgeApexGetNumApex();
	//метод установки наименьшего кол-во такта до смежной вершны(вершины направления)
	void EdgeApexSetMinTact(int);
	//меод получения наименьшего кол-во такта до смежной вершны(вершины направления)
	int EdgeApexGetMinTact();
	//метод получения конкретного пути типа Path по индексу в векторе path
	Path EdgeApexGetPath(int);
	//метод получения вектора пути типа Path
	vector<Path> EdgeApexGetVectorPath();
	//метод добавления пути типа Path в вектор path
	void EdgeApexPushPathInVector(Path);
	//метод очистки смежной вершины
	void EdgeApexClear();
public:
	void SetNumApex(int num) { EdgeApexSetNumApex(num); };
	int GetNumApex() { return EdgeApexGetNumApex(); };
	void SetMinTact(int tact) { EdgeApexSetMinTact(tact); };
	int GetMinTact() { return EdgeApexGetMinTact(); };
	Path GetPath(int index) { return EdgeApexGetPath(index); };
	vector<Path> GetVectorPath() { return EdgeApexGetVectorPath(); };
	void PushPathInVector(Path path) { EdgeApexPushPathInVector(path); };
	void Clear() { EdgeApexClear(); };
};
class Root{
private:
	//classSector-класс участка от 1 до 5
	int classSector=5;
	//номер вершины типа root
	int numApex = 0;
	//вектор смежных вершин типа EdgeApex
	vector<EdgeApex> Edge;
	//метод установки номера вершины типа root, в аргумент передается номер вершины
	void RootSetNumRoot(int);
	//метод получения номера вершины типа root
	int RootGetNumRoot();
	//метод получения вектора смежных root'ов 
	vector<EdgeApex> RootGetVectorEdge();
	//метод полуения смежной вершины типа EdgeApex у root'а по индексу
	EdgeApex RootGetEdgeApex(int);
	//метод добавления смежной вершны типа EdgeApex
	void RootPush(EdgeApex);
	//метод очистки root
	void RootClear();
public:
	void SetNumRoot(int num) { RootSetNumRoot(num); };
	int GetNumRoot() { return RootGetNumRoot(); };
	vector<EdgeApex> GetVectorEdge() { return RootGetVectorEdge(); };
	EdgeApex GetEdgeApex(int index) { return RootGetEdgeApex(index); }
	void Push(EdgeApex edge) { RootPush(edge); };
	void Clear() { RootClear(); };
};
class Scan {
private:
	vector<Root> scan;
	//метод добавления вершины типа root в Развертку
	void ScanPush(Root);
	//вывод Развертки в консоль
	void ScanPrint(vector<Root>);
	//метод получения вершины типа root по номеру вершины
	Root ScanGetRootByNum(int);
	//метод проверки существования запрашиваемой вершины
	bool ScanCheckRootByNum(int);
	//инициализация Развертки на основе графа
	vector<Root> ScanInitialization(Graph&);
public:
	vector<Root> Initialization(Graph& graph) { return ScanInitialization(graph); };
	void Push(Root root) { ScanPush(root); };
	void Print() { ScanPrint(scan); };
	Root GetRootByNum(int num) { return ScanGetRootByNum(num); };
	bool CheckRootByNum(int numRoot) { return ScanCheckRootByNum(numRoot); };
	Root GetRootByIndex(int num) { return scan[num]; };
	int GetSizeScan() { return this->scan.size(); };
	Scan() { this->scan; };
};