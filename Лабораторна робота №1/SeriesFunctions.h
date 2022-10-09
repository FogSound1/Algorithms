#pragma once
#include <climits>

class SeriesFunctions
{
	unsigned long long Previous, Current;
	bool Series, FileEnd;
public:
	SeriesFunctions();
	bool GetSeries();
	void SetSeries(bool flag);
	void SetFE(bool flag);
	bool GetFE();
	bool AddElement(unsigned long long num);
	unsigned long long GetCurrent();
	void Clear();
};