#include "chess.hpp"
#include <iostream>

int main() {
    Board board = Board();
    // board.PrintBoard();
    
    std::vector<std::vector<int>> moves = board.GetAllPossibleMoves(1);
    // for(auto move : moves){
    //     std::cout << move.at(0) << ":" << move.at(1) << " to " << move.at(2) << ":" << move.at(3) << std::endl;
    // }
    board.PrintBoardMoves(moves);
    board.GetPlayerMoveInput();
    board.PrintBoard();

    return 0;
}
