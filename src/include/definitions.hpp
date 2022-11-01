#pragma once

#include <vector>

// white is positive, black negative
// first digit is value, second id of piece
// rook has the value 5 and 1 the id of piece
// rook = (-)51, knight = (-)32, bishop = (-)33, queen = (-)94, king = (-)05, pawn = (-)16
const std::vector<std::vector<int>> startboard = {
        { -51, -32, -33, -94, -05, -33, -32, -51},
        { -16, -16, -16, -16, -16, -16, -16, -16},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {   0,   0,   0,   0,   0,   0,   0,   0},
        {  16,  16,  16,  16,  16,  16,  16,  16},
        {  51,  32,  33,  94,  05,  33,  32,  51},
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
        0, -2, // first so it can be skipped easily
        0, -1,
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

// hold piece info
struct Piece {
    int pieceid;
    int piecevalue;
};

struct Move {
    int startx;
    int starty;
    int newx;
    int newy;

    // possible ctor, but Move{x,y,x,y} can also be used
    // behaviour of structs and emplace_back changed in c++ 20
    // @https://stackoverflow.com/questions/13812703/c11-emplace-back-on-vectorstruct
    // Move(int startx, int stary, int newx, int newy)
    //     : startx(startx)
    //     , starty(starty)
    //     , newx(newx)
    //     , newy(newy)
    // {}
};

struct ChessBoard {
    std::vector<std::vector<int>> field;
    std::vector<Move> moves;
    int turncount;
    int whitescore;
    int blackscore;
    int turning;
};

struct Node {
    ChessBoard board;
    std::vector<ChessBoard> childnodes;
};
