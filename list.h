#pragma once
#include "scanGraph.h"
using namespace std;
struct Node {
	//����� �������
	int numNode=0;
	//���-�� ������
	int minTact = 10000000;//�� �� labelWeght 
	//����� ������� ���������
	int edgeNode=0;
	//���� ��������� �������
	bool visited = false;
};
class List {
private:
	vector<Node> list;
	//����� ���������� ���� � ������
	void ListPushNode(int);
	//���� ��������� ���-�� ������ � ������� � ������������� �������
	int ListGetMinTact(int);
	//����� ��������� ���� ������ �� ������ ����
	Node ListGetNodeByNum(int);
	//����� ��������� ����� ��������� ����
	bool ListGetLabelVisited(int);
	//����� ������ � �������
	void ListPrintList();
	//����� ��������� ���������, ������ �������� ����� ����, ������ ����� ���������
	void ListSetEdge(int, int);
	//����� ��������� ���-�� �����, ������ �������� ����� ����, ������ ���-�� ������
	void ListSetMinTact(int, int);
	//����� ��������� ����� ��������� ����
	void ListChangeLabelVisited(int, bool);
	//����� ��������� ������ ���� �� ����� ����
	int GetIndexNode(int);
	//����� ��������� ������ ������� ������� � ���������� ���-��� ������, � �������� �� ������������ �������
	int ListGetNumEdgeApexWithMinTactAndNotVisited(Scan, int);
public:
	void PushNode(int numNode) { ListPushNode(numNode); };
	int GetMinTact(int numNode) { return ListGetMinTact(numNode); };
	Node GetNodeByNum(int num) { return ListGetNodeByNum(num); };
	bool GetLabelVisited(int numNode) { return ListGetLabelVisited(numNode); };
	void  PrintList() { ListPrintList(); };
	void SetEdge(int num, int edge) { ListSetEdge(num, edge); };
	void SetMinTact(int num, int tact) { ListSetMinTact(num, tact); };
	void SetLabelVisited(int numNode, bool label) { ListChangeLabelVisited(numNode, label); };
	int GetSize() { return list.size(); };
	int GetNumEdgeApexWithMinTactAndNotVisited(Scan scan, int num) {
		return ListGetNumEdgeApexWithMinTactAndNotVisited(scan, num);
	};
	List() { this->list; };

};