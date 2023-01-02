#pragma once
#include <random>
#include <memory>
#include <vector>
#include "MatrixGraph.h"
#include "Ant.h"
using namespace std;

//Клас представлення мурашника
class Anthill
{
private:
	const double Alpha = 2; //Довіра феромону
	const double Beta = 4; //Довіра видимих міст
	const double Pheromone0 = 1.0; //Початковий феромон
	const double PheromoneEvaporation = 0.6; //Інтенсивність випаровування
	const double AntPheromone = 5; //Скільки феромону у мурахи
	const int Runs = 15; //Обхід графа без покращення результату

	MatrixGraph Distance; //Граф з вершинами задачі комівояжера
	MatrixGraph Pheromone; //Граф феромону

	random_device Device; //Прилад для генерації випадкових чисел
	default_random_engine Engine; //Генератор випадкових чисел
	
	vector <unique_ptr<Ant>> Ahill; //Масив мурах
	void CreateAnts(); //Функція створення мурах
public:
	Anthill(MatrixGraph Graph); //Конструктор класу
	void FindRoute(); //Функція пошуку найкращого маршруту для задачі комівояжера
};
