#pragma once
#include "ChessBoard.h"

struct State
{
	ChessBoard* Data;
	int Depth;
	int Value;
	State(ChessBoard* Input, int Position)
	{
		Data = Input;
		Depth = Position;
		Value = Depth + Data->F1();
	}
};
