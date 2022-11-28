#include "FredkinCell.h"

void FredkinCell::UpdateCells()
{
	// goes through each cell and applies fredkin cell rules
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			GetLivingNeighbors(i, x);

			if (cell[i][x] == '*' && count % 2 == 0)
				nextCellState[i][x] = '.';

			else if (cell[i][x] == '.' && count % 2 == 1)
				nextCellState[i][x] = '*';

		}
	}
	count = 0;
}
