#include "ConwayCell.h"

void ConwayCell::GetLivingNeighbors(int r, int c)
{
	// checks Moore neighborhood for living cells and increments count
	if (cell[r][c + 1] == '*')
		++count;
	if (cell[r][c - 1] == '*')
		++count;
	if (cell[r + 1][c] == '*')
		++count;
	if (cell[r - 1][c] == '*')
		++count;
	if (cell[r + 1][c + 1] == '*')
		++count;
	if (cell[r - 1][c - 1] == '*')
		++count;
	if (cell[r + 1][c - 1] == '*')
		++count;
	if (cell[r - 1][c + 1] == '*')
		++count;
}

void ConwayCell::UpdateCells()
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
	count = 0;
}
