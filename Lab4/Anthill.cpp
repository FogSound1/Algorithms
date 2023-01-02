#include "Anthill.h"
#include "pheromone.h"

/*����������� �����, ������� Distance �������� ��������� �����, ���� ��������������� � ������ ����������
���� �������� �������� ������ �������: ���� ������� ���, �� �������� �� 0, �� �� ����� ������� � ���� � ����*/
Anthill::Anthill(MatrixGraph Graph)
	: Distance(Graph), Pheromone(Graph.GetSize(),
		[this](int Index1, int Index2) -> double {return Index1 != Index2 ? this-> Pheromone0 : 0; }),
	Device(), Engine(Device())
{
}

/*������� ��������� �����*/
void Anthill::CreateAnts()
{
	int M = 45;
	Ahill.resize(M);

	for (int i = 0; i < M; i++)
	{
		Ahill[i] = unique_ptr<Ant>(new Ant(Engine, Distance.GetSize(), false));
	}
}

/*�������� �����, ������� ������� ��� �������� ������.
����������� ������, ���� �������� ����������� �� ����� �����.
���� ������ ���� ��� ��� ���� ������ ���� ���� ��� �� �������� ����
���� ����, �� ����� ������� ������ ������ �� ��������� ��������� ����, ��
����� ���� ���������� � ����� BestLength. ϳ��� ����� ������ �������� �������, ��� ������������*/
void Anthill::FindRoute()
{
	double BestLength = INFINITY;
	auto Cont = Runs;
	while (Cont > 0)
	{
		CreateAnts();
		
		for (unique_ptr<Ant>& ant : Ahill)
		{
			while (ant->AbleToContinue())
			{
				ant->Choice(Pheromone, Distance, Alpha, Beta);
			}
			
			auto CurrentRoute = ant->GetRoute();
			if (BestLength > CurrentRoute->GetDistance())
			{
				BestLength = CurrentRoute->GetDistance();
				Cont = Runs;
				cout << "Better route is found. It's length is " << BestLength << endl;
			}
			pheromone::Lay(Pheromone, *CurrentRoute, AntPheromone);
		}
		pheromone::Evaporate(Pheromone, PheromoneEvaporation);
		--Cont;
	}
}