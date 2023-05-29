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



move_ret_values Pawn::move(Coordinate beg, dir d) {
    if (white == color_) {
        if (d == nw) {
            return move_ret_values{Coordinate(beg.get_row() - 1, beg.get_col() - 1), Coordinate(beg.get_row() - 2, beg.get_col() - 2)};
        }
        if (d == ne) {
            return move_ret_values{Coordinate(beg.get_row() - 1, beg.get_col() + 1), Coordinate(beg.get_row() - 2, beg.get_col() + 2)};
        }
    }
    if (black == color_) {
        if (d == se) {
            return move_ret_values{Coordinate(beg.get_row() + 1, beg.get_col() + 1), Coordinate(beg.get_row() + 2, beg.get_col() + 2)};
        }
        if (d == sw) {
            return move_ret_values{Coordinate(beg.get_row() + 1, beg.get_col() - 1), Coordinate(beg.get_row() + 2, beg.get_col() - 2)};
        }
    }
    return move_ret_values{Coordinate(-1, -1), Coordinate(-1, -1)};
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
