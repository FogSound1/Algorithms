#include "Ant.h"
#include <cmath>

/*����������� �����, ��������� ���������� ����� ���������� ����������, ��������� �������� �������� �� true
���� �� ������� � ����� ���� ���� ��������, �� ��������� ���������� ���������� ���������� �����
�������� ������� �������� ���������� ������� �������, ������������ ����*/
Ant::Ant(default_random_engine& engine, int Location, bool Exact) : Engine(engine), IsAbleToMove(true)
{
	if (Exact)
	{
		CurrentLocation = Location;
	}
	else
	{
		uniform_int_distribution<int> Distribution(0, Location - 1);
		CurrentLocation = Distribution(Engine);
	}
	StartingLocation = CurrentLocation;
	route = unique_ptr<Route>(new Route(CurrentLocation));
}

/*������� ������ ������� ���������� �����*/
int Ant::Choice(const MatrixGraph& Pheromone, const MatrixGraph& Distance, double Alpha, double Beta)
{
	int From = CurrentLocation;

	if (route->GetSteps() == Distance.GetSize()) //�������� �� ������� ������ �� ����
	{
		IsAbleToMove = false;
		CurrentLocation = StartingLocation;
		route->AddStep(StartingLocation, Distance.GetElement(From, StartingLocation));
		return StartingLocation;
	}

	vector<double> NeighbourProb;
	double MaxProb = 0.0;
	double CurrentProb;
	for (int i = 0, Size = Distance.GetSize(); i < Size; i++)
	{
		if (i == From) //�� ����� ��� � �� ���� ����
		{
			NeighbourProb.push_back(0);
		}
		else if (route->Contains(i)) //�� ����� ���� ��������� ����
		{
			NeighbourProb.push_back(0);
		}
		else
		{
			CurrentProb = pow(Pheromone.GetElement(From, i), Alpha) * pow(Distance.GetElement(From, i), Beta);
			MaxProb += CurrentProb;
			NeighbourProb.push_back(MaxProb);
		}
	}

	if (MaxProb == 0) //���� ���� ���
	{
		IsAbleToMove = false;
		return SIZE_MAX;
	}

	uniform_real_distribution<double> Distribution(0.0, MaxProb);
	double choice = Distribution(Engine);

	for (int i = 0; i < NeighbourProb.size(); i++)
	{
		if (choice < NeighbourProb[i])
		{
			CurrentLocation = i;
			route->AddStep(i, Distance.GetElement(From, i));
			return i;
		}
	}
}

//����� ��������� �������������
int Ant::GetCurrentLocation() const
{
	return CurrentLocation;
}

//����� �����, ����������� �������
unique_ptr<Route> Ant::GetRoute()
{
	return move(route);
}

//��������� ������ ��� ���
bool Ant::AbleToContinue() const
{
	return IsAbleToMove;
}

//�������� �� ������ � �������� �������
bool Ant::AtTheStart() const
{
	if (CurrentLocation == StartingLocation)
	{
		return true;
	}
	else
	{
		return false;
	}
}