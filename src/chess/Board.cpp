//
// Created by anton on 16/10/22.
//

// needed for intellisense to work
#include "../include/Board.hpp"

#include <iostream>  // logging
#include <cmath> // abs
#include <algorithm> // std::range::any_of()

Board::Board() {
    this->LoadStartPosition();
}

void Board::LoadStartPosition() {
    this->p_board = StartBoard;
}

void Board::RequestMove(int x, int y, int newx, int newy){
}

// check what piece is on field
// call matching function and
// return moves of this piece
std::vector<std::pair<int, int>> Board::GetPossibleMoves(int x, int y) {
    Piece pieceinfo = this->At(x,y); // get info on piece
    if(pieceinfo.pieceid == 0) return {};
    switch (pieceinfo.pieceid) {
        case 1: // rook
            return GetPossibleMovesRook(x, y);
            break;
        case 2: // knight
            return GetPossibleMovesKnight(x, y);
            break;
        case 3: // bishop
            return GetPossibleMovesBishop(x, y);
            break;
        case 4: // queen
            return GetPossibleMovesQueen(x, y);
            break;
        case 5: // king
            return GetPossibleMovesKing(x, y);
            break;
        case 6: // pawn
            return GetPossibleMovesPawn(x, y);
            break;
    }
    return {};
}

// inline functions to get moves for each different piece
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
    return this->GetKingMoves(x, y);
}

inline std::vector<std::pair<int, int>> Board::GetPossibleMovesPawn(int x, int y) {
    return this->GetPawnMoves(x, y);
}

// actually check if a piece with certain can move straight or diagonal
// and which fields can be reached
// use predefined offsets for pawn and knight
// for loops for king
std::vector<std::pair<int, int>> Board::GetStraightMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    // check x row left
    for (int i = x - 1; i >= 0; --i) {
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
    for (int i = y - 1; i >= 0; --i) {
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
    for (int i = x - 1; i >= 0; --i) {
        for (int j = y - 1; j >= 0; --j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }
    // check left down
    for (int i = x - 1; i >= 0; --i) {
        for (int j = y + 1; j < 8; ++j) {
            int check = this->CheckField(piece, i, j);
            if(check == 0) moves.emplace_back( i, j );
            if(check == 1) moves.emplace_back( i, j );
        }
    }
    // check right up
    for (int i = x + 1; i < 8; ++i) {
        for (int j = y - 1; j >= 0; --j) {
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

std::vector<std::pair<int, int>> Board::GetPawnMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    // factor to make it fit for either side
    int factor = -1;
    if(piece.pieceid > 0){
        factor = 1;
    }
    for (int i = 0; i < pawnoffsets.size(); i += 2) {
        std::vector<int> cords = { x + pawnoffsets[i] * factor, y + pawnoffsets[i + 1] * factor };
        int check = this->CheckField(piece, cords[0], cords[1] );
        if(check == 0) moves.emplace_back( cords[0], cords[1] );
        if(check == 1) moves.emplace_back( cords[0], cords[1] );
    }
    return moves;
}

std::vector<std::pair<int, int>> Board::GetKingMoves(int x, int y) {
    Piece piece = this->At(x, y);
    std::vector<std::pair<int, int>> moves;
    for (int i = x - 1; i < x + 2; ++i) {
        for (int j = y - 1; j < y + 2; ++j) {
            if( 0 <= x && x < 8 && 0 <= y && y < 8){
                int check = this->CheckField( piece, i, j );
                if(check == 0) moves.emplace_back( i, j );
                if(check == 1) moves.emplace_back( i, j );
                // if check return 2, it checks the field where king is on
            }
        }
    }
    return moves;
}

// check which type of piece is on a certain field given a certain piece
// which wants to move/take
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

// get all moves for piece and check them against a certain field
inline bool Board::IsValidMove(int x, int y, int newx, int newy) {
    std::vector<std::pair<int, int>> possiblemoves = this->GetPossibleMoves(x, y);
//    for (auto & possiblemove : possiblemoves) {
//        if(possiblemove.first == newx && possiblemove.second == newy){
//            return true;
//        }
//    }
    std::ranges::any_of(
        possiblemoves.cbegin(),
        possiblemoves.cend(),
        [newx, newy](auto & possiblemove){ return possiblemove.first == newx && possiblemove.second == newy; }
        );
    return false;
}

// overwrite new with old, set old to 0
inline void Board::MakeMove(int x, int y, int newx, int newy){
    this->p_board[newy][newx] = this->p_board[y][x];
    this->p_board[y][x] = 0;
}

// get info on piece at x, y
inline Piece Board::At(int x, int y){
    Piece piece{-1, -1};
    piece.pieceid = this->p_board[y][x];
    piece.piecevalue = abs(int(piece.pieceid % 10));
    return piece;
}

// print info on piece on field x, y
void Board::FieldInfo(int x, int y){
    int piece = this->p_board[y][x];
    int value = abs(int(piece / 10));
    bool uppercase = true; // white is uppercase
    if (piece < 0){
        uppercase = false;
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

// print info on piece on field x, y
std::string Board::FieldAsString(int x, int y){
    int piece = this->p_board[y][x];
    bool uppercase = true; // white is uppercase
    if (piece < 0){
        uppercase = false;
    }
    switch (abs(int(piece % 10))) {
        case 0:
            return " ";
            break;
        case 1:
            if(uppercase) return "R";
            return "r";
            break;
        case 2:
            if(uppercase) return "N";
            return "n";
            break;
        case 3:
            if(uppercase) return "B";
            return "b";
            break;
        case 4:
            if(uppercase) return "Q";
            return "q";
            break;
        case 5:
            if(uppercase) return "K";
            return "k";
            break;
        case 6:
            if(uppercase) return "P";
            return "p";
            break;
        default:
            if(uppercase) return " ";
            return " ";
            break;
    }
}

// print board
void Board::PrintBoard() {
    for (int i = 0; i < this->p_board.size(); ++i) {
        std::cout << "| ";
        for (int j = 0; j < this->p_board[i].size(); ++j) {
            std::cout << this->FieldAsString(j, i) << " | ";
        }
        std::cout << "\n";
    }
}
