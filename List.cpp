#include <iostream>
#include <vector>
#include "list.h"

using namespace std;
//-------------List-----------//
//����� ���������� ���� � ������
void List::ListPushNode(int numNode) {
	Node currentNode;
	currentNode.numNode = numNode;
	this->list.push_back(currentNode);
}
//���� ��������� ���-�� ������ � ������� � ������������� �������
int List::ListGetMinTact(int numNode) {
	return this->list[GetIndexNode(numNode)].minTact;
}
//����� ��������� ���� ������ �� ������ ����
Node List::ListGetNodeByNum(int num) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (list[i].numNode == num)
		{
			return list[i];
		}
	}
	//ERROR-���� � ������ �� ����������!
	cout << "//////////Error-List(ListGetNodeByNum)///////////: ���� � ������ �� ����������!" << endl;
}
//����� ��������� ����� ��������� ����
bool List::ListGetLabelVisited(int numNode) {
	return this->list[GetIndexNode(numNode)].visited;
	//����� ������ � �������
}
//����� ������ � �������
void List::ListPrintList() {
	cout << "__________________________" << endl;
	cout << "������ �����:" << endl;
	for (int i = 0; i < this->GetSize(); i++)
	{
		cout << "������� (" << list[i].numNode << ")" << " �����: " << list[i].minTact << " ��������: " << list[i].edgeNode << endl;

	}
}
//����� ��������� ���������, ������ �������� ����� ����, ������ ����� ���������
void List::ListSetEdge(int num, int edge) {
	this->list[GetIndexNode(num)].edgeNode = edge;
}
//����� ��������� ���-�� �����, ������ �������� ����� ����, ������ ���-�� ������
void List::ListSetMinTact(int num, int tact) {
	this->list[GetIndexNode(num)].minTact = tact;
}
//����� ��������� ����� ��������� ����
void List::ListChangeLabelVisited(int numNode, bool label) {
	this->list[GetIndexNode(numNode)].visited = label;
}
//����� ��������� ������ ���� �� ����� ����
int List::GetIndexNode(int numNode) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (list[i].numNode == numNode)
		{
			return i;
		}
	}
	//ERROR-���� � ������ �� ����������!
	cout << "///////////Error-List(GetIndexNode)///////////: ���� � ������ �� ����������!" << endl;
}
//����� ��������� ������ ������� ������� � ���������� ���-��� ������, � �������� �� ������������ �������
int List::ListGetNumEdgeApexWithMinTactAndNotVisited(Scan scan, int numApex) {
	int sizeVectorEdge = scan.GetRootByNum(numApex).GetVectorEdge().size();
	int minTact = 10000000;
	int num = -1;
	for (int i = 0; i < sizeVectorEdge; i++)
	{
		int tact = scan.GetRootByNum(numApex).GetEdgeApex(i).GetMinTact();

		if (!this->GetLabelVisited(scan.GetRootByNum(numApex).GetEdgeApex(i).GetNumApex()) && minTact > tact) {
			num = scan.GetRootByNum(scan.GetRootByNum(numApex).GetEdgeApex(i).GetNumApex()).GetNumRoot();
			minTact = tact;
		}
	}
	return num;
}

