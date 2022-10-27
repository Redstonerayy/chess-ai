#include "Board.hpp"

#include <algorithm>

// check which type of piece is on a certain field given a certain piece
// which wants to move/take
// 0 = can move, is empty
// 1 = can move, is enemy
// 2 = can't move, is allied
int Board::CheckField(Piece &piece, int tocheckx, int tochecky){
    Piece tocheckpiece = this->At(tocheckx, tochecky);
    if (tocheckpiece.pieceid != EMPTY){
        // check for enemy
        if( (tocheckpiece.pieceid > 0 && piece.pieceid < 0) ||
            (tocheckpiece.pieceid < 0 && piece.pieceid > 0) ){
            return 1;
        }
        return 2;
    } else {
        return 0;
    }
}

// get all moves for piece and check them against a certain field
bool Board::IsValidMove(int x, int y, int newx, int newy) {
    std::vector<std::pair<int, int>> possiblemoves = this->GetPossibleMoves(x, y);
//    for (auto & possiblemove : possiblemoves) {
//        if(possiblemove.first == newx && possiblemove.second == newy){
//            return true;
//        }
//    }
    std::ranges::any_of(
        possiblemoves.cbegin(),
        possiblemoves.cend(),
        [newx, newy](auto & possiblemove){ return possiblemove.first == newx && possiblemove.second == newy; }
        );
    return false;
}

// overwrite new with old, set old to 0
void Board::MakeMove(int x, int y, int newx, int newy){
    this->p_board[newy][newx] = this->p_board[y][x];
    this->p_board[y][x] = 0;
}

// get info on piece at x, y
Piece Board::At(int x, int y){
    Piece piece{-1, -1};
    piece.pieceid = this->p_board[y][x];
    piece.piecevalue = abs(int(piece.pieceid % 10));
    return piece;
}