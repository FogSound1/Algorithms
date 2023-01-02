#include <iostream>
#include <string>
#include "MatrixGraph.h"
#include "Hive.h"

int main()
{
	/*Користувач вводить назву файлу, він створюється
	Далі генеруються значення елементів матриці випадковим чином*/
	string FileName;
	cout << "Enter the name of the file ";
	getline(cin, FileName);
	ofstream File(FileName);
	int size = 300;

	File << size;
	File << "\n";
	random_device Device;
	uniform_real_distribution<double> Dist(5, 150);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				File << 0.0;
				File << "\t";
			}
			else
			{
				File << Dist(Device);
				File << "\t";
			}
		}
		File << "\n";
	}
	File.close();

	MatrixGraph Graph(FileName);
	int Cycle = 1;
	int CycleLimit = 150;
	double BestDistance = INFINITY;
	Hive hive(Graph);
	hive.CreateBees();
	Route BestRoute;
	Route WaggleRoute(0);
	Route RecruitRoute(0);
	
	while (Cycle < CycleLimit)
	{
		WaggleRoute = hive.Waggle(500, ceil(180 * 0.2), BestRoute);
		if (WaggleRoute.GetDistance() < BestDistance)
		{
			BestDistance = WaggleRoute.GetDistance();
			BestRoute.ChangePath(WaggleRoute.GetPath(), BestDistance);
			cout << "Better route is found. It's length is " << BestDistance << endl;
		}
		RecruitRoute = hive.Recruit(BestRoute);
		if (RecruitRoute.GetDistance() < BestDistance)
		{
			BestDistance = RecruitRoute.GetDistance();
			BestRoute.ChangePath(RecruitRoute.GetPath(), BestDistance);
			cout << "Better route is found. It's length is " << BestDistance << endl;
		}

		Cycle += 1;
	}
}