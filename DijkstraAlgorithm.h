#pragma once
#include "graph.h"
#include "scanGraph.h"
#include "list.h"
using namespace std;
struct Track{
	int begin;
	int end;
	vector<int> track;
	int tact;
};

class DijkstraAlgoritm {
private:
	//искомый маршрут
	Track track;
	//вывод маршрута в консоль
	void Print();
	//построение маршрута на основе полученного списка в методе поиска маршрута
	void DijkstraAlgoritmBuildTrack(List, int);
	//Поиск маршрута, алгоритмически выглядит как составление списка вершин и установки минимальных тактов из запрашивааемой вершины
	void DijkstraAlgoritmSearchTrack(TactCalculation&, int, int);
public:
	void SearchTrack(TactCalculation& scan, int begin, int end) { return DijkstraAlgoritmSearchTrack(scan, begin, end); };
	void PushTrack(int num) { track.track.push_back(num); };
	void SetBeginTrack(int num) { track.begin = num; };
	void SetEndTrack(int num) { track.end = num; };
	void SetTactTrack(int num) { track.tact = num; };
	void PrintTrack() { Print(); }
	void BuildTrack(List list, int num) { DijkstraAlgoritmBuildTrack(list, num); };
	Track GetTrack() { return track; };
};