#include <vector>

#include "Check.hpp"
#include "Macros.hpp"

// check which type of piece is on a certain field given a certain piece
// which wants to move/take
// 0 = can move, is empty
// 1 = can move, is enemy
// 2 = can't move, is allied
// 3 = out of bounds
int CheckField(ChessBoard &board, int tocheckx, int tochecky){
     // check if out of bounds
    if( (tocheckx < 0 || tocheckx > 7) || (tochecky < 0 || tochecky > 7) ) return 3;

    Piece tocheckpiece = At(board.field, tocheckx, tochecky);
    
    if(tocheckpiece.piecevalue == 0) return 0; // empty
    if(board.turning){ // white
        return tocheckpiece.pieceid < 0 ? 1 : 2; 
    } else { // black
        return tocheckpiece.pieceid > 0 ? 1 : 2;
    }
}

// overwrite new with old, set old to 0
void MakeMove(ChessBoard &board, int x, int y, int newx, int newy){
    board.field.at(newy).at(newx) = board.field.at(y).at(x);
    board.field.at(y).at(x) = 0;
}
