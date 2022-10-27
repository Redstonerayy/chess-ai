// needed for intellisense to work
#include "Board.hpp"

Board::Board() {
    this->LoadStartPosition();
}

void Board::LoadStartPosition() {
    this->p_board = StartBoard;
}

void Board::RequestMove(int x, int y, int newx, int newy){
}
