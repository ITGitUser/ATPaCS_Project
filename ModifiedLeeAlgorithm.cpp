#include "modifiedLeeAlgorithm.h"

//�������� ����������� GTN ���������� � ���� �������
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


GTN* ModifiedLeeAlgoritm::SearchWay(Edge* beg, Edge* end, int tactBeg, int tactEnd) {
	queue<GTN*> q;
	q.push(new GTN(*beg, 0, tactBeg));
	q.front()->SetStatusGTN("start");
	int count = 0;//������� ������ �� ������� GTN
	int countq = 0;//������� ���� ����������� � ������� GTN
	int countn = 0;
		try
		{
			while (!q.empty())
			{
				count += 1;
				GTN* currentQueueItem = q.front();
				q.pop();//������� ������ GTN �� �������
				//���� ����� �� ����� ����������� �� ������� � ���� �� ������, ������ ������ ������� �� ����� ������
				if (currentQueueItem->GetTime() > tactEnd && tactEnd != -1) {
					throw exception("������: �������� ���� �� ����������! ����������� ��� �����");
				}
				else
				{
					//���� ������ �� ������� GTN-������� ����� � ������������/������� �� ���������� ������� �� ������� �  �����
					if ((currentQueueItem->GetEdge() == *end) &&
						(tactEnd == -1 || currentQueueItem->GetTime() == tactEnd))
					{
						vector<int> numEdge;

						cout << "���-�� ������������� node ���� GTN � �������: " << count << endl;
						cout << "���-�� ���� �������������� node ���� GTN: " << countn << endl;
						cout << "���-�� ���������� node ���� GTN � �������: " << countq << endl;
						//-------------- ������������� ����� �� ��������� ����� � ����������� ������ �� ���� ��������-------------------//
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
						return currentQueueItem;
					}
					//���� ������ �� ������� GTN-�������, �� ���� ������� �� ������������� �������� ��������, 
					//������ �� ������ � ���� GTN � ��������� ��������� ��������, ��� ��� � ������� ��� ���� GTN 
					else if ((currentQueueItem->GetEdge() == *end) && currentQueueItem->GetTime() < tactEnd && tactEnd != -1) {
						continue;
					}
					//���� ������ �� ������� GTN- �� ������� �����, �� ��������� �������� GTN � ���������� � �������
					else {
						for (GTN* n : currGTN.Next(currentQueueItem))
						{
							countn += 1;
							if (!(CheckLimit(n, n->GetEdge())))
							{
								q.push(n);
								countq += 1;
							}
						}
					}
				}
			}
			if (q.empty()) {
				throw exception("������: �������� ���� �� ����������! ����������� ��� GTN");
			}
		}
		catch (const std::exception& message)
		{
			cout << "���-�� ������������� node ���� GTN � �������: " << count << endl;
			cout << "���-�� ���� �������������� node ���� GTN: " << countn << endl;
			cout << "���-�� ���������� node ���� GTN � �������: " << countq << endl;
			cout << message.what() <<  " ��������� �������:"<<endl;
			return &GTN(*beg, 0, tactBeg, nullptr,"stop");
		}
}