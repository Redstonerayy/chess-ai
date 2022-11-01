#pragma once

#include <cmath>

#include "definitions.hpp" // for function

#define At(field, x, y) { field.at(y).at(x), abs( field.at(y).at(x) % 10) }
// function
// inline Piece At(field, x, y){
//     Piece piece = { field.at(y).at(x), abs( field.at(y).at(x) % 10) };
//     return piece;
// }