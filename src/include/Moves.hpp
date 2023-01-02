#pragma once

#include "ChessBoard.hpp"

bool IsEnemy(ChessBoard &board, Pos pos, bool direction);
void AddMove(ChessBoard &board, Pos newpos, bool direction, bool &blocked, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves);
void GetStraightMoves(ChessBoard &board, Pos pos, bool direction, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves);
void GetDiagonalMoves(ChessBoard &board, Pos pos, bool direction, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves);
std::vector<std::vector<Pos>> GetPawnMoves(ChessBoard &board, Pos pos);
std::vector<std::vector<Pos>> GetRookMoves(ChessBoard &board, Pos pos);
std::vector<std::vector<Pos>> GetKnightMoves(ChessBoard &board, Pos pos);
std::vector<std::vector<Pos>> GetBishopMoves(ChessBoard &board, Pos pos);
std::vector<std::vector<Pos>> GetQueenMoves(ChessBoard &board, Pos pos);
std::vector<std::vector<Pos>> GetKingMoves(ChessBoard &board, Pos pos);
