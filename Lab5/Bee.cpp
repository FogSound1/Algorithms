#include "Bee.h"

//����������� �����
Bee::Bee(int role, MatrixGraph Graph)
{
	Role = role;
	route.RandomRoute(Graph);
}

//������� ������������ �����
void Bee::ShuffleBeeRoute(MatrixGraph Graph)
{
	route.ShuffleRoute();
	route.UpdateDistance(Graph);
}

//���������� �����-����������
void Bee::Forage(MatrixGraph Graph, int Limit)
{
	Route NewPath = route.MutatePath(Graph);

	if (NewPath.GetDistance() < route.GetDistance())
	{
		route.ChangePath(NewPath.GetPath(), NewPath.GetDistance());
		Cycle = 0; //������� �-�� �������� ��� ������ ����� ��� ���������
	}
	else
	{
		Cycle += 1;
	}

	if (Cycle >= Limit) //���� ������ �� ������ ��������
	{
		Role = 3;
	}
}

//������� ����� ����� ������
void Bee::SetRoute(vector<int> OtherRoute, double distance)
{
	route.ChangePath(OtherRoute, distance);
}

//���������� ������-���������
void Bee::Scout(MatrixGraph Graph)
{
	route.ShuffleRoute();
	route.UpdateDistance(Graph);
	Role = 2;
	Cycle = 0;
}

//����� �����, ����������� �������
Route Bee::GetRoute()
{
	return route;
}

//����� ���
void Bee::SetRole(int Value)
{
	Role = Value;
}

//����� ��� ������
int Bee::GetRole()
{
	return Role;
}

//����� ��������
int Bee::GetCycle()
{
	return Cycle;
}