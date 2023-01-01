#include "Terminal.hpp"
#include "ChessBoard.hpp"

#include <iostream>

void PrintBoard(ChessBoard &board){
    for(std::uint8_t y = 0; y < 8; ++y){
        for(std::uint8_t x = 0; x < 8; ++x){
            std::cout << PiececodeToASCII(board.board.at(y).at(x)) << " ";
        }
        std::cout << "\n";
    }
}

void PrintMoves(std::vector<Pos> legalmoves, std::vector<Pos> allmoves){
    ChessBoard board;
    FillBoardEmpty(board);
    // fill array with moves
    for( Pos pos : allmoves ){
        board.board.at(pos.y).at(pos.x) = 1;
    }
    for( Pos pos : legalmoves ){
        board.board.at(pos.y).at(pos.x) = 2;
    }
    // print
    for(std::uint8_t y = 0; y < 8; ++y){
        for(std::uint8_t x = 0; x < 8; ++x){
            if( board.board.at(y).at(x) == 1 ){
                std::cout << "-  ";
            } else if( board.board.at(y).at(x) == 2) {
                std::cout << "X  ";
            } else {
                std::cout << "o  ";
            }
        }
        std::cout << "\n";
    }
}

char PiececodeToASCII(std::uint8_t piececode){
    // white is uppercase, black is lowercase
    switch(piececode){
        default: return ' '; break; // 0
        case 1: return 'P'; break;
        case 2: return 'R'; break;
        case 3: return 'N'; break;
        case 4: return 'B'; break;
        case 5: return 'Q'; break;
        case 6: return 'K'; break;
        case 11: return 'p'; break;
        case 12: return 'r'; break;
        case 13: return 'n'; break;
        case 14: return 'b'; break;
        case 15: return 'q'; break;
        case 16: return 'k'; break;
    }
}
