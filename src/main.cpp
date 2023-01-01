#include "ChessBoard.hpp"
#include "Terminal.hpp"
#include "Moves.hpp"

#include <iostream>

int main() {
    ChessBoard mainboard;
    FillBoard(mainboard);
    PrintBoard(mainboard);
    // for(int8_t i = 0; i < 8; ++i){
    //     std::cout << (int)i << ":" << 6 << "\n";
    //     std::vector<std::vector<Pos>> moves = GetPawnMoves(mainboard, Pos{i, 6});
    //     PrintMoves(moves.at(0), moves.at(1));
    // }
    std::vector<std::vector<Pos>> moves = GetRookMoves(mainboard, Pos{0, 0});
    PrintMoves(moves.at(0), moves.at(1));
    return 0;
}
