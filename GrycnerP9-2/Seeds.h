#ifndef SEEDS_H
#define SEEDS_H

#include "LifeCell.h"

class Seeds : public LifeCell
{
private:
	void GetLivingNeighbors(int r, int c);
	void UpdateCells();
};

#endif