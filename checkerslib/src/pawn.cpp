#include <iostream>
#include "../include/pawn.h"

Pawn::Pawn() 
: Piece() 
{
    // std::cout << "default pawn " << color_ << std::endl;
}

Pawn::Pawn(color c) 
: Piece(c) 
{
    // std::cout << "param pawn " << color_ << std::endl;
}

Pawn::~Pawn() {
    // std::cout << "destruct pawn " << color_ << std::endl;
}

std::pair<Coordinate, Coordinate> Pawn::move(Coordinate beg, dir d) {
    if (white == color_) {
        if (d == nw) {
            return std::make_pair(Coordinate(beg.get_row() - 1, beg.get_col() - 1), Coordinate(beg.get_row() - 2, beg.get_col() - 2));
        }
        if (d == ne) {
            return std::make_pair(Coordinate(beg.get_row() - 1, beg.get_col() + 1), Coordinate(beg.get_row() - 2, beg.get_col() + 2));
        }
    }
    if (black == color_) {
        if (d == se) {
            return std::make_pair(Coordinate(beg.get_row() + 1, beg.get_col() + 1), Coordinate(beg.get_row() + 2, beg.get_col() + 2));
        }
        if (d == sw) {
            return std::make_pair(Coordinate(beg.get_row() + 1, beg.get_col() - 1), Coordinate(beg.get_row() + 2, beg.get_col() - 2));
        }
    }
    return std::make_pair(Coordinate(-1, -1), Coordinate(-1, -1));
}


void Pawn::print(std::ostream& os) {
    if (color_ == white) {
        os << "w";
    }
    else if (color_ == black) {
        os << "b";
    }
    else {
        os << " ";
    }
}
