#pragma once
#include "ChessBoard.h"
#include <iostream>

class Tree
{
private:
	//Масив покажчиків на вершини-нащадки
	Tree** Node;
	//Дані вершини - шахова дошка
	ChessBoard* Data;
	//Кількість нащадків
	int Descendants;
	//Видалення гілки дерева рекурсивною функцією
	void DeleteBranch(Tree* Node, int& Counter);

public:
	//Конструктор, покажчик на дошку та кількість нащадків
	Tree(ChessBoard*, int Num = 2);
	//Вставлення вершини-нащадка на задану позицію
	Tree* Insert(ChessBoard*, int Position);
	//Геттер покажчика на шахову дошку
	ChessBoard* GetData();
	//Геттер кількості нащадків
	int GetDescendants();
	//Геттер нащадка певної позиції
	Tree* GetDescendant(int Num);
	//Видалення усіх нащадків вершини
	int Clear();
	//Деструктор
	~Tree();
};