#include "Route.h"

//����������� �����
Route::Route()
{
	Distance = INFINITY;
}

//����������� �����
Route::Route(int Initial)
{
	Distance = 0;
	this->AddStep(Initial, 0);
}

//����������� �����
Route::Route(vector<int> path, MatrixGraph Graph)
{
	Path = {path.begin(), path.end()};
	this->UpdateDistance(Graph);
}

//����� ��������� ���������
double Route::GetDistance() const
{
	return Distance;
}

//����������� �����
void Route::RandomRoute(MatrixGraph Graph)
{
	Path.resize(Graph.GetSize());
	for (int i = 0; i < Graph.GetSize(); i++)
	{
		Path[i] = i;
	}

	this->ShuffleRoute();
}

//������������ �����
void Route::ShuffleRoute()
{
	random_shuffle(begin(Path), end(Path));
}

//������� ����� �����
void Route::ChangePath(vector<int> OtherRoute, double distance)
{
	Path.resize(OtherRoute.size());
	Path = { OtherRoute.begin(), OtherRoute.end() };
	Distance = distance;
}

//������� ���� �����
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

//������� ��������� ��������� ���������
void Route::UpdateDistance(MatrixGraph Graph)
{
	Distance = 0;

	for (int i = 0; i < Path.size() - 1; i++)
	{
		Distance += Graph.GetElement(Path[i], Path[i+1]);
	}
}

//����� ������� ���������� �����
int Route::GetSteps() const
{
	return Path.size();
}

vector<int> Route::GetPath()
{
	return Path;
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

//�������������� ��������� ���������
Route& Route::operator=(Route route)
{
	Path = { route.Path.begin(), route.Path.end() };
	Distance = route.Distance;

	return* this;
}