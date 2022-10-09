#include "SeriesFunctions.h"

SeriesFunctions::SeriesFunctions() 
{
	Current = Previous = 0;
	Series = true;
	FileEnd = false;
}

bool SeriesFunctions::GetSeries()
{
	return Series;
}

void SeriesFunctions::SetSeries(bool flag)
{
	Series = flag;
}

void SeriesFunctions::SetFE(bool flag)
{
	FileEnd = flag;
}

bool SeriesFunctions::GetFE()
{
	return FileEnd;
}

//Додавання елементу та подальше визначення сутності серії
bool SeriesFunctions::AddElement(unsigned long long num)
{
	Previous = Current;
	Current = num;
	if (Previous <= Current && Current != ULLONG_MAX)
	{
		Series = true;
	}
	else
	{
		Series = false;
	}
	return Series;
}

unsigned long long SeriesFunctions::GetCurrent()
{
	return Current;
}

void SeriesFunctions::Clear()
{
	Previous = 0;
	Current = 0;
	Series = true;
}
