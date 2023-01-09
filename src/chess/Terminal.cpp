#include "Terminal.hpp"
#include "ChessBoard.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

void PrintBoard(ChessBoard &board){
    // print letter on board side
    std::cout << "  ";
    for(std::uint8_t code = 97; code < 105; ++code){
        std::cout << code << " ";
    }
    std::cout << "\n";

    for(std::uint8_t y = 0; y < 8; ++y){
        std::cout << 8 - y << " "; // print numbers on board side
        for(std::uint8_t x = 0; x < 8; ++x){
            std::cout << PiececodeToASCII(board.board.at(y).at(x)) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
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

    // print letter on board side
    std::cout << "  ";
    for(std::uint8_t code = 97; code < 105; ++code){
        std::cout << code << "  ";
    }
    std::cout << "\n";

    // print
    for(std::uint8_t y = 0; y < 8; ++y){
        std::cout << 8 - y << " "; // print numbers on board side
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
    std::cout << "\n";
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

Move GetPlayerMove(){
    // get line which should contain a move
    std::string line;
    std::getline(std::cin, line, '\n');
    if(line.empty()){
        std::cout << "Enter a move, not just press enter\n";
        return Move{-1, -1, -1, -1};
    }

    // format oldx,oldy,newx,newy
    // split line at , and add the numbers for the cordinates to a vector
    std::vector<std::int8_t> nums;
    std::stringstream lineasstream(line);
    std::string cordinate;
    while(std::getline(lineasstream, cordinate, ',')){
        // remove whitespace
        cordinate.erase(std::remove_if(cordinate.begin(), cordinate.end(), ::isspace), cordinate.end());
        std::int8_t num = std::stoi(cordinate);
        nums.emplace_back(num);
    }

    //check if it is this format
    if(nums.size() == 4){
        // check if in range
        if(std::all_of(nums.begin(), nums.end(), [](int num){ return num > 0 && num < 8; })){
            return Move{nums.at(0), nums.at(1), nums.at(2), nums.at(3)};
        } else {
            std::cout << "Move is out of range!\n";
        }
    }

    // [letter][num][letter][num]
    // check other format
    std::cout << line.length();
    if(line.length() == 4){
        Move mov;
        mov.oldx = line.at(0) - 'a';
        mov.oldy = 8 - line.at(1);
        mov.newx = line.at(2) - 'a';
        mov.newx = 8 - line.at(3);
        return mov; 
    }
}