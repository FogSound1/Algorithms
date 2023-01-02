#include "MatrixGraph.h"

/*Конструктор класу, функція приймає рядок з назвою файла.
З даного файлу зчитується розмір матриці та її елементи*/
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

//Гетер кількості вершин графу (розмірність матриці)
int MatrixGraph::GetSize() const
{
	return Size;
}

//Гетер елементу матриці
double MatrixGraph::GetElement(int Index1, int Index2) const
{
	return Matrix[Index1][Index2];
}