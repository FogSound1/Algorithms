#pragma once
#include <fstream>
using namespace std;

class Block
{
	unsigned long long* Data;
	int Size;
	int Iter;
public:
	Block(int num = 4 * 1048576);
	bool BlockRead(ifstream& file);
	bool GetNum(unsigned long long* num);
	bool NumNRead(unsigned long long* num, ifstream& file);
	bool AddNum(unsigned long long num);
	void BlockWrite(ofstream& file);
	void NumNWrite(unsigned long long num, ofstream& file);
	void Clear();
	~Block();
};
