#include <iostream>

#include "Info.hpp"

// print info on piece on field x, y
void FieldInfo(ChessBoard &board, int x, int y){
    int piece = board.field.at(y).at(x);
    int value = abs(piece % 10);
    bool uppercase = true; // white is uppercase
    if (piece < 0){
        uppercase = false;
        std::cout << "BLACK ";
    } else if (piece > 0) {
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

// get string representation of piece on field x, y
std::string FieldAsString(ChessBoard &board, int x, int y){
    int piece = board.field.at(y).at(x);
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
void PrintBoard(ChessBoard &board){
    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " " << "| ";
        for (int j = 0; j < 8; ++j) {
            std::cout << FieldAsString(board, j, i) << " | ";
        }
        std::cout << "\n";
    }
    
    std::string letters = "abcdefgh";
    std::cout << "  " << "  ";
    for(int i = 0; i < 8; ++i){
        std::cout << letters.at(i) << "   ";
    }
    std::cout << "\n";
}

// print board where every possible field, where the current player
// can move to is a X
void PrintBoardMoves(ChessBoard &board){
    // convert board to board as strings
    std::vector<std::vector<std::string>> boardwithmoves;
    for (int i = 0; i < 8; ++i) {
        std::vector<std::string> newrow;
        for (int j = 0; j < 8; ++j) {
            newrow.emplace_back(FieldAsString(board, j, i));
        }
        boardwithmoves.push_back(newrow);
    }
    // set fields to X, where a move can be made to
    for(Move &move : board.moves){
        boardwithmoves.at(move.newy).at(move.newx) = "X"; // x,y cordinate of target field
    }

    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " " << "| ";
        for (int j = 0; j < 8; ++j) {
            std::cout << boardwithmoves.at(i).at(j) << " | ";
        }
        std::cout << "\n";
    }

    std::string letters = "abcdefgh";
    std::cout << "  " << "  ";
    for(int i = 0; i < 8; ++i){
        std::cout << letters.at(i) << "   ";
    }
    std::cout << "\n";
}
