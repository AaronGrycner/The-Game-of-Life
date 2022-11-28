#ifndef CONWAYCELL_H
#define CONWAYCELL_H

#include "LifeCell.h"
class ConwayCell : public LifeCell
{
private:
	void GetLivingNeighbors(int r, int c);
	void UpdateCells();
};

#endif