#include "FileFunctions.h"

void FileCreate(string FileName, unsigned long long Count)
{
	ofstream F1(FileName, ios::binary);
	unsigned long long Num;
	Block block;
	for (int i = 0; i < Count; i++)
	{
		Num = rand() + 1;
		block.NumNWrite(Num, F1);
	}
	block.BlockWrite(F1);

	F1.close();
}

void FileRead(string FileName, int Count)
{
	ifstream F2(FileName, ios::binary);
	unsigned long long Num, Prev;
	Prev = 0;
	Block block;
	bool flag = true;

	//Ми зчитуєм з файла число Num і якщо не дублюєтся, то виводимо
	for (int i = 0; i < Count && block.NumNRead(&Num, F2); i++)
	{
		if (Num != Prev)
		{
			cout << Num << " ";
			Prev = Num;
		}
		else
		{
			i--;
		}
	}
	F2.close();
}

string FileSort(int Num, string FileName)
{
	//Відкриваємо масиви ifstream та ofstream для запису/зчитування розподільчих файлів
	ofstream** StreamOf = new ofstream*[Num];
	OpenStream<ofstream>("B", Num, StreamOf);
	ifstream** StreamIf = new ifstream*[Num];

	ifstream F2(FileName, ios::binary);
	unsigned long long Number, temp = 0;
	bool Bused = false;
	int i = 0;

	Block InBlockR;
	Block* BlockR = new Block[Num];
	Block* BlockW = new Block[Num];

	//Доки 
	while (InBlockR.NumNRead(&Number, F2))
	{
		while (Number >= temp)
		{
			BlockW[i].NumNWrite(Number, *(StreamOf[i]));
			temp = Number;
			if (!InBlockR.NumNRead(&Number, F2))
			{
				break;
			}
		}
		//Перевірка на запис усіх файлів
		if (i == Num - 1)
		{
			Bused = true;
		}
		//Перенос ітератора-покажчика на наступний файл для щапису серій
		i = (i + 1) % Num;
		//Запис числа, яке не ввійшло у попередню серію
		BlockW[i].NumNWrite(Number, *(StreamOf[i]));
		temp = Number;
	}
	F2.close();

	for (int i = 0; i < Num; i++)
	{
		BlockW[i].BlockWrite(*(StreamOf[i]));
	}
	CloseStream<ofstream**>(StreamOf, Num);

	//Якщо не усі файли були використані, то ми змінюємо загальну кількість файлів
	if (!Bused)
	{
		Num = i + 1;
	}

	int flag = 1;
	string FileName1, FileName2;
	int counter;
	while (flag)
	{
		//Почерговий запис із файлі В у С і навпаки
		if (flag % 2 == 1)
		{
			FileName1 = "B";
			FileName2 = "C";
		}
		else
		{
			FileName1 = "C";
			FileName2 = "B";
		}

		OpenStream<ifstream>(FileName1, Num, StreamIf);
		OpenStream<ofstream>(FileName2, Num, StreamOf);

		SeriesFunctions* series = new SeriesFunctions[Num];
		//Збирання перших чисел розподільчих файлів
		for (int i = 0; i < Num; i++)
		{
			if (BlockR[i].NumNRead(&temp, *(StreamIf[i])))
			{
				series[i].AddElement(temp);
			}
			else
			{
				series[i].SetFE(true);
			}
		}

		counter = 0;
		bool AllDone = false;
		bool InFlag = true;
		//Злиття і запис серій
		while (InFlag) 
		{
			bool CheckNum = false;
			while (!CheckNum)
			{
				CheckNum = true;
				int pos;
				unsigned long long min = ULLONG_MAX;
				//Пошук мінімального числа з початків серій
				for (int j = 0; j < Num; j++)
				{
					if (series[j].GetSeries() && !series[j].GetFE())
					{
						if (series[j].GetCurrent() <= min)
						{
							min = series[j].GetCurrent();
							pos = j;
						}
						CheckNum = false;
					}
				}
				//Запис мінімального числа у файл та взяття наступного числа з того ж файлу 
				if (!CheckNum)
				{
					BlockW[counter].NumNWrite(min, *(StreamOf[counter]));
					if (BlockR[pos].NumNRead(&temp, *(StreamIf[pos])))
					{
						series[pos].AddElement(temp);
					}
					else
					{
						series[pos].SetFE(true);
					}
				}
			}
			counter++;
			//Перевірка на запис усіх файлів
			if (counter == Num)
			{
				counter = 0;
				AllDone = true;
			}
			InFlag = false;
			//Перевірка на зчитування всіх файлів
			for (int j = 0; j < Num; j++)
			{
				series[j].SetSeries(true);
				if (!series[j].GetFE())
				{
					InFlag = true;
				}
			}
		}

		//Дозаписування та доочищування усіх блоків
		for (int i = 0; i < Num; i++)
		{
			BlockR[i].Clear();
			BlockW[i].BlockWrite(*(StreamOf[i]));
		}
		CloseStream(StreamIf, Num);
		CloseStream(StreamOf, Num);

		if (!AllDone)
		{
			Num = counter;
		}
		flag++;
		if (Num == 1)
		{
			flag = 0;
		}

		delete[] series;
	}

	delete[] BlockR;
	delete[] BlockW;
	delete[] StreamIf;
	delete[] StreamOf;
	return FileName2;
}