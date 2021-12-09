#include "modifiedLeeAlgorithm.h"

//проверка построенной GTN нахождения в зоне запрета
bool CheckLimit(GTN* gtn, Edge e) {
	for (int i = 0; i < e.GetLimit().size(); i++)
	{
		if (
			(gtn->GetTime() >= e.GetLimitbyIndex(i).GetTactBegin() && gtn->GetTime() <= e.GetLimitbyIndex(i).GetTactEnd())
			)
		{
			return true;//gtn находится в запретной зоне
		}
	}
	return false;//gtn не находится в запретной зоне
};


GTN ModifiedLeeAlgoritm::SearchPath(Edge* beg, Edge* end, int tactBeg, int tactEnd) {
	queue<GTN*> q;
	q.push(new GTN(*beg, 0, tactBeg));
	q.front()->SetStatusGTN("start");
	int count = 0;//счетчик взятых из очереди GTN
	int countq = 0;//счетчик всех построенных и добавленных в очередь GTN
	while (!q.empty())
	{
		count += 1;
		GTN* currentQueueItem = q.front();
		q.pop();//удаляем первую GTN из очереди
		try
		{
			//если вышли за рамки ограничения по времени и путь не найден, дальше искать маршрут не имеет смысла
			if (currentQueueItem->GetTime()>tactEnd && tactEnd!=-1){
				throw exception("Ошибка: искомого пути не существует!");
			}
			else
			{
				//если взятая из очереди GTN-искомая точка в пространстве/времени то запоминаем маршрут во времени и  выход
				if ((currentQueueItem->GetEdge() == *end) &&
					(tactEnd == -1 || currentQueueItem->GetTime() == tactEnd))
				{
					vector<int> numEdge;

					cout << "кол-во просмотренных node типа GTN в очереди: " << count << endl;
					cout << "кол-во записанных node типа GTN в очередь: " << countq << endl;
					//-------------- Устанавливаем лимит на посещение ребер в определеных тактах по ходу маршрута-------------------//
					GTN res = *currentQueueItem;
					while (res.GetPrev() != nullptr) {
						numEdge.push_back(res.GetEdge().GetEnd());
						res = *res.GetPrev();
					}
					numEdge.push_back(res.GetEdge().GetEnd());
					Edge* e = beg;
					for (int i = numEdge.size() - 1; i >= 0; i--)
					{
						if (numEdge[i] == e->GetEnd())
						{
							e->AdLimit(tactBeg + numEdge.size() - 1 - i, tactBeg + numEdge.size() - 1 - i);
						}
						else {
							for (int m = 0; m < e->GetNext().size(); m++)
							{
								if (numEdge[i] == e->GetNext()[m]->GetEnd())
								{
									e = e->GetNext()[m];
									e->AdLimit(tactBeg + numEdge.size() - 1 - i, tactBeg + numEdge.size() - 1 - i);
								}

							}
						}
					}
					//-------------------//
					currentQueueItem->SetStatusGTN("finish");
					return *currentQueueItem;
				}
				//если взятая из очереди GTN-искомая, но такт времени не удовлетворяет условиям останова, 
				//ничего не делаем с этой GTN и выполняем следующею итерацию, так как в очереди еще есть GTN 
				else if((currentQueueItem->GetEdge() == *end) && currentQueueItem->GetTime() < tactEnd && tactEnd!=-1) {		
					continue;
				}
				//если взятая из очереди GTN- не искомая точка, то формируем соседние GTN и записываем в очередь
				else {
					for (GTN* n : currGTN.Next(currentQueueItem))
					{
						if (!(CheckLimit(n, n->GetEdge())))
						{
							q.push(n);
							countq += 1;
						}

					}
					//обязательно формируем и записываем GTN аналогичную текущей, но с тактом времени t+1
					GTN* gtn = new GTN(currentQueueItem->GetEdge(), currentQueueItem->GetPlace(), currentQueueItem->GetTime() + 1, currentQueueItem);
					gtn->SetStatusGTN("wait");
					q.push(gtn);
					countq += 1;
				}
			}
		
		}
		catch (const std::exception& message)
		{
			cout << message.what() <<  "Начальная вершина:"<<endl;
			return GTN(*beg, 0, tactBeg, nullptr,"stop");
		}


		
		
	}
}