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
List SetLabelWeightInStepByEdge(TactCalculation& tactCalculation, List& currentList, int numRoot) {
	//��������� ��� ������� ���������� � �� ������������
	if (tactCalculation.CheckRootByNum(numRoot)&&numRoot >= 0)
	{
	//��������� ��������� ������� ���������� ��� ��� ���
	if (!currentList.GetLabelVisited(numRoot))
	{
		//������������� ���� ���������
		currentList.SetLabelVisited(numRoot, true);
		//
		for (int i = 0; i < tactCalculation.GetRootByNum(numRoot).GetVectorEdge().size(); i++)
		{
			//��������� ������� �������, ���������� ��� ��� ���
			if (!currentList.GetLabelVisited(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
				//������� ����� ����
				
				int minTact = tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetMinTact() + currentList.GetMinTact(numRoot);
					//���������� ���������� ��� � ������� ����� �������� root
				if (minTact <= currentList.GetMinTact(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex())) {
					//������������� ����� ���, ���� ����� ��� ������ ��������
					currentList.SetMinTact(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), minTact);
					currentList.SetEdge(tactCalculation.GetRootByNum(numRoot).GetEdgeApex(i).GetNumApex(), numRoot);
				}
			}
		}
		//���������� �������� ��� �� �������
		
			SetLabelWeightInStepByEdge(tactCalculation, currentList, currentList.GetNumEdgeApexWithMinTactAndNotVisited(tactCalculation, numRoot));
		}
		
	}
	return currentList;
}
//����� ��������, �������������� �������� ��� ����������� ������ ������ � ��������� ����������� ������ �� �������������� �������
void DijkstraAlgoritm::DijkstraAlgoritmSearchTrack(TactCalculation& tactCalculation, int begin, int end) {
	//�������� ������������� ������������� ������
	if (tactCalculation.CheckRootByNum(begin)&& tactCalculation.CheckRootByNum(end))
	{
		//������� ������ ��� �������� ���������� � ��������� ���������(������)
		List currentList;
		for (int i = 0; i < tactCalculation.GetSizeScan(); i++)
		{
			currentList.PushNode(tactCalculation.GetRootByIndex(i).GetNumRoot());
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
		SetLabelWeightInStepByEdge(tactCalculation, currentList, begin);
		currentList.PrintList();
		//SetTactTrack(scan.GetRootByNum(end).GetLabelWeight());
		BuildTrack(currentList, end);
		SetTactTrack(currentList.GetNodeByNum(end).minTact);
		Print();
	}
	else {
		if (!tactCalculation.CheckRootByNum(begin))
		{
			//ERROR-��������� ������� �� ���������� � ������� ���������
			cout << "��������� ������� �� ���������� � ������� ���������" << endl;
		}
		else if(!tactCalculation.CheckRootByNum(end)){
			//ERROR-�������� ������� �� ���������� � ������� ���������
			cout << "�������� ������� �� ���������� � ������� ���������" << endl;
		}
	}
}