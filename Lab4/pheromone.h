#pragma once
#include "MatrixGraph.h"
#include "Route.h"

namespace pheromone
{
	void Lay(MatrixGraph& Phero, const Route& route, double AntPheromone); //Функція прокладування феромону
	void Evaporate(MatrixGraph& Phero, double Evaporation); //Функція випаровування феромону
}