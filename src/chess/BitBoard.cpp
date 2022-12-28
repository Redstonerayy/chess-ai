#include "BitBoard.hpp"

#include <cstdint>

BitBoard MakeStartField(){
    // startfield
    BitBoard startfield;
    // white pieces
    startfield.whitePawns = 65280;
    startfield.whiteKnights = 66;
    startfield.whiteBishops = 36;
    startfield.whiteRooks = 129;
    startfield.whiteQueens = 16;
    startfield.whiteKing = 8;
    // black pieces
    startfield.blackPawns = 71776119061217280;
    startfield.blackKnights = 4755801206503243776;
    startfield.blackBishops = 2594073385365405696;
    startfield.blackRooks = 9295429630892703744;
    startfield.blackQueens = 1152921504606846976;
    startfield.blackKing = 576460752303423488;

    return startfield;
}
