#include "chess.hpp"
#include <iostream>

int main() {
    Board board = Board();
    board.PrintBoard();
    
    

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            board.FieldInfo(i, j);
            std::vector<std::pair<int, int>> moves = board.GetPossibleMoves(i, j);
            for(auto move : moves){
                std::cout << move.first << ":" << move.second << std::endl;
            }
        }
    }

    return 0;
}
