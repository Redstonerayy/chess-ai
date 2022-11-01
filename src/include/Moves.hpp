#pragma once 

#include <vector>

#include "definitions.hpp"

// get possible moves
std::vector<Move> GetAllPossibleMoves(ChessBoard &board, int player);
std::vector<Move> GetPossibleMoves(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesRook(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesKnight(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesBishop(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesQueen(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesKing(ChessBoard &board, int x, int y);
std::vector<Move> GetPossibleMovesPawn(ChessBoard &board, int x, int y);
// actually get moves
std::vector<Move> GetStraightMoves(ChessBoard &board, int x, int y);
std::vector<Move> GetDiagonalMoves(ChessBoard &board, int x, int y);
std::vector<Move> GetKnightMoves(ChessBoard &board, int x, int y);
std::vector<Move> GetKingMoves(ChessBoard &board, int x, int y);
std::vector<Move> GetPawnMoves(ChessBoard &board, int x, int y);
