#pragma once
#include "MatrixGraph.h"
#include "Route.h"

namespace pheromone
{
	void Lay(MatrixGraph& Phero, const Route& route, double AntPheromone); //������� ������������� ��������
	void Evaporate(MatrixGraph& Phero, double Evaporation); //������� ������������� ��������
}