#pragma once

#include <vector>
#include <string>

#include "definitions.hpp"

// Logging
void FieldInfo(ChessBoard &board, int x, int y);
std::string FieldAsString(ChessBoard &board, int x, int y);
void PrintBoard(ChessBoard &board);
void PrintBoardMoves(ChessBoard &board);
