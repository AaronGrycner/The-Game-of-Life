#include "ModifiedFredkinCell.h"


void ModifiedFredkinCell::UpdateCells()
{
	// goes through each cell and applies fredkin cell rules
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			bool isConway{};

			// updates cell age
			if (cell[i][x] == '*' && age[i][x] < 2)
				++age[i][x];

			// checks if the cell has survived twice
			if (age[i][x] == 2)
				isConway = true;

			GetLivingNeighbors(i, x);

			if (isConway == false) {
				if (cell[i][x] == '*' && count % 2 == 0)
					nextCellState[i][x] = '.';

				else if (cell[i][x] == '.' && count % 2 == 1)
					nextCellState[i][x] = '*';
			}

			else
				Conway(i, x);
		}
	}

	count = 0;
}

void ModifiedFredkinCell::Conway(int r, int c)
{
	// goes through each cell and applies conway cell rules
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			GetLivingNeighbors(i, x);

			if (cell[i][x] == '*') {
				if (count < 2)
					nextCellState[i][x] = '.';
				else if (count > 3)
					nextCellState[i][x] = '.';
			}

			if (cell[i][x] == '.' && count == 3)
				nextCellState[i][x] = '*';
		}
	}
}

void ModifiedFredkinCell::ClearAge()
{
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			age[i][x] = 0;
		}
	}
}
