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
		while (!q.empty())
		{
			GTN *currentQueueItem = q.front();
			
			if (currentQueueItem->GetEdge() == end)
			{
					return *currentQueueItem;
				
				
			}
			for (GTN *n: currGTN.Next(currentQueueItem))
			{
				q.push(n);
			}
			q.pop();
		}
	};
	DijkstraAlgoritm(NextNodeAlgorithm node) { this->currGTN = node; };
};