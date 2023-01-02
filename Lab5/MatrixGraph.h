#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <functional>
#include <fstream>
using namespace std;

//���� ������������� �����, �������� �� �������
class MatrixGraph
{
private:
	int Size; //ʳ������ ������ �����
	vector <vector <double>> Matrix; //������������� �������
public:
	MatrixGraph(string FileName); //�����������
	//��������� ������������ ��� ��������� ��� �������� �������� �������� ��'���� ����� ��� ������� ���������
	MatrixGraph() = delete;
	int GetSize() const; //����� ������� ������ ����� (��������� �������)
	double GetElement(int Index1, int Index2) const; //����� �������� �������
};