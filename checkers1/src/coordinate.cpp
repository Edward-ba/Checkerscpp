#include <iostream>
#include "../include/coordinate.h"

Coordinate::Coordinate()
: row_(0)
, col_(0) {}

Coordinate::Coordinate(int r, int c)
: row_(r)
, col_(c) {}


Coordinate::~Coordinate() {}