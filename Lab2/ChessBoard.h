#pragma once
#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
#include "windows.h"
#include "psapi.h"
using namespace std;

class ChessBoard
{
private:
	//ʳ������ ����� �� ������ �����
	int Quantity;
	//������������� ������ ����� � ��� ��������� ������
	int Board[8][8];

public:
	//����������� �����
	ChessBoard();
	//����������� ���������
	ChessBoard(ChessBoard* Previous);
	//����������� � ������������� ��������� ��� ������� ���������� �����
	ChessBoard(ChessBoard* Previous, int Position1, int Position2 = -1, int Orientation = 1);
	//����������� ��� ����������
	ChessBoard(int TestBoard[8][8]);
	//������� ������������ ����� �� ����� ���������� �����
	void Generation();
	//����� �����
	void SetBoard(ChessBoard* Previous);
	//������� ������ ������ �����
	void Output();
	int F1();

	bool ConflictCheck();
	bool ConflictCheckStraight(int x, int y);
	bool ConflictCheckDiagonal(int x, int y);
	int QueenHitNumber();
	std::vector<ChessBoard*> BoardArrGen();

	//����� ����
	void BFS();
	//�*
	void As ();
};