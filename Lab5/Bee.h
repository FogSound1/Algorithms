#pragma once
#include "Route.h"
#include "MatrixGraph.h"

//���� ������������� ������
class Bee
{
private:
	Route route; //����, ��������� �������
	//Onlooker - 1, Forager - 2, Scout - 3
	int Role; //���� ������ 
	int Cycle; //ʳ������ �������� �� ��� �������� ������
public:
	Bee(int role, MatrixGraph Graph); //����������� �����
	void ShuffleBeeRoute(MatrixGraph Graph); //������� ������������ �����
	void Forage(MatrixGraph Graph, int Limit); //���������� �����-����������
	void SetRoute(vector<int> OtherRoute, double distance); //������� ����� ����� ������
	void Scout(MatrixGraph Graph); //���������� ������-���������
	Route GetRoute(); //����� �����, ����������� �������
	void SetRole(int Value); //����� ���
	int GetRole(); //����� ��� ������
	int GetCycle(); //����� ��������
};