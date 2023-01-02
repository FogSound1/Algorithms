#pragma once
#include <random>
#include <memory>
#include "MatrixGraph.h"
#include "Route.h"
using namespace std;

//���� ������������� ������
class Ant
{
private:
	default_random_engine& Engine; //��������� ���������� �����
	int CurrentLocation; //������� ���������������� ������
	int StartingLocation; //��������� ���������������
	unique_ptr<Route> route; //����, ��������� �������
	bool IsAbleToMove; //��������� ������ ���������� ���
public:
	Ant(default_random_engine& engine, int Location, bool Exact); //����������� �����
	//������� ������ ���������� ����� ������
	int Choice(const MatrixGraph& Pheromone, const MatrixGraph& Distance, double Alpha, double Beta);
	int GetCurrentLocation() const; //����� ��������� ����������������
	unique_ptr<Route> GetRoute(); //����� �����, ����������� �������
	bool AbleToContinue() const; //����� ��������� ������ ������������ ���
	bool AtTheStart() const; //��������, �� ������ � �������� �������
};

