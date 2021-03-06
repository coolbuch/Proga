
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{

	srand(time(0));
	int n = 0, playerTurn = 0, compTurn = 0;
	bool isPlayerTurn = true;
	n = rand() % 70 + 31;
	cout << "Hello! Now we will play matches!" << endl;

	while (n > 0)
	{
		isPlayerTurn = true;
		cout << "Number of mathces: " << n << endl;
		cout << "Your turn. You take: ";
		cin >> playerTurn;

		while ((playerTurn > 5 || playerTurn < 1) || playerTurn > n)
		{
			cout << "Incorrect turn. You take: ";
			cin >> playerTurn;
		}
		n -= playerTurn;
		isPlayerTurn = false;
		if (n <= 0) break;
		cout << "Number of matches: " << n << endl;
		cout << "Computer's turn. It takes: ";

		if ((n - 1) % 6 == 0)
			compTurn = rand() % 5 + 1;
		else
			compTurn = (n - 1) % 6;
			
		cout << compTurn << endl;
		n -= compTurn;
		compTurn = 0;
		if (n <= 0) break;
	}

	if (isPlayerTurn) cout << "Player wins!" << endl;
	else cout << "Computer wins!" << endl;
	return 0;
}
