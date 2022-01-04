#include "routeManager.h"

bool CheckLimitTact(int tact, Edge e) {
	for (int i = 0; i < e.GetLimit().size(); i++)
	{
		if (
			(tact >= e.GetLimitbyIndex(i).GetTactBegin() && tact <= e.GetLimitbyIndex(i).GetTactEnd())
			)
		{
			return true;//tact находится в запретной зоне
		}
	}
	return false;//tact не находится в запретной зоне
};


void RouteManager::AddRoute(int type, Edge* beg, Edge* end, int tactBeg, int tactEnd) {
	bool flagNewTry = true;
	int tryCount = 1;
	while (flagNewTry) {
		cout << "Попытка №"<<tryCount << endl;
		//проверка нахождения начального такта в зоне запрета, сдвигает начальный такт до момента когда маршрут станет возможно построить
		while (CheckLimitTact(tactBeg, *beg) || tactBeg < tactEnd) {
			tactBeg += 1;
		}
		//если начальный такт сдвинули и это не перекрыло конечный такт, попробуем построить маршрут
		if ((tactEnd != -1 && tactBeg < tactEnd) || (tactEnd == -1)) {
			GTN* res = finder.SearchWay(beg, end, tactBeg, tactEnd);
			if (res->GetStatusGTN() != "stop") {
				this->allRoute.push_back(new Route(SetNumRoute(), type, beg, tactBeg, tactEnd, res, res->GetBegin()));
				res->PrintPath();
				flagNewTry = false;
			}
			else {
				tactBeg += 1;
				tryCount += 1;
			}
		}
		else if(tactEnd != -1 && tactBeg >= tactEnd){
			cout << "Ошибка: Маршрут в заданные временные рамки не возможен" << endl;
			break;
		}
		
	}
	
}

void RouteManager::DeleteRoute(int numR){
	makeTransparentRoute(numR);
	//delete findRoute(numR);
	for (int i = 0; i < this->allRoute.size(); i++) {
		if (allRoute[i]->GetNumRoute() == numR) {
			allRoute.erase(allRoute.begin() + i);
		}
	}
}
void RouteManager::makeTransparentRoute(int numR) {
	vector<int> numEdge;
	int tactBeg = findRoute(numR)->GetTactBegin();
	GTN res = *findRoute(numR)->GetEndPoint();
	while (res.GetPrev() != nullptr) {
		numEdge.push_back(res.GetEdge().GetEnd());
		res = *res.GetPrev();
	}
	numEdge.push_back(res.GetEdge().GetEnd());
	
	Edge* e = findRoute(numR)->GetBeginEdge();
	for (int i = numEdge.size() - 1; i >= 0; i--)
	{
		if (numEdge[i] == e->GetEnd())
		{
			e->DeleteLimit(tactBeg + numEdge.size() - 1 - i);
		}
		else {
			for (int m = 0; m < e->GetNext().size(); m++)
			{
				if (numEdge[i] == e->GetNext()[m]->GetEnd())
				{
					e = e->GetNext()[m];
					e->DeleteLimit(tactBeg + numEdge.size() - 1 - i);
				}

			}
		}
	}
	
}

Route* RouteManager::findRoute(int numR) {
	for (Route *n : this->allRoute) {
		if (n->GetNumRoute() == numR) {
			return n;
		}
	}
	//обработка ошибки следует реализовать...
}