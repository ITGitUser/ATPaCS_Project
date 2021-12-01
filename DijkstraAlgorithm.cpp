#include "DijkstraAlgorithm.h"
#include "restrictedArea.h"
//#include "graph.h"
#include <iostream>

bool CheckLimit(GTN* gtn, Edge e) {
	for (int i = 0; i < e.GetLimit().size(); i++)
	{
		if (
			(gtn->GetTime() >= e.GetLimitbyIndex(i).GetTactBegin() && gtn->GetTime() <= e.GetLimitbyIndex(i).GetTactEnd())
			)
		{
			return true;//gtn ��������� � ��������� ����
		}
	}
	return false;//gtn �� ��������� � ��������� ����
};


GTN DijkstraAlgoritm::SearchPath(Edge* beg, Edge* end, int tactBeg) {
	queue<GTN*> q;
	q.push(new GTN(*beg, 0, tactBeg));
	int count = 0;
	int countq = 0;
	while (!q.empty())
	{
		count += 1;
		GTN* currentQueueItem = q.front();

		if (currentQueueItem->GetEdge() == *end)
		{
			vector<int> numEdge;
			
			cout << "���-�� ������������� node ���� GTN � �������: " << count << endl;
			cout << "���-�� ���������� node ���� GTN � �������: " << countq << endl;
			//-------------- ������������� ����� �� ��������� ����� � ����������� ������ �� ���� ��������-------------------//
			GTN res = *currentQueueItem;
			while (res.GetPrev() != nullptr) {
				numEdge.push_back(res.GetEdge().GetEnd());
				res = *res.GetPrev();
			}
			numEdge.push_back(res.GetEdge().GetEnd());
			Edge* e=beg;
			for (int i = numEdge.size()-1; i >= 0; i--)
			{

				if (numEdge[i] == e->GetEnd())
				{
					e->AdLimit(tactBeg+numEdge.size() - 1-i, tactBeg+numEdge.size() - 1-i);
				}
				else {
					for (int m = 0; m < e->GetNext().size(); m++)
					{
						if (numEdge[i]== e->GetNext()[m]->GetEnd())
						{
							e = e->GetNext()[m];
							e->AdLimit(tactBeg+numEdge.size() - 1-i, tactBeg+numEdge.size() - 1-i);
						}

					}
				}
				
			}
			
			//-------------------//
			return *currentQueueItem;
		}

		for (GTN* n : currGTN.Next(currentQueueItem))
		{
			if (!(CheckLimit(n, n->GetEdge())))
			{
				q.push(n);
				countq += 1;
			}

		}

		GTN* gtn = new GTN(currentQueueItem->GetEdge(), currentQueueItem->GetPlace(), currentQueueItem->GetTime() + 1, currentQueueItem);
		gtn->SetStatusGTN("wait");
		q.push(gtn);
		countq += 1;

		q.pop();
	}
}









