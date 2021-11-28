#pragma once
#include "graph.h"
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include <queue>
using namespace std;
class DijkstraAlgoritm {
private:
	NextNodeAlgorithm currGTN;
public:
	//возвращает конечную GTN
	GTN SearchPath(Edge beg, Edge end) {
		queue<GTN*> q;
		q.push(new GTN(beg, 0, 0));
		int count = 0;
		int countnode = 0;
		while (!q.empty())
		{
			count += 1;
			GTN *currentQueueItem = q.front();
			
			if (currentQueueItem->GetEdge() == end)
			{
				cout << "кол-во просмотренных node типа GTN в очереди: " << count << endl;
				cout << "кол-во записанных node типа GTN в очередь: " << countnode << endl;
					return *currentQueueItem;
			}

			for (GTN *n: currGTN.Next(currentQueueItem))
			{
				
				// если GTN не попадает в запретную зону то сохраняем
				if (n->GetTime() < n->GetEdge().GetBeginTactLimit() || n->GetTime() > n->GetEdge().GetEndTactLimit()) {
					q.push(n);
					countnode += 1;
				}
				
			}
			
			GTN* gtn = new GTN(currentQueueItem->GetEdge(), currentQueueItem->GetPlace(), currentQueueItem->GetTime() + 1, currentQueueItem);
			gtn->SetStatusGTN("wait");
			q.push(gtn);
			
			q.pop();
		}
	};
	DijkstraAlgoritm(NextNodeAlgorithm node) { this->currGTN = node; };
};