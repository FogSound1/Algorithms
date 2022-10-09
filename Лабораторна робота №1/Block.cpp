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
	//«читуЇм з файла блок
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
		//якщо ≥тератор не вийшов за меж≥ блока, то повертаЇм поточне значенн€
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
	//якщо ≥тератор вийшов за меж≥, то заново починаЇм зчитувати блок
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
	//ƒодаЇмо число до блоку, €кщо Ї в≥льне м≥сце
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
	//якщо на€вен хоча б один елемент у блоц≥, то записуЇм його у файл
	if (Iter > 0)
	{
		file.write((char*)Data, sizeof(unsigned long long) * Size);
	}
	Clear();
}

void Block::NumNWrite(unsigned long long num, ofstream& file)
{
	//якщо блок повний, то записуЇм ≥снуююч≥ числа у файл, очищаЇм та записуЇм число
	if (!AddNum(num))
	{
		BlockWrite(file);
		Clear();
		AddNum(num);
	}
}

void Block::Clear()
{
	//«в≥льн€Їм блок в≥д значень
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
