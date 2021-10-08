#include <iostream>
#include "tactCalculation.h"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

//-------EdgeApex--------//
//метод установки номера смежной вершины
void EdgeApex::EdgeApexSetNumApex(int number) {
	this->numApex = number;
}
//меод получения номера смежной вершны
int EdgeApex::EdgeApexGetNumApex() {
	return this->numApex;
}
//метод установки наименьшего кол-во такта до смежной вершны(вершины направления)
void EdgeApex::EdgeApexSetMinTact(int tact) {
	this->minTact = tact;
}
//меод получения наименьшего кол-во такта до смежной вершны(вершины направления)
int EdgeApex::EdgeApexGetMinTact() {
	return this->minTact;
}
//метод получения конкретного пути типа Path по индексу в векторе path
Path EdgeApex::EdgeApexGetPath(int index) {
	return this->path[index];
}
//метод получения вектора пути типа Path
vector<Path> EdgeApex::EdgeApexGetVectorPath() {
	return this->path;
}
//метод добавления пути типа Path в вектор path
void EdgeApex::EdgeApexPushPathInVector(Path path) {
	this->path.push_back(path);

}
//метод очистки смежной вершины
void EdgeApex::EdgeApexClear() {
	this->path.clear();
	int numApex = -1;
	int minTact = -1;
}
//---------Root--------//
//метод установки номера вершины типа root, в аргумент передается номер вершины
void Root::RootSetNumRoot(int number) {
	this->numApex = number;
}
//метод получения номера вершины типа root
int Root::RootGetNumRoot() {
	return this->numApex;
}
//метод получения вектора смежных root'ов 
vector<EdgeApex> Root::RootGetVectorEdge() {
	return this->Edge;
}
//метод полуения смежной вершины типа EdgeApex у root'а по индексу
EdgeApex Root::RootGetEdgeApex(int index) {
	return this->Edge[index];
}
//метод добавления смежной вершны типа EdgeApex
void Root::RootPush(EdgeApex edge) {
	this->Edge.push_back(edge);
}
//метод очистки root
void Root::RootClear() {
	this->Edge.clear();
}
//--------Scan--------//
//метод добавления вершины типа root в TactCalculation
void TactCalculation::TactCalculationPush(Root root) {
	this->tactCalculation.push_back(root);
}
//вывод Развертки в консоль
void TactCalculation::TactCalculationPrint(vector<Root> tactCalculation) {
	cout << "__________________________" << endl;
	cout << "TactCulculation:" << endl;
	for (Root n : tactCalculation) {
		//-----Выводим номера вершин рутов-----//
		cout << "Вершина (" << n.GetNumRoot() << ") :"; //номер вершины-root
		for (int g = 0; g < n.GetVectorEdge().size(); g++) {
			cout << endl << "смежность: " << n.GetEdgeApex(g).GetNumApex() << " такты: " << n.GetEdgeApex(g).GetMinTact();//номер смежной вершины и число тактов
			for (int k = 0; k < n.GetEdgeApex(g).GetVectorPath().size(); k++) {//выводим позиции
				cout << "(" << n.GetEdgeApex(g).GetPath(k).direction << " ";
				cout << n.GetEdgeApex(g).GetPath(k).position << " ";
				cout << n.GetEdgeApex(g).GetPath(k).tact << ")";
			}
		}
		cout << endl;
	}
}
//метод получения вершины типа root по номеру вершины
Root TactCalculation::TactCalculationGetRootByNum(int num) {
	bool label = false;
	for (int i = 0; i < this->tactCalculation.size(); i++)
	{
		if (tactCalculation[i].GetNumRoot() == num) {
			label = true;
			return tactCalculation[i];
		}

	}
	if (!label) {
		cout << "///////////Error-TactCalculation(TactCalculationGetRootByNum)///////////: вершины с номером: " << num << " не существует! " << this->tactCalculation.size() << endl;
	}
}
//метод проверки существования запрашиваемой вершины
bool TactCalculation::TactCalculationCheckRootByNum(int n) {
	bool label = false;
	for (int i = 0; i < this->tactCalculation.size(); i++)
	{
		if (tactCalculation[i].GetNumRoot() == n) {
			label = true;
			return label;
		}

	}
	if (!label && n != -1) {
		cout << endl << "///////////Error-TactCalculation(TactCalculationCheckRootByNum)///////////: вершины с номером: " << n << " не существует! " << endl << endl;
		return label;
	}
}
//инициализация Развертки на основе графа
vector<Root> TactCalculation::TactCalculationInitialization(Graph& graph) {
	Root currentRoot;
	EdgeApex edgeApex;
	Path currentPath;
	int position = 0;
	int tact = 0;
	int tactTime = 60;
	for (int i = 0; i < graph.checkQuantityApex(); i++) {//перебираем вершины
		currentRoot.SetNumRoot(graph.GetApexByIndex(i).numApex);//записываем номер вершины
		for (int k = 0; k < graph.GetApexByIndex(i).edge.size(); k++) {//перебираем смежные вершины
			edgeApex.SetNumApex(graph.GetApexByIndex(i).edge[k]);//записываем номер смежной вершины
			while (position != 100) {
				tact = tact + 1;
				currentPath.direction = graph.GetApexByIndex(i).edge[k];// записываем направление
				//формула расчета пройденного пути и приведения к виду от 0 до 100
				position = (graph.GetApexByIndex(i).maxspeed[k] * tact * 100000) / (tactTime * graph.GetApexByIndex(i).length[k]);
				if (position >= 100) {
					position = 100;
				}
				currentPath.position = position; //записываем пройденную позицию
				currentPath.tact = tact;// записываем такт текущий
				edgeApex.PushPathInVector(currentPath);//записываем позицию в вектор
			}
			edgeApex.SetMinTact(tact);//записываем конечный такт
			//обнуляем флаги и счетчики и временные контейнеры
			tact = 0;
			position = 0;
			currentRoot.Push(edgeApex);//записываем посчитанный путь для смежной вершины
			edgeApex.Clear();
		}
		this->Push(currentRoot);
		currentRoot.Clear();

	}
	return tactCalculation;
}