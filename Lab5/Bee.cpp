#include "Bee.h"

//Конструктор класу
Bee::Bee(int role, MatrixGraph Graph)
{
	Role = role;
	route.RandomRoute(Graph);
}

//Функція перемішування шляху
void Bee::ShuffleBeeRoute(MatrixGraph Graph)
{
	route.ShuffleRoute();
	route.UpdateDistance(Graph);
}

//Функціонал бджол-працівників
void Bee::Forage(MatrixGraph Graph, int Limit)
{
	Route NewPath = route.MutatePath(Graph);

	if (NewPath.GetDistance() < route.GetDistance())
	{
		route.ChangePath(NewPath.GetPath(), NewPath.GetDistance());
		Cycle = 0; //Скинути к-ть ітерацій щоб бджола могла далі працювати
	}
	else
	{
		Cycle += 1;
	}

	if (Cycle >= Limit) //Якщо бджола не робить прогресу
	{
		Role = 3;
	}
}

//Функція заміни шляху бджоли
void Bee::SetRoute(vector<int> OtherRoute, double distance)
{
	route.ChangePath(OtherRoute, distance);
}

//Функціонал бджоли-розвідника
void Bee::Scout(MatrixGraph Graph)
{
	route.ShuffleRoute();
	route.UpdateDistance(Graph);
	Role = 2;
	Cycle = 0;
}

//Гетер шляху, пройденного мурахою
Route Bee::GetRoute()
{
	return route;
}

//Сетер ролі
void Bee::SetRole(int Value)
{
	Role = Value;
}

//Гетер ролі бджоли
int Bee::GetRole()
{
	return Role;
}

//Гетер ітерацій
int Bee::GetCycle()
{
	return Cycle;
}