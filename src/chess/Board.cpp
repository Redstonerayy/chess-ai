//
// Created by anton on 16/10/22.
//

#include "../include/Board.hpp"

#include <iostream>
#include <cmath>

Board::Board() {
    this->LoadStartPosition();
}

void Board::LoadStartPosition() {
    this->p_board = StartBoard;
}

void Board::RequestMove(int x, int y, int newx, int newy){
}

std::vector<std::pair<int, int>> Board::GetPossibleMoves(int x, int y) {
    Piece pieceinfo = this->At(x,y); // get info on piece
    if(pieceinfo.pieceid == 0) return {};
    switch (pieceinfo.pieceid) {
        case 1: // rook

            break;
        case 2: // knight
            std::cout << "KNIGHT";
            break;
        case 3: // bishop
            std::cout << "BISHOP";
            break;
        case 4: // queen
            std::cout << "QUEEN";
            break;
        case 5: // king
            std::cout << "KING";
            break;
        case 6: // pawn
            std::cout << "PAWN";
            break;
    }
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesRook(int x, int y){
    return this->GetStraightMoves(x, y);
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesKnight(int x, int y){
    return this->GetKnightMoves(x, y);
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesBishop(int x, int y){
    return this->GetDiagonalMoves(x, y);
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesQueen(int x, int y){
    std::vector<std::pair<int, int>> straight = this->GetStraightMoves(x, y);
    std::vector<std::pair<int, int>> diagonal = this->GetDiagonalMoves(x, y);
    // add two vectors
    straight.insert( straight.end(), diagonal.begin(), diagonal.end());
    return straight;
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesKing(int x, int y) {
    this->GetKingMoves(x, y);
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesPawn(int x, int y) {
    this->GetPawnMoves(x, y);
}

std::vector<std::pair<int, int>> Board::GetStraightMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    // check x row left
    for (int i = x - 1; i > 0; --i) {
        int check = this->CheckField(piece, i, y);
        if(check == 0) moves.emplace_back( i, y );
        if(check == 1) moves.emplace_back( i, y );
    }
    // check x row right
    for (int i = x + 1; i < 8; ++i) {
        int check = this->CheckField(piece, i, y);
        if(check == 0) moves.emplace_back( i, y );
        if(check == 1) moves.emplace_back( i, y );
    }
    // check y row up
    for (int i = y - 1; i > 0; --i) {
        int check = this->CheckField(piece, x, i);
        if(check == 0) moves.emplace_back( x, i );
        if(check == 1) moves.emplace_back( x, i );
    }
    // check y row down
    for (int i = y + 1; i < 8; ++i) {
        int check = this->CheckField(piece, x, i);
        if(check == 0) moves.emplace_back( x, i );
        if(check == 1) moves.emplace_back( x, i );
    }

    return moves;
}

std::vector<std::pair<int, int>> Board::GetDiagonalMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    // check left up
    for (int i = x - 1; i > 0; --i) {
        for (int j = y - 1; j > 0; --j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }
    // check left down
    for (int i = x - 1; i > 0; --i) {
        for (int j = y + 1; j < 8; ++j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }
    // check right up
    for (int i = x + 1; i < 8; ++i) {
        for (int j = y - 1; j > 0; --j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }
    // check right down
    for (int i = x + 1; i < 8; ++i) {
        for (int j = y + 1; j < 8; ++j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }

    return moves;
}

std::vector<std::pair<int, int>> Board::GetKnightMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < knightoffsets.size(); i += 2) {
        std::vector<int> cords = { x + knightoffsets[i], y + knightoffsets[i + 1] };
        int check = this->CheckField(piece, cords[0], cords[1] );
        if(check == 0) moves.emplace_back( cords[0], cords[1] );
        if(check == 1) moves.emplace_back( cords[0], cords[1] );
    }
    return moves;
}

// 0 = can move, is empty
// 1 = can move, is enemy
// 2 = can't move, is allied
inline int Board::CheckField(Piece &piece, int tocheckx, int tochecky){
    Piece tocheckpiece = this->At(tocheckx, tochecky);
    if (tocheckpiece.pieceid != EMPTY){
        // check for enemy
        if( (tocheckpiece.pieceid > 0 && piece.pieceid < 0) ||
            (tocheckpiece.pieceid < 0 && piece.pieceid > 0) ){
            return 1;
        }
        return 2;
    } else {
        return 0;
    }
}

inline bool Board::IsValidMove(int x, int y, int newx, int newy) {
    return true;
}

inline void Board::MakeMove(int x, int y, int newx, int newy){
    this->p_board[newy][newx] = this->p_board[y][x];
    this->p_board[y][x] = 0;
}

inline Piece Board::At(int x, int y){
    Piece piece{-1, -1};
    piece.pieceid = this->p_board[y][x];
    piece.piecevalue = abs(int(piece.pieceid % 10));
    return piece;
}

void Board::FieldInfo(int x, int y){
    int piece = this->p_board[y][x];
    int value = abs(int(piece / 10));
    if (piece < 0){
        std::cout << "BLACK ";
    } else {
        std::cout << "WHITE ";
    }
    switch (abs(piece % 10)) {
        case 0:
            std::cout << "EMPTY";
            break;
        case 1:
            std::cout << "ROOK";
            break;
        case 2:
            std::cout << "KNIGHT";
            break;
        case 3:
            std::cout << "BISHOP";
            break;
        case 4:
            std::cout << "QUEEN";
            break;
        case 5:
            std::cout << "KING";
            break;
        case 6:
            std::cout << "PAWN";
            break;
        default:
            std::cout << "UNKNOWN";
            break;
    }
    std::cout << " VALUE: " << value << "\n";
}

void Board::PrintBoard() {
    for (std::vector<int> &row : this->p_board) {
        for (int field : row) {
            std::cout << field << " ";
        }
        std::cout << "\n";
    }
}
