#include <iostream>
#include "./include/board.h"
#include "./include/pawn.h"
#include "./include/king.h"
#include "./include/coordinate.h"

int main(int argc, char* argv[]) {
    Board board;

    board.print_board(std::cout);


    return 1;

    int r, c;
    int d;
    dir actual_d;
    color current_player = white;
    while (!board.check_win()) {
        std::cout << ((current_player == black) ? "black's turn" : "white's turn") << std::endl;
        std::cout << "row of piece: ";
        std::cin >> r;
        std::cout << "column of piece: ";
        std::cin >> c;
        std::cout << "direction to move(0=ne, 1=se, 2=sw, 3=nw): ";
        std::cin >> d;
        if (d < 0 || d > 3) {
            std::cout << "invalid direction" << std::endl;
            continue;
        }
        actual_d = static_cast<dir>(d);
        if (!board.move(Coordinate(r, c), actual_d, current_player)) {
            continue;
        }

        board.promote_pieces();
        current_player = (current_player == black) ? white : black;
        board.print_board(std::cout);
    }
}