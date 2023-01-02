#include "Hive.h"

//Передається граф з містами задачі комівояжера
Hive::Hive(MatrixGraph Graph) : Distance (Graph)
{
	Population = 180;
}

//Функція створення бджол
void Hive::CreateBees()
{
	int Onlooker_Count, Forager_Count;

	Onlooker_Count = floor(Population * 0.5);
	Forager_Count = Onlooker_Count;
	BeeHive.resize(Population);
	for (int i = 0; i < Onlooker_Count; i++)
	{
		BeeHive[i] = unique_ptr<Bee>(new Bee(1, Distance));
	}

	for (int i = Onlooker_Count; i < (Onlooker_Count + Forager_Count); i++)
	{
		BeeHive[i] = unique_ptr<Bee>(new Bee(2, Distance));
		BeeHive[i]->ShuffleBeeRoute(Distance);
	}
}

/*Збирається інформація на рахунок праці бджол - працівників
Вибирається новий випадковий шлях для розвідників.*/
Route Hive::Waggle(int ForagerLimit, double ScoutCount, Route BestRoute)
{
	int Iterator = 0;
	vector<int> Indexes;
	vector<double> ForagerDistances;
	vector<double> ForagerDistancesSorted;
	for (unique_ptr<Bee>& bee : BeeHive)
	{
		if (bee->GetRole() == 2)
		{
			bee->Forage(Distance, ForagerLimit);
			if (bee->GetRoute().GetDistance() < BestRoute.GetDistance())
			{
				BestRoute.ChangePath(bee->GetRoute().GetPath(), bee->GetRoute().GetDistance());
			}
			Indexes.push_back(Iterator);
			ForagerDistances.push_back(BestRoute.GetDistance());
			ForagerDistancesSorted.push_back(BestRoute.GetDistance());
		}
		else if (bee->GetRole() == 3)
		{
			bee->Scout(Distance);
		}
		Iterator++;
	}

	vector<double>::iterator Ind;
	sort(ForagerDistancesSorted.begin(), ForagerDistancesSorted.end(), greater<double>{});
	for (int i = 0; i < ScoutCount && i < ForagerDistances.size(); i++)
	{
		Ind = find(ForagerDistances.begin(), ForagerDistances.end(), ForagerDistancesSorted[i]);
		BeeHive[Indexes[Ind - ForagerDistances.begin()]]->SetRole(3);
	}

	return BestRoute;
}

/*Переглядається найкращі результати, які були до цього моменту отримані*/
Route Hive::Recruit(Route BestRoute)
{
	for (unique_ptr<Bee>& bee : BeeHive)
	{
		if (bee->GetRole() == 1)
		{
			bee->SetRoute(BestRoute.GetPath(), BestRoute.GetDistance());
			Route MutantRoute(0);
			MutantRoute = bee->GetRoute().MutatePath(Distance);
			bee->SetRoute(MutantRoute.GetPath(), MutantRoute.GetDistance());
			if (bee->GetRoute().GetDistance() < BestRoute.GetDistance())
			{
				BestRoute.ChangePath(bee->GetRoute().GetPath(), bee->GetRoute().GetDistance());
			}
		}
	}

	return BestRoute;
}