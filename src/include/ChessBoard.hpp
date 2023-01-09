#pragma once

#include <cstdint>
#include <vector>
#include <array>

struct ChessBoard {
    std::array<std::array<std::uint8_t, 8>, 8> board;
    std::uint8_t castles;
};

struct Pos {
    std::int8_t x;
    std::int8_t y;
};

struct Move {
    std::int8_t oldx;
    std::int8_t oldy;
    std::int8_t newx;
    std::int8_t newy;
};

void FillBoard(ChessBoard &board);
void FillBoardEmpty(ChessBoard &board);
std::vector<Pos> GetPositionByPiececode(ChessBoard &board, std::uint8_t piececode);
