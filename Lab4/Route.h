#pragma once
#include <vector>
#include <iostream>
#include "MatrixGraph.h"
using namespace std;

//Клас представлення шляху
class Route
{
private:
	vector<int> Path; //Представлення шляху
	double Distance; //Дистанція, яку займає шлях
public:
	Route(int Initial); //Конструктор класу
	double GetDistance() const; //Гетер дистанції
	int GetSteps() const; //Отримання кількості, пройденних кроків
	int operator[] (int element) const; //Перевантаження оператору [] для ітерування елементами класу
	void AddStep(int Vertex, double distance); //Додавання кроку до шляху
	bool Contains(int Location); //Перевірка чи була пройдена локація
};

