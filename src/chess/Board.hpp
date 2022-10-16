//
// Created by anton on 16/10/22.
//

#ifndef CHESS_AI_BOARD_HPP
#define CHESS_AI_BOARD_HPP

#include <vector>

// white is positive, black negative
// first digit is value, second id of figure
// rook has the value 5 and 1 the id of figure
// rook = (-)51, knight = (-)32, bishop = (-)33, queen = (-)94, king = (-)05, pawn = (-)16

const std::vector<std::vector<int>> StartBoard = {
        {-51, -32, -33, -94, -05, -33, -32, -51},
        {-16, -16, -16, -16, -16, -16, -16, -16},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {51, 32, 33, 94, 05, 33, 32, 51},
        {16, 16, 16, 16, 16, 16, 16, 16},
};

class Board {
public:
    Board();

    void LoadPosition();
    void PrintBoard();
private:
    std::vector<std::vector<int>> p_board;
};


#endif //CHESS_AI_BOARD_HPP
