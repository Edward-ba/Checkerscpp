#pragma once
#include <vector>
#include "piece.h"
#include "coordinate.h"
#include "pawn.h"
#include "king.h"

class Board {
    std::vector<std::vector<Piece*>> board_; 

public:
    Board();
    ~Board();
    void print_board(std::ostream& os);
    void reset_board();

    void clear_board0();
    void clear_board1();
    void clear_board2();
    void clear_board3();
    
    void promote_pieces();
    bool check_win();
    bool move(Coordinate beg, dir d, color c);
};
