#pragma once
#include "graph.h"
using namespace std;
//path-�������� ������� � ����������� �� �������
//root-������ ��������������� ��������, �������� ������ �����
//scan-���������, ������������ ��������������� �����
struct Path {
	int direction = 0; //�����������, �.�. ���� �� ������� ������, � ������� ������� �������
	int position = 0; //�� 0 �� 100
	int tact = 0;
};
class EdgeApex {
private:
	//����� ������� �������
	int numApex = -1;
	//���������� ���������� ������ ��������� �� ���������� ������� �������
	int minTact=-1;
	//���� ��������� �� ������� �����������, �������� �� ����, � ����� ������
	vector<Path> path;
	//����� ��������� ������ ������� �������
	void EdgeApexSetNumApex(int);
	//���� ��������� ������ ������� ������
	int EdgeApexGetNumApex();
	//����� ��������� ����������� ���-�� ����� �� ������� ������(������� �����������)
	void EdgeApexSetMinTact(int);
	//���� ��������� ����������� ���-�� ����� �� ������� ������(������� �����������)
	int EdgeApexGetMinTact();
	//����� ��������� ����������� ���� ���� Path �� ������� � ������� path
	Path EdgeApexGetPath(int);
	//����� ��������� ������� ���� ���� Path
	vector<Path> EdgeApexGetVectorPath();
	//����� ���������� ���� ���� Path � ������ path
	void EdgeApexPushPathInVector(Path);
	//����� ������� ������� �������
	void EdgeApexClear();
public:
	void SetNumApex(int num) { EdgeApexSetNumApex(num); };
	int GetNumApex() { return EdgeApexGetNumApex(); };
	void SetMinTact(int tact) { EdgeApexSetMinTact(tact); };
	int GetMinTact() { return EdgeApexGetMinTact(); };
	Path GetPath(int index) { return EdgeApexGetPath(index); };
	vector<Path> GetVectorPath() { return EdgeApexGetVectorPath(); };
	void PushPathInVector(Path path) { EdgeApexPushPathInVector(path); };
	void Clear() { EdgeApexClear(); };
};
class Root{
private:
	//classSector-����� ������� �� 1 �� 5
	int classSector=5;
	//����� ������� ���� root
	int numApex = 0;
	//������ ������� ������ ���� EdgeApex
	vector<EdgeApex> Edge;
	//����� ��������� ������ ������� ���� root, � �������� ���������� ����� �������
	void RootSetNumRoot(int);
	//����� ��������� ������ ������� ���� root
	int RootGetNumRoot();
	//����� ��������� ������� ������� root'�� 
	vector<EdgeApex> RootGetVectorEdge();
	//����� �������� ������� ������� ���� EdgeApex � root'� �� �������
	EdgeApex RootGetEdgeApex(int);
	//����� ���������� ������� ������ ���� EdgeApex
	void RootPush(EdgeApex);
	//����� ������� root
	void RootClear();
public:
	void SetNumRoot(int num) { RootSetNumRoot(num); };
	int GetNumRoot() { return RootGetNumRoot(); };
	vector<EdgeApex> GetVectorEdge() { return RootGetVectorEdge(); };
	EdgeApex GetEdgeApex(int index) { return RootGetEdgeApex(index); }
	void Push(EdgeApex edge) { RootPush(edge); };
	void Clear() { RootClear(); };
};
class Scan {
private:
	vector<Root> scan;
	//����� ���������� ������� ���� root � ���������
	void ScanPush(Root);
	//����� ��������� � �������
	void ScanPrint(vector<Root>);
	//����� ��������� ������� ���� root �� ������ �������
	Root ScanGetRootByNum(int);
	//����� �������� ������������� ������������� �������
	bool ScanCheckRootByNum(int);
	//������������� ��������� �� ������ �����
	vector<Root> ScanInitialization(Graph&);
public:
	vector<Root> Initialization(Graph& graph) { return ScanInitialization(graph); };
	void Push(Root root) { ScanPush(root); };
	void Print() { ScanPrint(scan); };
	Root GetRootByNum(int num) { return ScanGetRootByNum(num); };
	bool CheckRootByNum(int numRoot) { return ScanCheckRootByNum(numRoot); };
	Root GetRootByIndex(int num) { return scan[num]; };
	int GetSizeScan() { return this->scan.size(); };
	Scan() { this->scan; };
};