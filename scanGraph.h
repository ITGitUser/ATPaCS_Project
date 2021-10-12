#pragma once

#include "graph.h"
using namespace std;
//path-�������� ������� � ����������� �� �������
//root-������ ��������������� ��������, �������� ������ �����
//scan-���������, ������������ ��������������� �����
class TactPosition {
private:
	int numberTrack = 0000;
	int direction = 0; //�����������, �.�. ���� �� ������� ������, � ������� ������� �������
	int position = 0; //�� 0 �� 100
	int tact = 0;
	bool labelfree = true;//����� ����������� �����, true-������������ �����, ���� �������� 
	//void TactPositionSetLabelFree(bool label) {  };
public:
	void SetNumberTrack(int number) { numberTrack = number; };
	void SetDirection(int dir) { direction = dir; };
	void SetPosition(int pos) { position = pos; };
	void SetTact(int t) { tact = t; };
	void SetLabelFree(bool label) { this->labelfree = label; };
	int GetNumberTrack() { return numberTrack; };
	int GetDirection() { return direction; };
	int GetPosition() { return position; };
	int GetTact() { return tact; };
	bool GetLabelFree() { return labelfree; };
};
class EdgeApexScan {
private:
	//����� ������� �������
	int numApex = -1;
	//��������� ��������� �������� ���� TactPosition
	vector<TactPosition> tactPosition;
	//����� ��������� ������ ������� �������
	void EdgeApexScanSetNumApex(int);
	//����� ��������� ������ ������� ������
	int EdgeApexScanGetNumApex();
	//����� ��������� ����������� TactPosition �� ������� � ������� tactPosition
	TactPosition& EdgeApexScanGetTactPosition(int);
	//����� ���������� ��������� ���� TactPosition � ������ tactPosition
	void EdgeApexScanPushPathInVector(TactPosition);
	//����� ��������� ������� ������ ���� TactPosition
	vector<TactPosition> EdgeApexScanGetVectorPath();
	//����� ������� ������� �������
	void EdgeApexScanClear();
public:
	void SetNumApex(int num) { EdgeApexScanSetNumApex(num); };
	int GetNumApex() { return EdgeApexScanGetNumApex(); };
	TactPosition& GetTactPosition(int index) { return this->EdgeApexScanGetTactPosition(index); };
	void PushPathInVector(TactPosition tactPosition) { EdgeApexScanPushPathInVector(tactPosition); };
	vector<TactPosition> GetVectorPath() { return EdgeApexScanGetVectorPath(); };
	void Clear() { EdgeApexScanClear(); };
};
class RootScan{
private:
	//classSector-����� ������� �� 1 �� 5
	int classSector=5;
	//����� ������� ���� rootScan
	int numApex = 0;
	//������ ������� ������ ���� EdgeApexScan
	vector<EdgeApexScan> Edge;
	//����� ��������� ������ ������� ���� rootScan, � �������� ���������� ����� �������
	void RootScanSetNumRoot(int);
	//����� ��������� ������ ������� ���� rootScan
	int RootScanGetNumRoot();
	//����� ��������� ������� ������� root'�� 
	vector<EdgeApexScan>& RootScanGetVectorEdge();
	//����� ��������� ������� ������� ���� EdgeApexScan � root'� �� �������
	EdgeApexScan RootScanGetEdgeApex(int);
	//����� ���������� ������� ������ ���� EdgeApex
	void RootScanPush(EdgeApexScan);
	//����� ������� rootScan
	void RootScanClear();
public:
	void SetNumRoot(int num) { RootScanSetNumRoot(num); };
	int GetNumRoot() { return RootScanGetNumRoot(); };
	vector<EdgeApexScan>& GetVectorEdge() { return this->RootScanGetVectorEdge(); };
	EdgeApexScan GetEdgeApex(int index) { return RootScanGetEdgeApex(index); }
	void Push(EdgeApexScan edge) { RootScanPush(edge); };
	void Clear() { RootScanClear(); };
};
class Scan {
private:
	const int tact = 15;//��������� ���������� ������ ��� ���������
	vector<RootScan> scan;
	//����� ���������� ������� ���� rootScan � ���������
	void ScanPush(RootScan);
	//����� ��������� � �������
	void ScanPrint(vector<RootScan>);
	//����� ��������� ������� ���� rootScan �� ������ �������
	RootScan& ScanGetRootByNum(int);
	//������������� ��������� �� ������ �����
	vector<RootScan> ScanInitialization(Graph&);
	//��������� �����������	
	void ScanSetBarrier(int, int, int, int, int);
	int ScanGetTact() { return tact; };
public:
	vector<RootScan> Initialization(Graph& graph) { return ScanInitialization(graph); };
	void Push(RootScan root) { ScanPush(root); };
	void Print() { ScanPrint(scan); };
	RootScan& GetRootByNum(int num) { return this->ScanGetRootByNum(num); };
	RootScan& GetRootByIndex(int num) { return this->scan[num]; };
	int GetSizeScan() { return this->scan.size(); };
	void SetBarrier(int tactBegin, int tactEnd, int position, int positionDirection, int type) { ScanSetBarrier(tactBegin, tactEnd, position, positionDirection, type); };
	Scan() { this->scan; };
};
