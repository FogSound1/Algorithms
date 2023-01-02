#pragma once
#include <random>
#include <vector>
#include "MatrixGraph.h"
#include "Bee.h"


//���� ������������� ������
class Hive
{
private:
	int Population; //ʳ������ �����
	MatrixGraph Distance; //���� � ��������� ������ ����������
	random_device Device; //������ ��� ��������� ���������� �����
	default_random_engine Engine; //��������� ���������� �����
	vector <unique_ptr<Bee>> BeeHive; //����� �����
public:
	Hive(MatrixGraph Graph); //����������� �����
	void CreateBees(); //������� ��������� �����
	Route Waggle(int ForagerLimit, double ScoutCount, Route BestRoute); //��� ����������
	Route Recruit(Route BestRoute); //�������� ��������� ����������
};