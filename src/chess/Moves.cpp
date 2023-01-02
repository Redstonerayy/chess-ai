#include "Moves.hpp"
#include "ChessBoard.hpp"

#include <vector>
#include <array>
#include <cstdint>

const std::array<Pos, 4> pawnoffsets = {
    Pos{0, 1},
    Pos{0, 2},
    Pos{1, 1},
    Pos{-1, 1}
};

const std::array<Pos, 8> knightoffsets = {
    // left
    Pos{-2, 1},
    Pos{-2, -1},
    // right
    Pos{2, 1},
    Pos{2, -1},
    // up
    Pos{1, -2},
    Pos{-1, -2},
    // down
    Pos{1, 2},
    Pos{-1, 2}
};

const std::array<Pos, 8> kingoffsets = {
    Pos{-1, -1},
    Pos{0, -1},
    Pos{1, -1},
    Pos{1, 0},
    Pos{1, 1},
    Pos{0, 1},
    Pos{-1, 1},
    Pos{-1, 0},
};

#define IsInRange(x, y) ( x >= 0 && x <= 7 && y >= 0 && y <= 7 )

bool IsEnemy(ChessBoard &board, Pos pos, bool direction){
    // white
    if( direction ){
        if( board.board.at(pos.y).at(pos.x) > 10 ){
            return true;
        } else {
            return false;
        }
    }
    // black
    if( board.board.at(pos.y).at(pos.x) < 10 ){
        return true;
    } else {
        return false;
    }
}

void AddMove(ChessBoard &board, Pos newpos, bool direction, bool &blocked, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves){
    if( blocked ){
        allmoves.emplace_back(newpos);
        return; // can't be legal move
    }
    if ( board.board.at(newpos.y).at(newpos.x) == 0 ){
        legalmoves.emplace_back(newpos);
    } else {
        blocked = true;
        if ( IsEnemy(board, newpos, direction) ){// enemy
            legalmoves.emplace_back(newpos);
        } else {
            allmoves.emplace_back(newpos);
        }
    }
}

void GetStraightMoves(ChessBoard &board, Pos pos, bool direction, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves){
    bool blocked = false;
    // left
    for(int8_t x = pos.x - 1; x >= 0; --x){
        Pos newpos = {x, pos.y};
        AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
    }
    blocked = false;
    // right
    for(int8_t x = pos.x + 1; x <= 7; ++x){
        Pos newpos = {x, pos.y};
        AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
    }
    blocked = false;
    // up
    for(int8_t y = pos.y - 1; y >= 0; --y){
        Pos newpos = {pos.x, y};
        AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
    }
    blocked = false;
    //down
    for(int8_t y = pos.y + 1; y <= 7; ++y){
        Pos newpos = {pos.x, y};
        AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
    }
}

void GetDiagonalMoves(ChessBoard &board, Pos pos, bool direction, std::vector<Pos> &legalmoves, std::vector<Pos> &allmoves){
    int8_t x, y;
    // left up
    bool blocked = false;
    x = pos.x - 1;
    y = pos.y - 1;
    while( IsInRange(x, y) ){
        AddMove(board, Pos{x, y}, direction, blocked, legalmoves, allmoves);
        --x;
        --y;
    }
    // right up
    blocked = false;
    x = pos.x + 1;
    y = pos.y - 1;
    while( IsInRange(x, y) ){
        AddMove(board, Pos{x, y}, direction, blocked, legalmoves, allmoves);
        ++x;
        --y;
    }
    // left down
    blocked = false;
    x = pos.x - 1;
    y = pos.y + 1;
    while( IsInRange(x, y) ){
        AddMove(board, Pos{x, y}, direction, blocked, legalmoves, allmoves);
        --x;
        ++y;
    }
    // right down
    blocked = false;
    x = pos.x + 1;
    y = pos.y + 1;
    while( IsInRange(x, y) ){
        AddMove(board, Pos{x, y}, direction, blocked, legalmoves, allmoves);
        ++x;
        ++y;
    }
}

std::vector<std::vector<Pos>> GetPawnMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    for( Pos offset : pawnoffsets ){
        Pos newpos;
        newpos.x = pos.x + offset.x;
        newpos.y = pos.y + (direction ? offset.y * -1 : offset.y);
        if( IsInRange(newpos.x, newpos.y) ){
            allmoves.emplace_back(newpos);
            if( direction ){ // white
                if( board.board.at(newpos.y).at(newpos.x) == 0 ||  
                    ( board.board.at(newpos.y).at(newpos.x) > 10 && offset.x != 1 )
                ){
                    legalmoves.emplace_back(newpos);
                }
            } else { // black
                if( board.board.at(newpos.y).at(newpos.x) == 0 ||  
                    ( board.board.at(newpos.y).at(newpos.x) < 10 && offset.x != 1 )
                ){
                    legalmoves.emplace_back(newpos);
                }
            }
        }
    }
    return { legalmoves, allmoves };
}


std::vector<std::vector<Pos>> GetRookMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    
    GetStraightMoves(board, pos, direction, legalmoves, allmoves);
    
    return { legalmoves, allmoves};
}

std::vector<std::vector<Pos>> GetKnightMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    for( Pos offset : knightoffsets ){
        Pos newpos;
        newpos.x = pos.x + offset.x;
        newpos.y = pos.y + offset.y;
        if( IsInRange(newpos.x, newpos.y) ){
            bool blocked = false; // needed because passed as refenrece
            AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
        }
    }
    return { legalmoves, allmoves };
}

std::vector<std::vector<Pos>> GetBishopMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    
    GetDiagonalMoves(board, pos, direction, legalmoves, allmoves);

    return { legalmoves, allmoves};
}

std::vector<std::vector<Pos>> GetQueenMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    
    GetStraightMoves(board, pos, direction, legalmoves, allmoves);
    GetDiagonalMoves(board, pos, direction, legalmoves, allmoves);
    
    return { legalmoves, allmoves};
}

std::vector<std::vector<Pos>> GetKingMoves(ChessBoard &board, Pos pos){
    bool direction = board.board.at(pos.y).at(pos.x) < 10; // true is white
    std::vector<Pos> legalmoves;
    std::vector<Pos> allmoves;
    for( Pos offset : kingoffsets ){
        Pos newpos;
        newpos.x = pos.x + offset.x;
        newpos.y = pos.y + offset.y;
        if( IsInRange(newpos.x, newpos.y) ){
            bool blocked = false; // needed because passed as refenrece
            AddMove(board, newpos, direction, blocked, legalmoves, allmoves);
        }
    }
    return { legalmoves, allmoves };
}
