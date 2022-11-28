#include "LifeCell.h"

const int ROWS = 45;
const int COLS = 78;

void LifeCell::InitializeBoard()
{
	string temp{};
	ifstream input{ pattern };

	if (!input) {
		bOpen = false;
		return;
	}

	// trash first two lines
	getline(input, temp);
	getline(input, temp);

	// read each row into temp and then into cell
	for (int i{}; i < ROWS; ++i) {
		getline(input, temp);
		for (int x{}; x < COLS; ++x) {
			cell[i][x] = temp.at(x);
		}
	}
}

void LifeCell::GetLivingNeighbors(int r, int c)
{
	// checks von neumann neighborhood for living cells and increments count
	if (cell[r][c + 1] == '*')
		++count;
	if (cell[r][c - 1] == '*')
		++count;
	if (cell[r + 1][c] == '*')
		++count;
	if (cell[r - 1][c] == '*')
		++count;
}

void LifeCell::SetNextState()
{
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			cell[i][x] = nextCellState[i][x];
			nextCellState[i][x] = '.';
		}
	}
}

void LifeCell::SetPattern(string pat)
{
	pattern = pat;
	InitializeBoard();
}

void LifeCell::UpdateBoard()
{
	UpdateCells();
	SetNextState();
}

string LifeCell::PrintBoard()
{
	stringstream st;

	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			st << cell[i][x];
		}
	}

	return st.str();
}

void LifeCell::Clear()
{
	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			cell[i][x] = '.';
		}
	}

	for (int i{}; i < ROWS; ++i) {
		for (int x{}; x < COLS; ++x) {
			nextCellState[i][x] = '.';
		}
	}
}
