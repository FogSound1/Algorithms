#pragma once
#include "Route.h"
#include "MatrixGraph.h"

//Клас представлення бджоли
class Bee
{
private:
	Route route; //Шлях, пройдений бджолою
	//Onlooker - 1, Forager - 2, Scout - 3
	int Role; //Роль бджоли 
	int Cycle; //Кількість ітерацій під час вирішення задачі
public:
	Bee(int role, MatrixGraph Graph); //Конструктор класу
	void ShuffleBeeRoute(MatrixGraph Graph); //Функція перемішування шляху
	void Forage(MatrixGraph Graph, int Limit); //Функціонал бджол-працівників
	void SetRoute(vector<int> OtherRoute, double distance); //Функція заміни шляху бджоли
	void Scout(MatrixGraph Graph); //Функціонал бджоли-розвідника
	Route GetRoute(); //Гетер шляху, пройденного мурахою
	void SetRole(int Value); //Сетер ролі
	int GetRole(); //Гетер ролі бджоли
	int GetCycle(); //Гетер ітерацій
};
