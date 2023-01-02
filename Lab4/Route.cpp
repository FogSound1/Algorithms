#include "Route.h"

//Конструктор класу
Route::Route(int Initial)
{
	Distance = 0;
	this->AddStep(Initial, 0);
}

//Гетер пройденної дистанції
double Route::GetDistance() const
{
	return Distance;
}

//Гетер кількості пройденних кроків
int Route::GetSteps() const
{
	return Path.size();
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