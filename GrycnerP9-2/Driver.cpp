#include "LifeCell.h"
#include "ConwayCell.h"
#include "Grycner.h"
#include "Header.h"
#include "ModifiedFredkinCell.h"
#include "Seeds.h"

LifeCell* pLife[5];

ConwayCell con;
FredkinCell fred;
ModifiedFredkinCell modFred;
Seeds seed;
Nelson dog;

pLife[0] = &con;
pLife[1] = &fred;
pLife[2] = &modFred;
pLife[3] = &seed;
pLife[4] = &dog;

int main() {
	int config{}, lifeCount{};
	string patternChoice{};
	string patterns[5] = {"halfmoon.txt", "x.txt", "u.txt", "cross.txt", "line.txt"};

	ShowInfo();

	do {

		cout << "\n\nEnter your choice of cell (enter a number 1-5): ";
		cin >> config;

		cout << "\n\nEnter your choice of initial pattern: ";
		getline(cin, patternChoice);

		do {
			pLife[config]->UpdateBoard();
			cout << pLife[config]->PrintBoard();
			Sleep(150);
			system("cls");
			lifeCount++;
		} while (lifeCount < 200);
	} while (DoAgain());

	Goodbye();

	return 0;
}