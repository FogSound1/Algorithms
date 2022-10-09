#include "FileFunctions.h"
#include <string>

int main()
{
	srand(time(NULL));
	
	int Choice, Size;
	string FileName, EndFile;

	for (int i = 0; ; i++)
	{
		cout << "Enter 1 to create a file\nEnter 2 to read a file\nEnter 3 to sort a file\nEnter anything else to exit\nEnter the number ";
		cin >> Choice;
		if (Choice == 1)
		{
			cout << "Enter the name of the file ";
			cin.ignore();
			getline(cin, FileName);
			cout << endl << "Enter the size of the file in mb ";
			cin >> Size;
			FileCreate(FileName, Size * 131072);
			cout << "File " << FileName << " is created" << endl;
		}
		else if (Choice == 2)
		{
			cin.ignore();
			cout << "Enter the name of file: ";
			getline(cin, FileName);
			cout << "Enter the the quantity of displayed numbers ";
			cin >> Size;
			FileRead(FileName, Size);
			cout << endl;
		}
		else if (Choice == 3)
		{
			if (FileName == "")
			{
				cout << "Enter the name of the file ";
				cin.ignore();
				getline(cin, FileName);
			}

			for (int i = 0;; i++)
			{
				cout << "Enter the number of files to divide the original one from 2 to 10 ";
				cin >> Size;
				if (Size < 2 || Size > 10)
				{
					cout << "\nIncorrect input, please try again" << endl;
				}
				else
				{
					break;
				}
			}
			EndFile = FileSort(Size, FileName);
			cout << "The file is sorted, to check the results, read the file " << EndFile << "1.txt\n\n";
		}
		else
		{
			break;
		}
	}
}
