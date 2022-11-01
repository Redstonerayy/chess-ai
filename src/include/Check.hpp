#pragma once

#include "definitions.hpp"

// check if field is empty, enemy, ally or out of bounds
int CheckField(ChessBoard &board, int tocheckx, int tochecky);
// move piece, overwrite the target field
void MakeMove(int x, int y, int newx, int newy);
