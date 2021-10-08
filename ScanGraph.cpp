
#include <iostream>
#include "scanGraph.h"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

//-------EdgeApexScan--------//
//����� ��������� ������ ������� �������
void EdgeApexScan::EdgeApexScanSetNumApex(int number) {
	this->numApex = number;
}
//���� ��������� ������ ������� ������
int EdgeApexScan::EdgeApexScanGetNumApex() {
	return this->numApex;
}
//����� ��������� ����������� TactPosition �� ������� � ������� tactPosition
TactPosition EdgeApexScan::EdgeApexScanGetTactPosition(int index) {
	return this->tactPosition[index];
}
//����� ���������� ��������� ���� TactPosition � ������ tactPosition
void EdgeApexScan::EdgeApexScanPushPathInVector(TactPosition tactPosition) {
	this->tactPosition.push_back(tactPosition);

}
//����� ��������� ������� ������ ���� TactPosition
vector<TactPosition> EdgeApexScan::EdgeApexScanGetVectorPath() {
	return this->tactPosition;
}
//����� ������� ������� �������
void EdgeApexScan::EdgeApexScanClear() {
	this->tactPosition.clear();
	int numApex = -1;
	int minTact = -1;
}
//---------RootScan--------//
//����� ��������� ������ ������� ���� rootScan, � �������� ���������� ����� �������
void RootScan::RootScanSetNumRoot(int number) {
	this->numApex = number;
}
//����� ��������� ������ ������� ���� rootScan
int RootScan::RootScanGetNumRoot() {
	return this->numApex;
}
//����� ��������� ������� ������� root'�� 
vector<EdgeApexScan> RootScan::RootScanGetVectorEdge() {
	return this->Edge;
}
//����� ��������� ������� ������� ���� EdgeApexScan � root'� �� �������
EdgeApexScan RootScan::RootScanGetEdgeApex(int index) {
	return this->Edge[index];
}
//����� ���������� ������� ������ ���� EdgeApexScan
void RootScan::RootScanPush(EdgeApexScan edge) {
	this->Edge.push_back(edge);
}
//����� ������� rootScan
void RootScan::RootScanClear() {
	this->Edge.clear();
}
//--------Scan--------//
//����� ���������� ������� ���� rootScan � ���������
void Scan::ScanPush(RootScan root) {
	this->scan.push_back(root);
}
//����� ��������� � �������
void Scan::ScanPrint(vector<RootScan> scan) {
	cout << "__________________________" << endl;
	cout << "���������:" << endl;
	for (RootScan n : scan) {
		//-----������� ������ ������ �����-----//
		cout << "������� (" << n.GetNumRoot() << ") :"; //����� �������-root
		for (int g = 0; g < n.GetVectorEdge().size(); g++) {
			cout << endl << "���������: " << n.GetEdgeApex(g).GetNumApex();//����� ������� ������� � ����� ������
			for (int k = 0; k < n.GetEdgeApex(g).GetVectorPath().size(); k++) {//������� �������
				cout << "(" << n.GetEdgeApex(g).GetPath(k).numberTrack << " ";
				cout << n.GetEdgeApex(g).GetPath(k).direction << " ";
				cout << n.GetEdgeApex(g).GetPath(k).position << " ";
				cout << n.GetEdgeApex(g).GetPath(k).labelfree << " ";
				cout << n.GetEdgeApex(g).GetPath(k).tact << ")";
			}
		}
		cout << endl;
	}
}
//����� ��������� ������� ���� rootScan �� ������ �������
RootScan Scan::ScanGetRootByNum(int num) {
	bool label = false;
	for (int i = 0; i < this->scan.size(); i++)
	{
		if (scan[i].GetNumRoot() == num) {
			label = true;
			return scan[i];
		}
		
	}
	if (!label) {
		cout << "///////////Error-Scan(ScanGetRootByNum)///////////: ������� � �������: " << num << " �� ����������! " << this->scan.size() << endl;
	}
}

//������������� ��������� �� ������ �����
vector<RootScan> Scan::ScanInitialization(Graph& graph) {
	RootScan currentRootScan;
	EdgeApexScan edgeApexScan;
	TactPosition currentTactPosition;
	int const Tact = 15;//��������� ���������� ������ ��� ���������
	for (int i = 0; i < graph.checkQuantityApex(); i++) {//���������� �������
		currentRootScan.SetNumRoot(graph.GetApexByIndex(i).numApex);//���������� ����� �������
		for (int k = 0; k < graph.GetApexByIndex(i).edge.size(); k++) {//���������� ������� �������
			edgeApexScan.SetNumApex(graph.GetApexByIndex(i).edge[k]);//���������� ����� ������� �������
			for (int z = 0; z < Tact; z++)
			{
				currentTactPosition.direction = graph.GetApexByIndex(i).edge[k];
				currentTactPosition.tact = z;
				edgeApexScan.PushPathInVector(currentTactPosition);//���������� ������� � ������
			}
			//�������� ��������� ����������
			currentRootScan.Push(edgeApexScan);//���������� ��������� ��� ������� �������
			edgeApexScan.Clear();
		}
		this->Push(currentRootScan);
		currentRootScan.Clear();
		
	}
	return scan;
}
