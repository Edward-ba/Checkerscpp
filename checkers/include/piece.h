#pragma once
#include "coordinate.h"

struct move_ret_values{
    Coordinate mid;
    Coordinate kill;
};

class Piece
{
protected:
    color color_;
public:
    Piece();
    Piece(color c);
    virtual ~Piece();

    virtual move_ret_values move(Coordinate beg, dir d) = 0;

    virtual void print(std::ostream& os) = 0;
    color get_color() { return color_;};
    void set_color(color c) {color_ = c;};
};
