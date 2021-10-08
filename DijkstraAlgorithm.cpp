#include <iostream>
#include "DijkstraAlgorithm.h"
#include <string>
#include <vector>
#include <iterator>

using namespace std;
//����� �������� � �������
void DijkstraAlgoritm::Print() {
	cout << "__________________________" << endl;
	cout << "������� " << this->GetTrack().begin << "-->" << this->GetTrack().end << " ����� ������� �� " << this->GetTrack().tact << " ������" << endl;
	cout << "������ �������: ";
	for (int i = 0; i < this->GetTrack().track.size(); i++)
	{
		if (i != this->GetTrack().track.size() - 1) { cout << this->GetTrack().track[i] << "-->"; }
		else { cout << this->GetTrack().track[i] << endl; }
	}
}
//���������� �������� �� ������ ����������� ������ � ������ ������ ��������
void DijkstraAlgoritm::DijkstraAlgoritmBuildTrack(List list, int num) {
	//���� ����� ��������� ������� �� ��������� �� ������ ������ ��������, �� ��������� ����������
	if ((list.GetNodeByNum(num).edgeNode!= this->GetTrack().begin)&&num>=0&& list.GetNodeByNum(num).edgeNode != num )
	{	
		DijkstraAlgoritmBuildTrack(list, list.GetNodeByNum(num).edgeNode);
	}
	PushTrack(num);
}
//��������� ����� ������� ��������
List SetLabelWeightInStepByEdge(Scan& scan, List& currentList, int numRoot) {
	//��������� ��� ������� ���������� � �� ������������
	if (scan.CheckRootByNum(numRoot)&&numRoot >= 0)
	{
	//��������� ��������� ������� ���������� ��� ��� ���
	if (!currentList.GetLabelVisited(numRoot))
	{
		//������������� ���� ���������
		currentList.SetLabelVisited(numRoot, true);
		//
		for (int i = 0; i < scan.GetRootByNum(numRoot).GetVectorEdge().size(); i++)
		{
			//��������� ������� �������, ���������� ��� ��� ���
			if (!currentList.GetLabelVisited(scan.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
				//������� ����� ����
				
				int minTact = scan.GetRootByNum(numRoot).GetEdgeApex(i).GetMinTact() + currentList.GetMinTact(numRoot);
					//���������� ���������� ��� � ������� ����� �������� root
				if (minTact <= currentList.GetMinTact(scan.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
					//������������� ����� ���, ���� ����� ��� ������ ��������
					currentList.SetMinTact(scan.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), minTact);
					currentList.SetEdge(scan.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), numRoot);
					//currentList.ChangeNode(scan.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), minTact, numRoot);
				}
			}
		}
		//���������� �������� ��� �� �������
		
			SetLabelWeightInStepByEdge(scan, currentList, currentList.GetNumEdgeApexWithMinTactAndNotVisited(scan, numRoot));
			//SetLabelWeightInStepByEdge(scan, currentList, scan.GetNumEdgeApexWithMinTactAndNotVisited(numRoot, currentList));
		}
		
	}
	return currentList;
}
//����� ��������, �������������� �������� ��� ����������� ������ ������ � ��������� ����������� ������ �� �������������� �������
void DijkstraAlgoritm::DijkstraAlgoritmSearchTrack(Scan& scan, int begin, int end) {
	//�������� ������������� ������������� ������
	if (scan.CheckRootByNum(begin)&&scan.CheckRootByNum(end))
	{
		//������� ������ ��� �������� ���������� � ��������� ���������(������)
		List currentList;
		for (int i = 0; i < scan.GetSizeScan(); i++)
		{
			currentList.PushNode(scan.GetRootByIndex(i).GetNumRoot());
		}
		//������� ��������� ��� �������� ��������
		/////////////////////////////////////////
		SetBeginTrack(begin);
		SetEndTrack(end);
		//��������� � ������� ������� ��������� �������
		PushTrack(begin);
		//������������� ����� ��������� ������� ������ 0
		currentList.SetMinTact(begin,0);
		currentList.SetEdge(begin, begin);
		SetLabelWeightInStepByEdge(scan, currentList, begin);
		currentList.PrintList();
		//SetTactTrack(scan.GetRootByNum(end).GetLabelWeight());
		BuildTrack(currentList, end);
		SetTactTrack(currentList.GetNodeByNum(end).minTact);
		Print();
	}
	else {
		if (!scan.CheckRootByNum(begin))
		{
			//ERROR-��������� ������� �� ���������� � ������� ���������
			cout << "��������� ������� �� ���������� � ������� ���������" << endl;
		}
		else if(!scan.CheckRootByNum(end)){
			//ERROR-�������� ������� �� ���������� � ������� ���������
			cout << "�������� ������� �� ���������� � ������� ���������" << endl;
		}
	}
}