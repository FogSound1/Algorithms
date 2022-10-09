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
