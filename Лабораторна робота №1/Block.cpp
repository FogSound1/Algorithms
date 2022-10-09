#include "Block.h"

Block::Block(int num)
{
	Data = new unsigned long long[num]; 
	Size = num;
	Clear();
}

bool Block::BlockRead(ifstream& file)
{
	Clear();
	//Зчитуєм з файла блок
	if (file.read((char*)Data, Size * sizeof(unsigned long long)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Block::GetNum(unsigned long long* num)
{
	if (Iter < Size)
	{
		//Якщо ітератор не вийшов за межі блока, то повертаєм поточне значення
		if (Data[Iter] != ULLONG_MAX)
		{
			*num = Data[Iter];
			Iter++;
			return true;
		}
	}
	return false;
}

bool Block::NumNRead(unsigned long long* num, ifstream& file)
{
	//Якщо ітератор вийшов за межі, то заново починаєм зчитувати блок
	if (!GetNum(num))
	{
		if (BlockRead(file))
		{
			return GetNum(num);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool Block::AddNum(unsigned long long num)
{
	//Додаємо число до блоку, якщо є вільне місце
	if (Iter < Size)
	{
		Data[Iter] = num;
		Iter++;
		return true;
	}
	return false;
}

void Block::BlockWrite(ofstream& file)
{
	//Якщо наявен хоча б один елемент у блоці, то записуєм його у файл
	if (Iter > 0)
	{
		file.write((char*)Data, sizeof(unsigned long long) * Size);
	}
	Clear();
}

void Block::NumNWrite(unsigned long long num, ofstream& file)
{
	//Якщо блок повний, то записуєм існуюючі числа у файл, очищаєм та записуєм число
	if (!AddNum(num))
	{
		BlockWrite(file);
		Clear();
		AddNum(num);
	}
}

void Block::Clear()
{
	//Звільняєм блок від значень
	for (int i = 0; i < Size; i++)
	{
		Data[i] = ULLONG_MAX;
	}
	Iter = 0;
}

Block::~Block()
{
	delete[Size] Data;
}
