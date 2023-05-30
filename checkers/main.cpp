

// class King: private Piece{
//     public:
//         Coordinate move(Coordinate beg, dir d) {
//             if (d == nw) {
//                 return Coordinate(beg.get_row() - 1, beg.get_col() - 1);
//             }
//             if (d == ne) {
//                 return Coordinate(beg.get_row() - 1, beg.get_col() + 1);
//             }
//             if (d == se) {
//                 return Coordinate(beg.get_row() + 1, beg.get_col() + 1);
//             }
//             if (d == sw) {
//                 return Coordinate(beg.get_row() + 1, beg.get_col() - 1);
//             }
//             return Coordinate(-1, -1);
//         }
//         void print() {
//             if (get_type() == white) {
//                 std::cout << "W";
//             }
//             else if (get_type() == black) {
//                 std::cout << "B";
//             }
//             else {
//                 std::cout << " ";
//             }
//         }
// };

#include <iostream>
#include "./include/board.h"
#include "./include/pawn.h"
#include "./include/king.h"
#include "./include/coordinate.h"

int main(int argc, char* argv[]) {
    Board board;
    
    board.move(Coordinate(2, 2), sw, black);

    board.print_board(std::cout);
    
    // {
    //     Piece* p = new Pawn();
    //     p->print();
    //     p->move(Coordinate(-1, -1), ne);
    //     delete p;
    // }

    // std::cout << "----\n";
    // {
    //     Piece* k = new King();
    //     k->print();
    //     k->move(Coordinate(-1, -1), ne);
    //     delete k;
    // }

}