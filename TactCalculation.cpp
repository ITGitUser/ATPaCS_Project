#include <iostream>
#include "tactCalculation.h"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

//-------EdgeApex--------//
//����� ��������� ������ ������� �������
void EdgeApex::EdgeApexSetNumApex(int number) {
	this->numApex = number;
}
//���� ��������� ������ ������� ������
int EdgeApex::EdgeApexGetNumApex() {
	return this->numApex;
}
//����� ��������� ����������� ���-�� ����� �� ������� ������(������� �����������)
void EdgeApex::EdgeApexSetMinTact(int tact) {
	this->minTact = tact;
}
//���� ��������� ����������� ���-�� ����� �� ������� ������(������� �����������)
int EdgeApex::EdgeApexGetMinTact() {
	return this->minTact;
}
//����� ��������� ����������� ���� ���� Path �� ������� � ������� path
Path EdgeApex::EdgeApexGetPath(int index) {
	return this->path[index];
}
//����� ��������� ������� ���� ���� Path
vector<Path> EdgeApex::EdgeApexGetVectorPath() {
	return this->path;
}
//����� ���������� ���� ���� Path � ������ path
void EdgeApex::EdgeApexPushPathInVector(Path path) {
	this->path.push_back(path);

}
//����� ������� ������� �������
void EdgeApex::EdgeApexClear() {
	this->path.clear();
	int numApex = -1;
	int minTact = -1;
}
//---------Root--------//
//����� ��������� ������ ������� ���� root, � �������� ���������� ����� �������
void Root::RootSetNumRoot(int number) {
	this->numApex = number;
}
//����� ��������� ������ ������� ���� root
int Root::RootGetNumRoot() {
	return this->numApex;
}
//����� ��������� ������� ������� root'�� 
vector<EdgeApex> Root::RootGetVectorEdge() {
	return this->Edge;
}
//����� �������� ������� ������� ���� EdgeApex � root'� �� �������
EdgeApex Root::RootGetEdgeApex(int index) {
	return this->Edge[index];
}
//����� ���������� ������� ������ ���� EdgeApex
void Root::RootPush(EdgeApex edge) {
	this->Edge.push_back(edge);
}
//����� ������� root
void Root::RootClear() {
	this->Edge.clear();
}
//--------Scan--------//
//����� ���������� ������� ���� root � TactCalculation
void TactCalculation::TactCalculationPush(Root root) {
	this->tactCalculation.push_back(root);
}
//����� ��������� � �������
void TactCalculation::TactCalculationPrint(vector<Root> tactCalculation) {
	cout << "__________________________" << endl;
	cout << "TactCulculation:" << endl;
	for (Root n : tactCalculation) {
		//-----������� ������ ������ �����-----//
		cout << "������� (" << n.GetNumRoot() << ") :"; //����� �������-root
		for (int g = 0; g < n.GetVectorEdge().size(); g++) {
			cout << endl << "���������: " << n.GetEdgeApex(g).GetNumApex() << " �����: " << n.GetEdgeApex(g).GetMinTact();//����� ������� ������� � ����� ������
			for (int k = 0; k < n.GetEdgeApex(g).GetVectorPath().size(); k++) {//������� �������
				cout << "(" << n.GetEdgeApex(g).GetPath(k).direction << " ";
				cout << n.GetEdgeApex(g).GetPath(k).position << " ";
				cout << n.GetEdgeApex(g).GetPath(k).tact << ")";
			}
		}
		cout << endl;
	}
}
//����� ��������� ������� ���� root �� ������ �������
Root TactCalculation::TactCalculationGetRootByNum(int num) {
	bool label = false;
	for (int i = 0; i < this->tactCalculation.size(); i++)
	{
		if (tactCalculation[i].GetNumRoot() == num) {
			label = true;
			return tactCalculation[i];
		}

	}
	if (!label) {
		cout << "///////////Error-TactCalculation(TactCalculationGetRootByNum)///////////: ������� � �������: " << num << " �� ����������! " << this->tactCalculation.size() << endl;
	}
}
//����� �������� ������������� ������������� �������
bool TactCalculation::TactCalculationCheckRootByNum(int n) {
	bool label = false;
	for (int i = 0; i < this->tactCalculation.size(); i++)
	{
		if (tactCalculation[i].GetNumRoot() == n) {
			label = true;
			return label;
		}

	}
	if (!label && n != -1) {
		cout << endl << "///////////Error-TactCalculation(TactCalculationCheckRootByNum)///////////: ������� � �������: " << n << " �� ����������! " << endl << endl;
		return label;
	}
}
//������������� ��������� �� ������ �����
vector<Root> TactCalculation::TactCalculationInitialization(Graph& graph) {
	Root currentRoot;
	EdgeApex edgeApex;
	Path currentPath;
	int position = 0;
	int tact = 0;
	int tactTime = 60;
	for (int i = 0; i < graph.checkQuantityApex(); i++) {//���������� �������
		currentRoot.SetNumRoot(graph.GetApexByIndex(i).numApex);//���������� ����� �������
		for (int k = 0; k < graph.GetApexByIndex(i).edge.size(); k++) {//���������� ������� �������
			edgeApex.SetNumApex(graph.GetApexByIndex(i).edge[k]);//���������� ����� ������� �������
			while (position != 100) {
				tact = tact + 1;
				currentPath.direction = graph.GetApexByIndex(i).edge[k];// ���������� �����������
				//������� ������� ����������� ���� � ���������� � ���� �� 0 �� 100
				position = (graph.GetApexByIndex(i).maxspeed[k] * tact * 100000) / (tactTime * graph.GetApexByIndex(i).length[k]);
				if (position >= 100) {
					position = 100;
				}
				currentPath.position = position; //���������� ���������� �������
				currentPath.tact = tact;// ���������� ���� �������
				edgeApex.PushPathInVector(currentPath);//���������� ������� � ������
			}
			edgeApex.SetMinTact(tact);//���������� �������� ����
			//�������� ����� � �������� � ��������� ����������
			tact = 0;
			position = 0;
			currentRoot.Push(edgeApex);//���������� ����������� ���� ��� ������� �������
			edgeApex.Clear();
		}
		this->Push(currentRoot);
		currentRoot.Clear();

	}
	return tactCalculation;
}