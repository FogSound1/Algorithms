#pragma once
#include "ChessBoard.h"
#include <iostream>

class Tree
{
private:
	//����� ��������� �� �������-�������
	Tree** Node;
	//��� ������� - ������ �����
	ChessBoard* Data;
	//ʳ������ �������
	int Descendants;
	//��������� ���� ������ ����������� ��������
	void DeleteBranch(Tree* Node, int& Counter);

public:
	//�����������, �������� �� ����� �� ������� �������
	Tree(ChessBoard*, int Num = 2);
	//���������� �������-������� �� ������ �������
	Tree* Insert(ChessBoard*, int Position);
	//������ ��������� �� ������ �����
	ChessBoard* GetData();
	//������ ������� �������
	int GetDescendants();
	//������ ������� ����� �������
	Tree* GetDescendant(int Num);
	//��������� ��� ������� �������
	int Clear();
	//����������
	~Tree();
};