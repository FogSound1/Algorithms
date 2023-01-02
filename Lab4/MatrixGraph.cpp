#include "MatrixGraph.h"

/*����������� �����, ������� ������ ����� � ������ �����.
� ������ ����� ��������� ����� ������� �� �� ��������*/
MatrixGraph::MatrixGraph(string FileName)
{
	ifstream File(FileName); 
	File >> Size; 
	Matrix.resize(Size);

	for (int i = 0; i < Size; i++)
	{
		Matrix[i].resize(Size);
		for (int j = 0; j < Size; j++)
		{
			File >> Matrix[i][j];
		}
	}

	File.close();
}

/*����������� ��� ����� ��������, � ����� ���������� ������ �����
ϳ��� ����� �������� �������� ���������� �� ��������� ��������*/
MatrixGraph::MatrixGraph(int size, function<double(int, int)> Generation)
{
	Size = size;
	Matrix.resize(Size);
	for (int i = 0; i < Size; i++)
	{
		Matrix[i].resize(Size);
		for (int j = 0; j < Size; j++)
		{
			Matrix[i][j] = Generation(i, j);
		}
	}
}

//����� ������� ������ ����� (��������� �������)
int MatrixGraph::GetSize() const
{
	return Size;
}

//����� �������� �������
double MatrixGraph::GetElement(int Index1, int Index2) const
{
	return Matrix[Index1][Index2];
}

//������� ���� ���������
void MatrixGraph::alter(int From, int To, function<void(double&)> alterator)
{
	alterator(Matrix[From][To]);
}