#pragma once
// definitions ins Check.cpp, Game.cpp, GetMoves.cpp and Loging.cpp
// merge in Board.cpp

#include <vector>
#include <string>

#include "definitions.hpp"

class Board {
public:
    Board();

    void test();

    // game procedure
    void LoadStartPosition();
    void RequestMove(int x, int y, int newx, int newy);

    // Logging
    void FieldInfo(int x, int y);
    std::string FieldAsString(int x, int y);
    void PrintBoard();

// private:
    std::vector<std::vector<int>> p_board;
    
    // get possible moves
    std::vector<std::pair<int, int>> GetPossibleMoves(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesRook(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKnight(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesBishop(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesQueen(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesKing(int x, int y);
    std::vector<std::pair<int, int>> GetPossibleMovesPawn(int x, int y);
    // actually get moves
    std::vector<std::pair<int, int>> GetStraightMoves(int x, int y);
    std::vector<std::pair<int, int>> GetDiagonalMoves(int x, int y);
    std::vector<std::pair<int, int>> GetKnightMoves(int x, int y);
    std::vector<std::pair<int, int>> GetKingMoves(int x, int y);
    std::vector<std::pair<int, int>> GetPawnMoves(int x, int y);
    
    // check if field is empty, enemy or ally
    int CheckField(Piece &piece, int tocheckx, int tochecky);
    // move piece, overwrite the target field
    void MakeMove(int x, int y, int newx, int newy);
    // get info on piece at x, y
    Piece At(int x, int y);
    // check if empty or enemy and if reachable by piece
    // slow
    bool IsValidMove(int x, int y, int newx, int newy);
    // replace new with old (overwrite)
};
