#include "chess.hpp"
#include <iostream>

int main() {
    Board board = Board();
    board.PrintBoard();
    board.test();
    // std::vector<std::pair<int, int>> moves = board.GetPossibleMoves(0, 0);
    // for(auto move : moves){
    //     std::cout << move.first << ":" << move.second << std::endl;
    // }
    return 0;
}
