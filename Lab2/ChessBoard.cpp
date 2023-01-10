#include "ChessBoard.h"
#include "Tree.h"
#include "State.h"
using namespace std;

//Конструктор класу
ChessBoard::ChessBoard()
{
	Quantity = 8;
	for (int i = 0; i < Quantity; i++)
	{
		for (int j = 0; j < Quantity; j++)
		{
			Board[i][j] = 0;
		}
	}
}


ChessBoard::ChessBoard(ChessBoard* Previous)
{
	Quantity = Previous->Quantity;
	SetBoard(Previous);
}

ChessBoard::ChessBoard(ChessBoard* Previous, int Position1, int Position2, int Orientation)
{
	SetBoard(Previous);
	Position1 %= Quantity;

	if (Position2 == -1)
	{
		Position2 = (Position1 + 1) % Quantity;
	}
	else
	{
		Position2 %= Quantity;
	}

	int temp;
	switch (Orientation)
	{
	case 1: //Стовбці
		for (int i = 0; i < Quantity; i++)
		{
			temp = Board[i][Position1];
			Board[i][Position1] = Board[i][Position2];
			Board[i][Position2] = temp;
		}
		break;
	case 2: //Рядки
		for (int i = 0; i < Quantity; i++)
		{
			temp = Board[Position1][i];
			Board[Position1][i] = Board[Position2][i];
			Board[Position2][i] = temp;
		}
	}
}

ChessBoard::ChessBoard(int TestBoard[8][8])
{
	Quantity = 8;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Board[i][j] = TestBoard[i][j];
		}
	}
}

void ChessBoard::SetBoard(ChessBoard* Previous)
{
	Quantity = Previous->Quantity;
	for (int i = 0; i < Quantity; i++)
	{
		for (int j = 0; j < Quantity; j++)
		{
			Board[i][j] = Previous->Board[i][j];
		}
	}
}

//Функція розставлення ферзів на дошці випадковим чином
void ChessBoard::Generation()
{
	srand(time(NULL));
	int RandNum1, RandNum2, Temp;
	int Arr[8];

	for (int i = 0; i < Quantity; i++)
	{
		Arr[i] = i;
	}

	for (int i = 0; i < Quantity; i++)
	{
		RandNum1 = rand() % Quantity;
		RandNum2 = rand() % Quantity;

		Temp = Arr[RandNum1];
		Arr[RandNum1] = Arr[RandNum2];
		Arr[RandNum2] = Temp;
	}

	for (int i = 0; i < Quantity; i++)
	{
		Board[i][Arr[i]] = 1;
	}
}

//Функція виводу шахової дошки
void ChessBoard::Output()
{
	int arr[8];
	for (int i = 0; i < Quantity; i++)
	{
		for (int j = 0; j < Quantity; j++)
		{
			cout << Board[i][j] << " ";
			if (Board[i][j] == 1)
			{
				arr[i] = j;
			}
		}
		cout << endl;
	}
	cout << endl << "The State:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
}

int ChessBoard::F1()
{
	int* Location[8];
	int QuantDiagonal = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[i][j] == 1)
			{
				int tempx = i, tempy = j;
				while (tempx > 0 && tempy > 0)
				{
					tempx--;
					tempy--;
					if (Board[tempx][tempy] != 0)
					{
						QuantDiagonal++;
						break;
					}
				}

				tempx = i, tempy = j;
				while (tempx < Quantity - 1 && tempy < Quantity - 1)
				{
					tempx++;
					tempy++;
					if (Board[tempx][tempy] != 0)
					{
						QuantDiagonal++;
						break;
					}
				}

				tempx = i, tempy = j;
				while (tempx > 0 && tempy < Quantity - 1)
				{
					tempx--;
					tempy++;
					if (Board[tempx][tempy] != 0)
					{
						QuantDiagonal++;
						break;
					}
				}

				tempx = i, tempy = j;
				while (tempx < Quantity - 1 && tempy > 0)
				{
					tempx++;
					tempy--;
					if (Board[tempx][tempy] != 0)
					{
						QuantDiagonal++;
						break;
					}
				}
			}
		}
	}

	return QuantDiagonal / 2;
}

bool ChessBoard::ConflictCheck()
{
	bool Flag = false;
	for (int i = 0; i < Quantity && !Flag; i++)
	{
		for (int j = 0; j < Quantity && !Flag; j++)
		{
			if (Board[i][j] != 0 && !Flag)
			{
				Flag = ConflictCheckDiagonal(i, j);
			}
		}
	}
	
	return Flag;
}

bool ChessBoard::ConflictCheckStraight(int x, int y)
{
	for (int i = 1; i < Quantity; i++)
	{
		if (Board[(x + i) % Quantity][y] != 0)
		{
			return true;
		}
		if (Board[x][(y + i) % Quantity] != 0)
		{
			return true;
		}
	}

	return false;
}

