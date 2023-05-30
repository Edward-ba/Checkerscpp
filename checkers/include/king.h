#pragma once
#include "piece.h"

class King : public Piece
{
public:
    King();
    King(color c);
    ~King();

    std::pair<Coordinate, Coordinate> move(Coordinate beg, dir d);
    void print(std::ostream& os);
};
