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
	//������ � ����� ����
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
		//���� �������� �� ������ �� ��� �����, �� �������� ������� ��������
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
	//���� �������� ������ �� ���, �� ������ ������� ��������� ����
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
	//������ ����� �� �����, ���� � ����� ����
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
	//���� ������ ���� � ���� ������� � �����, �� ������� ���� � ����
	if (Iter > 0)
	{
		file.write((char*)Data, sizeof(unsigned long long) * Size);
	}
	Clear();
}

void Block::NumNWrite(unsigned long long num, ofstream& file)
{
	//���� ���� ������, �� ������� �������� ����� � ����, ������ �� ������� �����
	if (!AddNum(num))
	{
		BlockWrite(file);
		Clear();
		AddNum(num);
	}
}

void Block::Clear()
{
	//�������� ���� �� �������
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
