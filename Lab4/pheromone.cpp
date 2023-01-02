#include "pheromone.h"

//Функція прокладування феромону
void pheromone::Lay(MatrixGraph& Phero, const Route& route, double AntPheromone)
{
	double PheromoneToLay = AntPheromone / route.GetSteps();
	for (int i = 1, n = route.GetSteps(); i < n; i++)
	{
		Phero.alter(route[i - 1], route[i], [PheromoneToLay](double& val) {val += PheromoneToLay; });
	}
}

//Функція випаровування феромону
void pheromone::Evaporate(MatrixGraph& Phero, double Evaporation)
{
	for (int i = 0, n = Phero.GetSize(); i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Phero.alter(i, j, [Evaporation](double& val) {val *= 1 - Evaporation; });
		}
	}
}
