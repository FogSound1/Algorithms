#pragma once
#include <random>
#include <memory>
#include "MatrixGraph.h"
#include "Route.h"
using namespace std;

//Клас представлення мурахи
class Ant
{
private:
	default_random_engine& Engine; //Генератор випадкових чисел
	int CurrentLocation; //Поточне місцерозташування мурахи
	int StartingLocation; //Початкове місцерозтішування
	unique_ptr<Route> route; //Шлях, пройдений мурахою
	bool IsAbleToMove; //Можливість мурахи продовжити рух
public:
	Ant(default_random_engine& engine, int Location, bool Exact); //Конструктор класу
	//Функція вибору подальшого кроку мурахи
	int Choice(const MatrixGraph& Pheromone, const MatrixGraph& Distance, double Alpha, double Beta);
	int GetCurrentLocation() const; //Гетер поточного місцерозташування
	unique_ptr<Route> GetRoute(); //Гетер шляху, пройденного мурахою
	bool AbleToContinue() const; //Гетер можливості мурахи продовжувати рух
	bool AtTheStart() const; //Перевірка, чи мураха у стартовій локації
};

