#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <functional>
#include <fstream>
using namespace std;

//Клас представлення графу, задається як матриця
class MatrixGraph
{
private:
	int Size; //Кількість вершин графу
	vector <vector <double>> Matrix; //Представлення матриці
public:
	MatrixGraph(string FileName); //Конструктор
	MatrixGraph(int size, function<double(int, int)> Generation); //Конструктор для графу феромонів
	//Видалення конструктора без параметрів для ліквідації можливих створень об'єктів класу без заданих параметрів
	MatrixGraph() = delete; 
	int GetSize() const; //Гетер кількості вершин графу (розмірності матриці)
	double GetElement(int Index1, int Index2) const; //Гетер елементу матриці
	void alter(int From, int To, function<void(double&)> alterator); //Функція зміни параметру
};

