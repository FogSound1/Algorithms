#include "Tree.h"

Tree::Tree(ChessBoard* data, int Num)
{
	Data = data;
	Descendants = Num;
	Node = new Tree * [Descendants];
	for (int i = 0; i < Descendants; i++)
	{
		Node[i] = NULL;
	}
}

Tree* Tree::Insert(ChessBoard* data, int Position)
{
	Node[Position] = new Tree(data, Descendants);
	return Node[Position];
}

ChessBoard* Tree::GetData()
{
	return Data;
}

int Tree::GetDescendants()
{
	return Descendants;
}

Tree* Tree::GetDescendant(int Num)
{
	return Node[Num];
}

void Tree::DeleteBranch(Tree* Node, int& Counter)
{
	if (Node == NULL)
	{
		return;
	}

	Counter++;

	for (int i = 0; i < Descendants; i++)
	{
		DeleteBranch(Node->GetDescendant(i), Counter);
	}

	delete Node;
}

int Tree::Clear()
{
	int Counter = 0;
	for (int i = 0; i < Descendants; i++)
	{
		DeleteBranch(Node[i], Counter);
		Node[i] = NULL;
	}
	return Counter;
}

Tree::~Tree()
{
	delete Data;
	delete[Descendants] Node;
};