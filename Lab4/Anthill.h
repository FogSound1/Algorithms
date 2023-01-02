#pragma once
#include <random>
#include <memory>
#include <vector>
#include "MatrixGraph.h"
#include "Ant.h"
using namespace std;

//���� ������������� ���������
class Anthill
{
private:
	const double Alpha = 2; //����� ��������
	const double Beta = 4; //����� ������� ���
	const double Pheromone0 = 1.0; //���������� �������
	const double PheromoneEvaporation = 0.6; //������������ �������������
	const double AntPheromone = 5; //������ �������� � ������
	const int Runs = 15; //����� ����� ��� ���������� ����������

	MatrixGraph Distance; //���� � ��������� ������ ����������
	MatrixGraph Pheromone; //���� ��������

	random_device Device; //������ ��� ��������� ���������� �����
	default_random_engine Engine; //��������� ���������� �����
	
	vector <unique_ptr<Ant>> Ahill; //����� �����
	void CreateAnts(); //������� ��������� �����
public:
	Anthill(MatrixGraph Graph); //����������� �����
	void FindRoute(); //������� ������ ���������� �������� ��� ������ ����������
};