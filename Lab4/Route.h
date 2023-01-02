#pragma once
#include <vector>
#include <iostream>
#include "MatrixGraph.h"
using namespace std;

//���� ������������� �����
class Route
{
private:
	vector<int> Path; //������������� �����
	double Distance; //���������, ��� ����� ����
public:
	Route(int Initial); //����������� �����
	double GetDistance() const; //����� ���������
	int GetSteps() const; //��������� �������, ���������� �����
	int operator[] (int element) const; //�������������� ��������� [] ��� ���������� ���������� �����
	void AddStep(int Vertex, double distance); //��������� ����� �� �����
	bool Contains(int Location); //�������� �� ���� �������� �������
};

