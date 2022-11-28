#include "Header.h"

void ShowInfo() {

	cout << "\nWelcome to The Game of Life!\n"
		<< "\n ~ Watch as cells reproduce and die like real organisms in nature"
		<< "\n ~ Different cell types have different rules"
		<< "\n ~ The shape of the starting cells will determine how the rest of the game plays out"
		<< "\n ~ There are five different cell types"
		<< "\n 1. The Conway cell: "
		<< "\n    Any live cell with fewer than two live neighbors dies, as if caused by under-population."
		<< "\n	  Any live cell with two or three live neighbors lives on to the next generation."
		<< "\n	  Any live cell with more than three live neighbors dies, as if by overcrowding."
		<< "\n    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction."
		<< "\n\n 2. The Fredkin Cell: "
		<< "\n    A dead cell becomes a live cell if 1 or 3 neighbors are alive."
		<< "\n    A live cell becomes a dead cell if 0, 2, or 4 neighbors are alive."
		<< "\n    Otherwise, the cell stays the same."
		<< "\n 3. The Modified Fredkin Cell: "
		<< "\n    Similar to Fredkin Cell, but after two generations"
		<< "\n    it becomes a Conway Cell."
		<< "\n 4. The Seeds Cell: "
		<< "\n    A dead cell becomes a live cell if exactly 2 neighbors are alive."
		<< "\n    All other cells become dead."
		<< "\n 5. The Grycner Cell: "
		<< "\n    ...";
}

bool DoAgain() {
	string yesNo{};

	cout << "\nWould you like to play again? (y/n): ";
	cin >> yesNo;
	
	if (yesNo == "n")
		return false;

	return true;
}

void Goodbye() {
	cout << "\nNow exiting program. Goodbye!\n";
}