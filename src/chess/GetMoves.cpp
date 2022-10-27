#include "Board.hpp"

#include <vector>

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

//functions to get moves for each different piece
std::vector<std::pair<int, int>> Board::GetPossibleMovesRook(int x, int y){
    return this->GetStraightMoves(x, y);
}

std::vector<std::pair<int, int>> Board::GetPossibleMovesKnight(int x, int y){
    return this->GetKnightMoves(x, y);
}

std::vector<std::pair<int, int>> Board::GetPossibleMovesBishop(int x, int y){
    return this->GetDiagonalMoves(x, y);
}

std::vector<std::pair<int, int>> Board::GetPossibleMovesQueen(int x, int y){
    std::vector<std::pair<int, int>> straight = this->GetStraightMoves(x, y);
    std::vector<std::pair<int, int>> diagonal = this->GetDiagonalMoves(x, y);
    // add two vectors
    straight.insert( straight.end(), diagonal.begin(), diagonal.end());
    return straight;
}

std::vector<std::pair<int, int>> Board::GetPossibleMovesKing(int x, int y) {
    return this->GetKingMoves(x, y);
}

std::vector<std::pair<int, int>> Board::GetPossibleMovesPawn(int x, int y) {
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
