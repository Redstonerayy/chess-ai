//
// Created by anton on 16/10/22.
//

#include "Board.hpp"

#include <iostream>

Board::Board() {
    this->LoadPosition();
}

void Board::LoadPosition() {
    this->p_board = StartBoard;
}

void Board::PrintBoard() {
    for (std::vector<int> &row : this->p_board) {
        for (int field : row) {
            std::cout << field << " ";
        }
        std::cout << "\n";
    }
}
