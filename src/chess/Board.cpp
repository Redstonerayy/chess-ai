// needed for intellisense to work
#include "Board.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

Board::Board() {
    this->LoadStartPosition();
}

void Board::LoadStartPosition() {
    this->p_board = StartBoard;
}

bool Board::RequestMove(int x, int y, int newx, int newy){
    if(this->IsValidMove(x,y, newx, newy)){
        this->MakeMove(x,y, newx, newy);
        return true;
    }
    return false;
}
// oldx,oldy,newx,newy
bool Board::GetPlayerMoveInput(){
    // get line which should contain a move
    std::string line;
    std::getline(std::cin, line);
    if(line.empty()){
        std::cout << "Enter a move\n";
        return false;
    }

    // split line at , and add the numbers for the cordinates to a vector
    std::vector<int> nums;
    std::stringstream lineasstream(line);
    std::string cordinate;
    while(std::getline(lineasstream, cordinate, ',')){
        // remove whitespace
        cordinate.erase(std::remove_if(cordinate.begin(), cordinate.end(), ::isspace), cordinate.end());
        int num = std::stoi(cordinate);
        nums.emplace_back(num);
    }

    // request the moves of the cordinates
    if(nums.size() == 4){
        if(this->RequestMove(nums.at(0), nums.at(1), nums.at(2), nums.at(3))){
            std::cout << "Moving from " << nums.at(0) << ":" << nums.at(1) << " to " << nums.at(2) << ":" << nums.at(3) << "\n";
            return true;
        }
    }
    std::cout << "Enter a valid move in the correct format [x],[y],[newx],[newy]!\n";
    return false;
}