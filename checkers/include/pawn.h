#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn();
    Pawn(color c);
    ~Pawn();

    std::pair<Coordinate, Coordinate> move(Coordinate beg, dir d);
    void print(std::ostream& os);
};
