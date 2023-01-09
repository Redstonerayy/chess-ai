#pragma once

#include "ChessBoard.hpp"

void PrintBoard(ChessBoard &board);
void PrintMoves(std::vector<Pos> legalmoves, std::vector<Pos> allmoves);
char PiececodeToASCII(std::uint8_t piececode);
Move GetPlayerMove();