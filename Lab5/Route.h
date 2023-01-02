#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "MatrixGraph.h"

//���� ������������� �����
class Route
{
private:
	vector<int> Path; //������������� �����
	double Distance; //���������, ��� ����� ����
public:
	Route(); //����������� �����
	Route(int Initial); //����������� �����
	Route(vector<int> path, MatrixGraph Graph); //����������� �����
	double GetDistance() const; //����� ���������
	void RandomRoute(MatrixGraph Graph); //������������ ����
	void ShuffleRoute(); //������������ �����
	void ChangePath(vector<int> OtherRoute, double distance); //������� ����� �����
	Route MutatePath(MatrixGraph Graph); //������� ���� �����
	void UpdateDistance(MatrixGraph Graph); //������� ��������� ��������� ���������
	int GetSteps() const; //��������� �������, ���������� �����
	vector<int> GetPath(); //����� �����
	int operator[] (int element) const; //�������������� ��������� [] ��� ���������� ���������� �����
	void AddStep(int Vertex, double distance); //��������� ����� �� �����
	bool Contains(int Location); //�������� �� ���� �������� �������
	Route& operator = (Route route); //�������������� ��������� ���������
};