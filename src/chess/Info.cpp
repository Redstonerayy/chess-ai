#include "Board.hpp"

#include <iostream>

// print info on piece on field x, y
void Board::FieldInfo(int x, int y){
    int piece = this->p_board[y][x];
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

void Board::PrintBoardMoves(std::vector<std::vector<int>> &moves){
    // convert board to board as strings
    std::vector<std::vector<std::string>> boardwithmoves;
    for (int i = 0; i < this->p_board.size(); ++i) {
        std::vector<std::string> newrow;
        for (int j = 0; j < this->p_board[i].size(); ++j) {
            newrow.emplace_back(this->FieldAsString(j, i));
        }
        boardwithmoves.push_back(newrow);
    }
    // set fields to X, where a move can be made to
    for(std::vector<int> &move : moves){
        boardwithmoves.at(move.at(3)).at(move.at(2)) = "X"; // x,y cordinate of target field
    }

    for (int i = 0; i < this->p_board.size(); ++i) {
        std::cout << "| ";
        for (int j = 0; j < this->p_board[i].size(); ++j) {
            std::cout << boardwithmoves.at(i).at(j) << " | ";
        }
        std::cout << "\n";
    }
}
