//
// Created by anton on 16/10/22.
//

#ifndef CHESS_AI_BOARD_HPP
#define CHESS_AI_BOARD_HPP

#include <vector>

// white is positive, black negative
// first digit is value, second id of piece
// rook has the value 5 and 1 the id of piece
// rook = (-)51, knight = (-)32, bishop = (-)33, queen = (-)94, king = (-)05, pawn = (-)16

struct Piece {
    int pieceid;
    int piecevalue;
};

const std::vector<int> knightoffsets = {
        // left
        -3,  1,
        -3, -1,
        // up
        -1, -3,
         1, -3,
        // right
         3, -1,
         3,  1,
        // down
         1,  3,
        -1,  3,
};

enum {
    EMPTY = 0,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN,
};

const std::vector<std::vector<int>> StartBoard = {
        { -51, -32, -33, -94, -05, -33, -32, -51},
        { -16, -16, -16, -16, -16, -16, -16, -16},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {  51,  32,  33,  94,  05,  33,  32,  51},
        {  16,  16,  16,  16,  16,  16,  16,  16},
};

class Board {
public:
    Board();

    void LoadStartPosition();
    void RequestMove(int x, int y, int newx, int newy);
    // Logging
    void FieldInfo(int x, int y);
    void PrintBoard();

private:
    std::vector<std::vector<int>> p_board;
    std::vector<std::pair<int, int>> GetPossibleMoves(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesRook(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKnight(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesBishop(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesQueen(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKing(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesPawn(int x, int y);
    std::vector<std::pair<int, int>> GetStraightMoves(int x, int y);
    std::vector<std::pair<int, int>> GetDiagonalMoves(int x, int y);
    std::vector<std::pair<int, int>> GetKnightMoves(int x, int y);
    int CheckField(Piece &piece, int tocheckx, int tochecky);
    bool IsValidMove(int x, int y, int newx, int newy);
    void MakeMove(int x, int y, int newx, int newy);
    Piece At(int x, int y);
};


#endif //CHESS_AI_BOARD_HPP
