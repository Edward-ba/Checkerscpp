#include <iostream>
#include "../include/piece.h"

Piece::Piece()
: color_(none) {  
    // std::cout << "default Piece " << color_ << std::endl;
}

Piece::Piece(color c)
: color_(c) {
    // std::cout << "param Piece " << color_ << std::endl;
}

Piece::~Piece() {
    // std::cout << "destruct Piece " << color_ << std::endl;
}
