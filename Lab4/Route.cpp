#include "Route.h"

//����������� �����
Route::Route(int Initial)
{
	Distance = 0;
	this->AddStep(Initial, 0);
}

//����� ��������� ���������
double Route::GetDistance() const
{
	return Distance;
}

//����� ������� ���������� �����
int Route::GetSteps() const
{
	return Path.size();
}

//�������������� ��������� [] ��� ���������� ���������� �����
int Route::operator[](int element) const
{
	return Path[element];
}

//��������� ����� �� �����
void Route::AddStep(int Vertex, double distance)
{
	Path.push_back(Vertex);
	Distance += distance;
}

//�������� �� ���� �������� �������
bool Route::Contains(int Location)
{
	return find(Path.begin(), Path.end(), Location) != Path.end();
}