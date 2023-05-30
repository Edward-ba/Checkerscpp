#include <iostream>
#include "../include/king.h"

King::King() 
: Piece() 
{
    // std::cout << "default King " << color_ << std::endl;
}

King::King(color c) 
: Piece(c) 
{
    // std::cout << "param King " << color_ << std::endl;
}

King::~King() {
    // std::cout << "destruct King " << color_ << std::endl;
}

std::pair<Coordinate, Coordinate> King::move(Coordinate beg, dir d) {
    if (d == nw) {
        return std::make_pair(Coordinate(beg.get_row() - 1, beg.get_col() - 1), Coordinate(beg.get_row() - 2, beg.get_col() - 2));
    }
    if (d == ne) {
        return std::make_pair(Coordinate(beg.get_row() - 1, beg.get_col() + 1), Coordinate(beg.get_row() - 2, beg.get_col() + 2));
    }
    if (d == se) {
        return std::make_pair(Coordinate(beg.get_row() + 1, beg.get_col() + 1), Coordinate(beg.get_row() + 2, beg.get_col() + 2));
    }
    if (d == sw) {
        return std::make_pair(Coordinate(beg.get_row() + 1, beg.get_col() - 1), Coordinate(beg.get_row() + 2, beg.get_col() - 2));
    }
    return std::make_pair(Coordinate(-1, -1), Coordinate(-1, -1));
}


void King::print(std::ostream& os) {
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
