#include <iostream>
#include "DijkstraAlgorithm.h"
#include <string>
#include <vector>
#include <iterator>

using namespace std;
//вывод маршрута в консоль
void DijkstraAlgoritm::Print() {
	cout << "__________________________" << endl;
	cout << "ћаршрут " << this->GetTrack().begin << "-->" << this->GetTrack().end << " будет пройден за " << this->GetTrack().tact << " тактов" << endl;
	cout << "полный маршрут: ";
	for (int i = 0; i < this->GetTrack().track.size(); i++)
	{
		if (i != this->GetTrack().track.size() - 1) { cout << this->GetTrack().track[i] << "-->"; }
		else { cout << this->GetTrack().track[i] << endl; }
	}
}
//построение маршрута на основе полученного списка в методе поиска маршрута
void DijkstraAlgoritm::DijkstraAlgoritmBuildTrack(List list, int num) {
	//≈сли номер начальной вершины не совпадает со св€зью текщей вершиной, то повтор€ем рекурсивно
	if ((list.GetNodeByNum(num).edgeNode!= this->GetTrack().begin)&&num>=0&& list.GetNodeByNum(num).edgeNode != num )
	{	
		DijkstraAlgoritmBuildTrack(list, list.GetNodeByNum(num).edgeNode);
	}
	PushTrack(num);
}
//установка меток смежным вершинам
List SetLabelWeightInStepByEdge(TactCalculation& tactCalculation, List& currentList, int numRoot) {
	//провер€ем что вершина существует и не отрицательна
	if (tactCalculation.CheckRootByNum(numRoot)&&numRoot >= 0)
	{
	//провер€ем выбранную вершину посещалась она или нет
	if (!currentList.GetLabelVisited(numRoot))
	{
		//устанавливаем флаг посещени€
		currentList.SetLabelVisited(numRoot, true);
		//
		for (int i = 0; i < tactCalculation.GetRootByNum(numRoot).GetVectorEdge().size(); i++)
		{
			//провер€ем смежную вершину, посещалась она или нет
			if (!currentList.GetLabelVisited(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
				//считаем метку веса
				
				int minTact = tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetMinTact() + currentList.GetMinTact(numRoot);
					//сравниваем посчитаный вес с текущим весом смежного root
				if (minTact <= currentList.GetMinTact(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
					//устанавливаем новый вес, если новый вес меньше текущего
					currentList.SetMinTact(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), minTact);
					currentList.SetEdge(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), numRoot);
				}
			}
		}
		//рекурсивно вызываем эту же функцию
		
			SetLabelWeightInStepByEdge(tactCalculation, currentList, currentList.GetNumEdgeApexWithMinTactAndNotVisited(tactCalculation, numRoot));
		}
		
	}
	return currentList;
}
//ѕоиск маршрута, алгоритмически выгл€дит как составление списка вершин и установки минимальных тактов из запрашивааемой вершины
void DijkstraAlgoritm::DijkstraAlgoritmSearchTrack(TactCalculation& tactCalculation, int begin, int end) {
	//проверка существовани€ запрашиваемых вершин
	if (tactCalculation.CheckRootByNum(begin)&& tactCalculation.CheckRootByNum(end))
	{
		//создаем список дл€ хранени€ информации о возможных маршрутах(трэках)
		List currentList;
		for (int i = 0; i < tactCalculation.GetSizeScan(); i++)
		{
			currentList.PushNode(tactCalculation.GetRootByIndex(i).GetNumRoot());
		}
		//создаем контейнер дл€ целевого маршрута
		/////////////////////////////////////////
		SetBeginTrack(begin);
		SetEndTrack(end);
		//ƒобавл€ем в искомый маршрут начальную вершину
		PushTrack(begin);
		//устанавливаем метку начальной вершине равную 0
		currentList.SetMinTact(begin,0);
		currentList.SetEdge(begin, begin);
		SetLabelWeightInStepByEdge(tactCalculation, currentList, begin);
		currentList.PrintList();
		//SetTactTrack(scan.GetRootByNum(end).GetLabelWeight());
		BuildTrack(currentList, end);
		SetTactTrack(currentList.GetNodeByNum(end).minTact);
		Print();
	}
	else {
		if (!tactCalculation.CheckRootByNum(begin))
		{
			//ERROR-Ќачальна€ вершина не существует в текущей развертке
			cout << "Ќачальна€ вершина не существует в текущей развертке" << endl;
		}
		else if(!tactCalculation.CheckRootByNum(end)){
			//ERROR- онечна€ вершина не существует в текущей развертке
			cout << " онечна€ вершина не существует в текущей развертке" << endl;
		}
	}
}