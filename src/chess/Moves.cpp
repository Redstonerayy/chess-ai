#include "definitions.hpp"
#include "Moves.hpp"
#include "Macros.hpp"
#include "Check.hpp"

#include <vector>
#include <cmath>
#include <iostream>

// get all possible moves
std::vector<Move> GetAllPossibleMoves(ChessBoard &board, int player){ // 0 = black, 1 = white
	std::vector<Move> allmoves;
	for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            Piece piece = At(board.field, i, j);
			if( (piece.pieceid > 0 && player) || (piece.pieceid < 0 && !player) ){ // if piece matches color
				std::vector<Move> moves = GetPossibleMoves(board, i, j);
				for(int k = 0; k < moves.size(); ++k){
                    // std::cout << moves.at(k).first << ":" << moves.at(k).second << std::endl;
					allmoves.insert(allmoves.begin(), moves.begin(), moves.end()); // from x,y to x,y
				}
			}
        }
    }

    return allmoves;
}


// check what piece is on field
// call matching function and
// return moves of this piece
std::vector<Move> GetPossibleMoves(ChessBoard &board, int x, int y) {
    Piece pieceinfo = At(board.field, x,y); // get info on piece
    // std::cout << pieceinfo.pieceid << std::endl;
	if(pieceinfo.pieceid == 0) return {};
    switch (std::abs(pieceinfo.pieceid % 10)) {
        case 1: // rook
            return GetPossibleMovesRook(board, x, y);
            break;
        case 2: // knight
            return GetPossibleMovesKnight(board, x, y);
            break;
        case 3: // bishop
            return GetPossibleMovesBishop(board, x, y);
            break;
        case 4: // queen
            return GetPossibleMovesQueen(board, x, y);
            break;
        case 5: // king
            return GetPossibleMovesKing(board, x, y);
            break;
        case 6: // pawn
            return GetPossibleMovesPawn(board, x, y);
            break;
    }
    return {};
}

//functions to get moves for each different piece
inline std::vector<Move> GetPossibleMovesRook(ChessBoard &board, int x, int y){
    return GetStraightMoves(board, x, y);
}

inline std::vector<Move> GetPossibleMovesKnight(ChessBoard &board, int x, int y){
    return GetKnightMoves(board, x, y);
}

inline std::vector<Move> GetPossibleMovesBishop(ChessBoard &board, int x, int y){
    return GetDiagonalMoves(board, x, y);
}

std::vector<Move> GetPossibleMovesQueen(ChessBoard &board, int x, int y){
    std::vector<Move> straight = GetStraightMoves(board, x, y);
    std::vector<Move> diagonal = GetDiagonalMoves(board, x, y);
    // add two vectors
    straight.insert( straight.end(), diagonal.begin(), diagonal.end());
    return straight;
}

inline std::vector<Move> GetPossibleMovesKing(ChessBoard &board, int x, int y) {
    return GetKingMoves(board, x, y);
}

inline std::vector<Move> GetPossibleMovesPawn(ChessBoard &board, int x, int y) {
    return GetPawnMoves(board, x, y);
}

// actually check if a piece with certain can move straight or diagonal
// and which fields can be reached
// use predefined offsets for pawn and knight
// for loops for king
std::vector<Move> GetStraightMoves(ChessBoard &board, int x, int y) {
    Piece piece = At(board.field, x, y);
    std::vector<Move> moves;
    // check x row left
    for (int i = x - 1; i >= 0; --i) {
        int check = CheckField(board, i, y);
        if(check == 0) moves.emplace_back( Move{Move{x, y, i, y}} );
        if(check == 1) moves.emplace_back( Move{x, y, i, y} );
		if(check == 2) break; // end loop if it is blocked by ally
		if(check == 3) break; // end loop if out of bounds
    }
    // check x row right
    for (int i = x + 1; i < 8; ++i) {
        int check = CheckField(board, i, y);
        if(check == 0) moves.emplace_back( Move{x, y, i, y} );
        if(check == 1) moves.emplace_back( Move{x, y, i, y} );
		if(check == 2) break; // end loop if it is blocked by ally
		if(check == 3) break; // end loop if out of bounds
    }
    // check y row up
    for (int i = y - 1; i >= 0; --i) {
        int check = CheckField(board, i, y);
        if(check == 0) moves.emplace_back( Move{x, y, x, i} );
        if(check == 1) moves.emplace_back( Move{x, y, x, i} );
		if(check == 2) break; // end loop if it is blocked by ally
		if(check == 3) break; // end loop if out of bounds
    }
    // check y row down
    for (int i = y + 1; i < 8; ++i) {
        int check = CheckField(board, i, y);
        if(check == 0) moves.emplace_back( Move{x, y, x, i} );
        if(check == 1) moves.emplace_back( Move{x, y, x, i} );
		if(check == 2) break; // end loop if it is blocked by ally
		if(check == 3) break; // end loop if out of bounds
    }

    return moves;
}

