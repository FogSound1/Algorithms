#include <iostream>
#include <ctime>
#include "ChessBoard.h"
#include <string>
using namespace std;

int main()
{
	ChessBoard chessboard;
	cout << "Starting board:\n";
	chessboard.Generation();
	chessboard.Output();
	int Choice;
	string Check;
	cout << "\nEnter 1 to complete the task with the BFS algorithm\nEnter 2 to complete the task with the A* algorithm";
	//Валідація
	while (Check != "1" && Check != "2")
	{
		cout << "\nEnter the number ";
		getline(cin, Check);

		if (Check != "1" && Check != "2")
		{
			cout << "\nThe input is incorrect, try again";
		}
	}
	Choice = atoll(Check.c_str());
	unsigned int StartTime;
	if (Choice == 1)
	{
		StartTime = clock();
		chessboard.BFS();
	}
	else
	{
		StartTime = clock();
		chessboard.As();
	}
	unsigned int EndTime = clock();
	int S, Ms;
	S = (EndTime - StartTime) / 1000;
	Ms = EndTime - StartTime - S * 1000;
	cout << endl << "Result:";
	cout << endl << "Time spent: " << S << " s " << Ms << " ms" << endl << endl;
	
	chessboard.Output();
}