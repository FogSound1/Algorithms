#include "Route.h"

//Конструктор класу
Route::Route()
{
	Distance = INFINITY;
}

//Конструктор класу
Route::Route(int Initial)
{
	Distance = 0;
	this->AddStep(Initial, 0);
}

//Конструктор класу
Route::Route(vector<int> path, MatrixGraph Graph)
{
	Path = {path.begin(), path.end()};
	this->UpdateDistance(Graph);
}

//Гетер пройденної дистанції
double Route::GetDistance() const
{
	return Distance;
}

//Рандомізація шляху
void Route::RandomRoute(MatrixGraph Graph)
{
	Path.resize(Graph.GetSize());
	for (int i = 0; i < Graph.GetSize(); i++)
	{
		Path[i] = i;
	}

	this->ShuffleRoute();
}

//Перемішування шляху
void Route::ShuffleRoute()
{
	random_shuffle(begin(Path), end(Path));
}

//Функція заміни шляху
void Route::ChangePath(vector<int> OtherRoute, double distance)
{
	Path.resize(OtherRoute.size());
	Path = { OtherRoute.begin(), OtherRoute.end() };
	Distance = distance;
}

//Функція зміни шляху
Route Route::MutatePath(MatrixGraph Graph)
{
	int Temp;
	random_device Device;
	uniform_int_distribution<int> Dist(0, (Path.size() - 2));

	int RandIndex = Dist(Device);
	vector<int> path = {Path.begin(), Path.end()};
	Temp = path[RandIndex];
	path[RandIndex] = path[RandIndex + 1];
	path[RandIndex + 1] = Temp;

	Route route(path, Graph);
	return route;
}

//Функція оновлення пройденної дистанції
void Route::UpdateDistance(MatrixGraph Graph)
{
	Distance = 0;

	for (int i = 0; i < Path.size() - 1; i++)
	{
		Distance += Graph.GetElement(Path[i], Path[i+1]);
	}
}

//Гетер кількості пройденних кроків
int Route::GetSteps() const
{
	return Path.size();
}

vector<int> Route::GetPath()
{
	return Path;
}

//Перевантаження оператору [] для ітерування елементами класу
int Route::operator[](int element) const
{
	return Path[element];
}

//Додавання кроку до шляху
void Route::AddStep(int Vertex, double distance)
{
	Path.push_back(Vertex);
	Distance += distance;
}

//Перевірка чи була пройдена локація
bool Route::Contains(int Location)
{
	return find(Path.begin(), Path.end(), Location) != Path.end();
}

//Перевантаження оператору присвоєння
Route& Route::operator=(Route route)
{
	Path = { route.Path.begin(), route.Path.end() };
	Distance = route.Distance;

	return* this;
}