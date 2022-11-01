#include <limits>
#include <iostream>

#include "definitions.hpp"
#include "Info.hpp"
#include "Macros.hpp"

int main() {
    ChessBoard start;
    start.field = startboard;
    start.blackscore = std::numeric_limits<int>::max();
    start.whitescore = std::numeric_limits<int>::min();
    start.turncount = 0;
    start.turning = 1;

    Node rootnode;
    rootnode.board = start;

    PrintBoard(rootnode.board);

    Piece piece = At(rootnode.board.field, 0, 0);

    std::cout << piece.pieceid << "\n";

    return 0;
}
