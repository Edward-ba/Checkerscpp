#include <iostream>
#include "./include/board.h"
#include "./include/pawn.h"
#include "./include/king.h"
#include "./include/coordinate.h"

int main(int argc, char* argv[]) {
    Board board;
    
    board.move(Coordinate(2, 2), sw, black);

    board.print_board(std::cout);
}