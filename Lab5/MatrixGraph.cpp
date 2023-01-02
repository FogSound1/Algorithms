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