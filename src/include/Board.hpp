//
// Created by anton on 16/10/22.
//

#ifndef CHESS_AI_BOARD_HPP
#define CHESS_AI_BOARD_HPP

#include <vector>
#include <string>

// white is positive, black negative
// first digit is value, second id of piece
// rook has the value 5 and 1 the id of piece
// rook = (-)51, knight = (-)32, bishop = (-)33, queen = (-)94, king = (-)05, pawn = (-)16
const std::vector<std::vector<int>> StartBoard = {
        { -51, -32, -33, -94, -05, -33, -32, -51},
        { -16, -16, -16, -16, -16, -16, -16, -16},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {  16,  16,  16,  16,  16,  16,  16,  16},
        {  51,  32,  33,  94,  05,  33,  32,  51},
};

// hold piece info
struct Piece {
    int pieceid;
    int piecevalue;
};

// offset positons for knight, 8 possible fields
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

// white perspective, invert for black perspective
const std::vector<int> pawnoffsets = {
        0, -1,
        0, -2,
        -1, -1,
        1, -1,
};

// enum for pieces
enum {
    EMPTY = 0,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN,
};

class Board {
public:
    Board();

    void LoadStartPosition();
    void RequestMove(int x, int y, int newx, int newy);
    // Logging
    void FieldInfo(int x, int y);
    std::string FieldAsString(int x, int y);
    void PrintBoard();

private:
    std::vector<std::vector<int>> p_board;
    // get possible moves
    std::vector<std::pair<int, int>> GetPossibleMoves(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesRook(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKnight(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesBishop(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesQueen(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKing(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesPawn(int x, int y);
    // check moves
    std::vector<std::pair<int, int>> GetStraightMoves(int x, int y);
    std::vector<std::pair<int, int>> GetDiagonalMoves(int x, int y);
    std::vector<std::pair<int, int>> GetKnightMoves(int x, int y);
    std::vector<std::pair<int, int>> GetKingMoves(int x, int y);
    std::vector<std::pair<int, int>> GetPawnMoves(int x, int y);
    // check if field is empty, enemy or ally
    int CheckField(Piece &piece, int tocheckx, int tochecky);
    // check if empty or enemy and if reachable by piece
    bool IsValidMove(int x, int y, int newx, int newy);
    // replace new with old (overwrite)
    void MakeMove(int x, int y, int newx, int newy);
    // get info on piece at x, y
    Piece At(int x, int y);
};

#endif //CHESS_AI_BOARD_HPP
