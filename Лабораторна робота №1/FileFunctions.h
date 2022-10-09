#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "SeriesFunctions.h"
#include "Block.h"
#include <iostream>
#include <fstream>
using namespace std;

void FileCreate(string FileName, unsigned long long Count);
void FileRead(string FileName, int Count);
string FileSort(int, string);

template <typename T>
void OpenStream(string Letter, int Quant, T** StreamArr)
{
	for (int i = 0; i < Quant; i++)
	{
		char* Pos = new char;
		_itoa(i + 1, Pos, 10);
		StreamArr[i] = new T(Letter + string(Pos) + ".txt", ios::binary);
	}
}

template <typename T>
void CloseStream(T StreamArr, int Quant)
{
	for (int i = 0; i < Quant; i++)
	{
		StreamArr[i]->close();
	}
}
