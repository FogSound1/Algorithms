#include <iostream>
#include <string>
#include "Anthill.h"
#include "MatrixGraph.h"

int main()
{
	/*Користувач вводить назву файлу, він створюється.
	Далі генеруються значення елементів матриці випадковим чином*/
	string FileName;
	cout << "Enter the name of the file ";
	getline(cin, FileName);

	ofstream File(FileName);
	int size = 250;

	File << size;
	File << "\n";
	random_device Device;
	uniform_real_distribution<double> Dist(0, 50);
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
	Anthill anthill(Graph);

	anthill.FindRoute();
}