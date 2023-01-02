#include "Anthill.h"
#include "pheromone.h"

/*Конструктор класу, атрибут Distance задається значенням графа, який використовується у задачі комівояжера
Граф феромонів задається лямбда виразом: якщо індекси рівні, то задається як 0, бо не можна перейти з міста в себе*/
Anthill::Anthill(MatrixGraph Graph)
	: Distance(Graph), Pheromone(Graph.GetSize(),
		[this](int Index1, int Index2) -> double {return Index1 != Index2 ? this-> Pheromone0 : 0; }),
	Device(), Engine(Device())
{
}

/*Функція створення мурах*/
void Anthill::CreateAnts()
{
	int M = 45;
	Ahill.resize(M);

	for (int i = 0; i < M; i++)
	{
		Ahill[i] = unique_ptr<Ant>(new Ant(Engine, Distance.GetSize(), false));
	}
}

/*Алгоритм мурах, головна функція для вирішення задачі.
Створюються мурахи, потім алгоритм проходиться по кожній мурасі.
Поки мураха може йти далі вона робить вибір куди йти та прокладає шлях
Якщо шлях, по якому пройшла мураха менший за попередній найкращий шлях, то
даний шлях записується у змінну BestLength. Після цього мураха прокладує феромон, той випаровується*/
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
