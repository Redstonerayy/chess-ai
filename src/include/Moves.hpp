#pragma once 

#include <vector>

#include "definitions.hpp"

std::vector<std::vector<int>> p_board;

// get possible moves
std::vector<std::vector<int>> GetAllPossibleMoves(ChessBoard &board, int player);
std::vector<std::pair<int, int>> GetPossibleMoves(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesRook(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesKnight(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesBishop(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesQueen(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesKing(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPossibleMovesPawn(ChessBoard &board, int x, int y);
// actually get moves
std::vector<std::pair<int, int>> GetStraightMoves(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetDiagonalMoves(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetKnightMoves(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetKingMoves(ChessBoard &board, int x, int y);
std::vector<std::pair<int, int>> GetPawnMoves(ChessBoard &board, int x, int y);
