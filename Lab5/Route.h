#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "MatrixGraph.h"

//Клас представлення шляху
class Route
{
private:
	vector<int> Path; //Представлення шляху
	double Distance; //Дистанція, яку займає шлях
public:
	Route(); //Конструктор класу
	Route(int Initial); //Конструктор класу
	Route(vector<int> path, MatrixGraph Graph); //Конструктор класу
	double GetDistance() const; //Гетер дистанції
	void RandomRoute(MatrixGraph Graph); //Рандомізувати шлях
	void ShuffleRoute(); //Перемішування шляху
	void ChangePath(vector<int> OtherRoute, double distance); //Функція заміни шляху
	Route MutatePath(MatrixGraph Graph); //Функція зміни шляху
	void UpdateDistance(MatrixGraph Graph); //Функція оновлення пройденної дистанції
	int GetSteps() const; //Отримання кількості, пройденних кроків
	vector<int> GetPath(); //Гетер шляху
	int operator[] (int element) const; //Перевантаження оператору [] для ітерування елементами класу
	void AddStep(int Vertex, double distance); //Додавання кроку до шляху
	bool Contains(int Location); //Перевірка чи була пройдена локація
	Route& operator = (Route route); //Перевантаження оператора присвоєння
};
