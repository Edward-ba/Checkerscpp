#pragma once
#include "piece.h"

class King : public Piece
{
public:
    King();
    King(color c);
    ~King();

    move_ret_values move(Coordinate beg, dir d);
    void print(std::ostream& os);
};
