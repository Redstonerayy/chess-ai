#pragma once

#include <vector>

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
