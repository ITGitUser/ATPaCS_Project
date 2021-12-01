#include "nextNodeAlgorithm.h"

vector<GTN*> NextNodeAlgorithm::Next(GTN* node) {
	int nextTact = node->GetTime()+1;
	int tact = 1; //1 ���
	vector<GTN*> nodes;
	//int s = speed * tact;
	//�������� ���������� ���������, ���� � ��������� ���� �� �������� � ��� �� �����, ��..., �����...
	if (node->GetPlace()+speed < node->GetEdge().GetDistance())
	{
		
		nodes.push_back(new GTN(node->GetEdge(), node->GetPlace() + speed, nextTact, node));
		return nodes;
	}
	else {
		double rest = node->GetEdge().GetDistance() - node->GetPlace(); //������� ����
		double time = 1 - rest / this->speed;
		int way = node->GetEdge().GetNext().size();
		
		for (int i = 0; i < way; i++)
		{
			Edge edge = *node->GetEdge().GetNext()[i];
			nodes.push_back(new GTN(edge, time * speed, nextTact, node));
		}
		return nodes;
	}
}