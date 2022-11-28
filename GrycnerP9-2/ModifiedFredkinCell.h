#ifndef MODIFIEDFREDKINCELL_H
#define MODIFIEDFREDKINCELL_H

#include "FredkinCell.h"
class ModifiedFredkinCell : public FredkinCell
{
private:
    int age[ROWS][COLS];
    void UpdateCells();
    void Conway(int r, int c);

public:
    ModifiedFredkinCell() { ClearAge(); }
    void ClearAge();
};

#endif