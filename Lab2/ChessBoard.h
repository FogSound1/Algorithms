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
	//Кількість ферзів на шаховій дошці
	int Quantity;
	//Представлення шахової дошки у виді двомірного масиву
	int Board[8][8];

public:
	//Конструктор класу
	ChessBoard();
	//Конструктор копіювання
	ChessBoard(ChessBoard* Previous);
	//Конструктор з перестановкою стовпчиків або колонок попередньої дошки
	ChessBoard(ChessBoard* Previous, int Position1, int Position2 = -1, int Orientation = 1);
	//Конструктор для тестування
	ChessBoard(int TestBoard[8][8]);
	//Функція розставлення ферзів на дошці випадковим чином
	void Generation();
	//Сетер дошки
	void SetBoard(ChessBoard* Previous);
	//Функція виводу шахової дошки
	void Output();
	int F1();

	bool ConflictCheck();
	bool ConflictCheckStraight(int x, int y);
	bool ConflictCheckDiagonal(int x, int y);
	int QueenHitNumber();
	std::vector<ChessBoard*> BoardArrGen();

	//Пошук вшир
	void BFS();
	//А*
	void As ();
};