std::vector<Move> GetDiagonalMoves(ChessBoard &board, int x, int y) {
    Piece piece = At(board.field, x, y);
    std::vector<Move> moves;
    // check left up
    for (int i = x - 1; i >= 0; --i) {
        for (int j = y - 1; j >= 0; --j) {
            int check = CheckField(board, i, y);
            if(check == 0) moves.emplace_back( Move{x, y, i, j} );
            if(check == 1) moves.emplace_back( Move{x, y, i, j} );
			if(check == 2) break; // end loop if it is blocked by ally
			if(check == 3) break; // end loop if out of bounds
        }
    }
    // check left down
    for (int i = x - 1; i >= 0; --i) {
        for (int j = y + 1; j < 8; ++j) {
            int check = CheckField(board, i, y);
            if(check == 0) moves.emplace_back( Move{x, y, i, j} );
            if(check == 1) moves.emplace_back( Move{x, y, i, j} );
			if(check == 2) break; // end loop if it is blocked by ally
			if(check == 3) break; // end loop if out of bounds
        }
    }
    // check right up
    for (int i = x + 1; i < 8; ++i) {
        for (int j = y - 1; j >= 0; --j) {
            int check = CheckField(board, i, y);
            if(check == 0) moves.emplace_back( Move{x, y, i, j} );
            if(check == 1) moves.emplace_back( Move{x, y, i, j} );
			if(check == 2) break; // end loop if it is blocked by ally
			if(check == 3) break; // end loop if out of bounds
        }
    }
    // check right down
    for (int i = x + 1; i < 8; ++i) {
        for (int j = y + 1; j < 8; ++j) {
            int check = CheckField(board, i, y);
            if(check == 0) moves.emplace_back( Move{x, y, i, j} );
            if(check == 1) moves.emplace_back( Move{x, y, i, j} );
			if(check == 2) break; // end loop if it is blocked by ally
			if(check == 3) break; // end loop if out of bounds
        }
    }

    return moves;
}

std::vector<Move> GetKnightMoves(ChessBoard &board, int x, int y) {
    Piece piece = At(board.field, x, y);
    std::vector<Move> moves;
    for (int i = 0; i < knightoffsets.size(); i += 2) {
        std::vector<int> cords = { x + knightoffsets[i], y + knightoffsets[i + 1] };
        int check = CheckField(board, cords[0], cords[1] );
        if(check == 0) moves.emplace_back( Move{x, y, cords[0], cords[1]} );
        if(check == 1) moves.emplace_back( Move{x, y, cords[0], cords[1]} );
    }
    return moves;
}

std::vector<Move> GetPawnMoves(ChessBoard &board, int x, int y) {
    Piece piece = At(board.field, x, y);
    std::vector<Move> moves;
    // factor to make it fit for either side
    int factor = 1;
	int isonbaseline = 0;
	if(piece.pieceid < 0){ // is black
        factor = -1;
		if(y != 1){ // check black baseline
			isonbaseline = 1;
		}
    } else { // is white
    	// check white baseline
		if(y != 6) isonbaseline = 1;
	}
	// std::cout << isonbaseline << std::endl;
    for (int i = isonbaseline; i < pawnoffsets.size(); i += 2) {
        std::vector<int> cords = { x + pawnoffsets[i] * factor, y + pawnoffsets[i + 1] * factor };
        int check = CheckField(board, cords[0], cords[1] );
        if(check == 0 && pawnoffsets[i] == 0) moves.emplace_back( Move{x, y, cords[0], cords[1]} );
        if(check == 1 && pawnoffsets[i] != 0) moves.emplace_back( Move{x, y, cords[0], cords[1]} );
    }
    return moves;
}

std::vector<Move> GetKingMoves(ChessBoard &board, int x, int y) {
    Piece piece = At(board.field, x, y);
    std::vector<Move> moves;
    for (int i = x - 1; i < x + 2; ++i) {
        for (int j = y - 1; j < y + 2; ++j) {
            if( 0 <= x && x < 8 && 0 <= y && y < 8){
                int check = CheckField(board, i, j );
                if(check == 0) moves.emplace_back( Move{x, y, i, j} );
                if(check == 1) moves.emplace_back( Move{x, y, i, j} );
                // if check return 2, it checks the field where king is on
            }
        }
    }
    return moves;
}
