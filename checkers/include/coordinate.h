#pragma once

enum color {none, white, black};
enum dir  {ne = 0, se, sw, nw};

class Coordinate {
    int row_;
    int col_;
public:
    Coordinate();
    Coordinate(int r, int c);
    ~Coordinate();

    int get_row() {return row_;};
    int get_col() {return col_;};
};

