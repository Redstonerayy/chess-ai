#include "ChessBoard.hpp"

#include <cstdint>
#include <vector>

// 0 = empty
// white = 1,2,3,4,5,6 //pawn, rook, knight, bishop, queen, king
// black = 11,12,13,14,15,16 //pawn, rook, knight, bishop, queen, king
void FillBoard(ChessBoard &board){
    board.board.at(0) = { 12, 13, 14, 15, 16, 15, 13, 12};
    board.board.at(1) = { 11, 11, 11, 11, 11, 11, 11, 11};
    board.board.at(2) = {  0,  0,  0,  0,  0,  0,  0,  0};
    board.board.at(3) = {  0,  0,  0,  0,  0,  0,  0,  0};
    board.board.at(4) = {  0,  0,  0,  0,  0,  0,  0,  0};
    board.board.at(5) = {  0,  0,  0,  0,  0,  0,  0,  0};
    board.board.at(6) = {  1,  1,  1,  1,  1,  1,  1,  1};
    board.board.at(7) = {  2,  3,  4,  5,  6,  4,  3,  2};
    board.castles = 0;
}

void FillBoardEmpty(ChessBoard &board){
    board.board.at(0) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(1) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(2) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(3) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(4) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(5) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(6) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.board.at(7) = std::array<uint8_t, 8>{}; // initialize with zeros
    board.castles = 0;
}

std::vector<Pos> GetPositionByPiececode(ChessBoard &board, std::uint8_t piececode){
    std::vector<Pos> occurences;
    for(std::int8_t y = 0; y < 8; ++y){
        for(std::int8_t x = 0; x < 8; ++x){
            if( board.board.at(y).at(x) == piececode)
                occurences.emplace_back(Pos{x, y});
        }
    }
    return occurences;
}