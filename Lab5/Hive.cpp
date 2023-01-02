#pragma once
#include <random>
#include <vector>
#include "MatrixGraph.h"
#include "Bee.h"


//Клас представлення вулику
class Hive
{
private:
	int Population; //Кількість бджол
	MatrixGraph Distance; //Граф з вершинами задачі комівояжера
	random_device Device; //Прилад для генерації випадкових чисел
	default_random_engine Engine; //Генератор випадкових чисел
	vector <unique_ptr<Bee>> BeeHive; //Масив бджол
public:
	Hive(MatrixGraph Graph); //Конструктор класу
	void CreateBees(); //Функція створення бджол
	Route Waggle(int ForagerLimit, double ScoutCount, Route BestRoute); //Збір інформації
	Route Recruit(Route BestRoute); //Перегляд найкращих результатів
};