bool ChessBoard::ConflictCheckDiagonal(int x, int y)
{
	int tempx = x, tempy = y;
	while (tempx > 0 && tempy > 0)
	{
		tempx--; 
		tempy--;
		if (Board[tempx][tempy] != 0)
		{
			return true;
		}
	}

	tempx = x, tempy = y;
	while (tempx < Quantity - 1 && tempy < Quantity - 1)
	{
		tempx++; 
		tempy++;
		if (Board[tempx][tempy] != 0)
		{
			return true;
		}
	}

	tempx = x, tempy = y;
	while (tempx > 0 && tempy < Quantity - 1)
	{
		tempx--; 
		tempy++;
		if (Board[tempx][tempy] != 0)
		{
			return true;
		}
	}

	tempx = x, tempy = y;
	while (tempx < Quantity - 1 && tempy > 0)
	{
		tempx++; 
		tempy--;
		if (Board[tempx][tempy] != 0)
		{
			return true;
		}
	}

	return false;
}

int ChessBoard::QueenHitNumber()
{
	int count = 0;
	for (int i = 0; i < Quantity; i++)
	{
		for (int j = 0; j < Quantity; j++)
		{
			if (Board[i][j] != 0)
			{
				if (ConflictCheckDiagonal(i, j))
				{
					count++;
				}
			}
		}
	}
	return count;
}

std::vector<ChessBoard*> ChessBoard::BoardArrGen()
{
	int QueenHit = Quantity;
	std::vector<ChessBoard*> result;

	for (int orientation = 1; orientation <= 2; orientation++)
	{
		for (int j = 0; j < Quantity - 1; j++)
		{
			for (int k = j + 1; k < Quantity; k++)
			{
				result.push_back(new ChessBoard(this, j, k, orientation));
			}
		}
	}
	return result;
}


void ChessBoard::BFS()
{
	if (!this->ConflictCheck())
	{
		return;
	}

	int Counter = 1; //Кількість станів
	int MaxCount = 1; //Кількість станів в пам'яті
	int Iter = 0; //Кількість ітерацій
	// змінні для BFS алгоритму
	queue <Tree*> Plan;
	Tree* temp = new Tree(new ChessBoard(this), pow(Quantity, 2) - Quantity);
	Plan.push(temp);
	bool Flag = temp->GetData()->ConflictCheck();
	Tree* temp2 = temp;
	std::vector<ChessBoard*> ChessBoardArr;

	while (Flag)
	{
		Iter++;
		//BFS алгоритм
		temp = Plan.front();
		Plan.pop();
		ChessBoardArr = temp->GetData()->BoardArrGen();

		for (int i = 0; i < ChessBoardArr.size() && Flag; i++)
		{
			temp2 = temp->Insert(ChessBoardArr[i], i);
			Plan.push(temp2);
			if (!temp2->GetData()->ConflictCheck())
			{
				Flag = false;
			}
			Counter++;
		}

		// визначення найбільшої кількості вершин, що існували в один момент
		if (MaxCount < Plan.size() + 1)
		{
			MaxCount = Plan.size() + 1;
		}

		// видалення непотрібних вершин
		if (temp2 != temp)
		{
			delete temp;
		}
	}

	// видалення всіх вершин дерева, що залишилися
	while (Plan.size() > 1)
	{
		temp = Plan.front();
		Plan.pop();
		delete temp;
	}

	// результат
	for (int i = 0; i < Quantity; i++)
	{
		for (int j = 0; j < Quantity; j++)
		{
			Board[i][j] = temp2->GetData()->Board[i][j];
		}
	}
	
	cout << endl << "Quantity of states " << Counter;
	cout << endl << "Quantity of states in the memory " << MaxCount;
	cout << endl << "Quantity of iterations " << Iter;
	delete temp2;
}

void ChessBoard::As()
{
	if (!this->ConflictCheck())
	{
		return;
	}

	int Counter = 1; //Кількість станів
	int MaxCount = 1; //Кількість станів в пам'яті
	int Iter = 0; //Кількість ітерацій

	auto compare = [](State a, State b)
	{
		return a.Value > b.Value;
	};

	priority_queue<State, vector<State>, decltype(compare)> Nodes(compare);
	Nodes.push(State(new ChessBoard(*this), 1));
	bool Flag = true;

	while (Flag)
	{
		Iter++;
		State Current = Nodes.top();
		Nodes.pop();
		std::vector<ChessBoard*> Descendants = Current.Data->BoardArrGen();
		for (int i = 0; i < Descendants.size() && Flag; i++)
		{
			if (Descendants[i] != nullptr)
			{
				if (!Descendants[i]->ConflictCheck())
				{
					Flag = false;
					SetBoard(Descendants[i]);
				}
				else
				{
					Nodes.push(State(Descendants[i], Current.Depth + 1));
					Counter++;
				}
			}
		}
		delete Current.Data;
		if (MaxCount < Nodes.size())
		{
			MaxCount = Nodes.size();
		}
	}
	while (Nodes.size())
	{
		delete Nodes.top().Data;
		Nodes.pop();
	}
	cout << endl << "Quantity of states " << Counter;
	cout << endl << "Quantity of states in the memory " << MaxCount;
	cout << endl << "Quantity of iterations " << Iter;
}
