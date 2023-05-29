#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn();
    Pawn(color c);
    ~Pawn();

    move_ret_values move(Coordinate beg, dir d);
    void print(std::ostream& os);
};
