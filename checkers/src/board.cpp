#include <iostream>
#include "../include/board.h"

Board::Board() {
    reset_board();
}

Board::~Board() {
    clear_board3();
}

void Board::clear_board0() {
    // iterates through board and deletes the items
    for (int i = 0; i < board_.size(); ++i)  {
        for (int j = 0; j < board_[i].size(); ++j)
            if (nullptr != board_[i][j])
                delete board_[i][j];                 
    }
    board_.resize(0);
}

void Board::clear_board1() {
    // iterates through board and deletes the items
    for (std::vector<std::vector<Piece*>>::iterator it = board_.begin(); it != board_.end(); ++it) {
        for (std::vector<Piece*>::iterator jt = it->begin(); jt != it->end(); ++jt) {
            if (nullptr != *jt)
                delete *jt;
        }
    }
    board_.resize(0);
}

void Board::clear_board2() {
    // iterates through board and deletes the items
    for (auto& it : board_ ) {
        for (auto& jt : it) {
            if (nullptr != jt) 
                delete jt;           
        }
    }
    board_.resize(0);
}

void Board::clear_board3() {
    // iterates through board and deletes the items using lambda
    for_each(board_.begin(), board_.end(), [](auto& vec) {
        for_each(vec.begin(), vec.end(), [](auto& p){
            if (p != nullptr)
                delete p;
        });
    });
}


void Board::reset_board() {
    // gets rid of everything in the board
    clear_board3();
    // resets the board to the starting position
    board_.resize(8);
    for_each(board_.begin(), board_.end(), [](auto& vec) {
        vec.resize(8);
    });

    for (int i = 0; i < board_.size(); ++i) {
        for (int j = i % 2; j < board_[i].size(); j+=2) {
            if (i < 3) {
                board_[i][j] = new Pawn(black);
            }
            else if (i > 4) {
                board_[i][j] = new Pawn(white);
            }
            else {
                board_[i][j] = new Pawn();
            }
        }
    }
    
}

bool Board::check_win() {
    // iterates through the board to see if there are pieces left
    bool black_left = false;
    bool white_left = false;
    for_each(board_.begin(), board_.end(), [&black_left, &white_left](auto& vec) {
        for_each(vec.begin(), vec.end(), [&black_left, &white_left](auto& p){
            if (p != nullptr) {
                if (p->get_color() == black) {
                    black_left = true;
                }
                else if (p->get_color() == white) {
                    white_left = true; 
                }
            }
        });
    });
    if (black_left == false) {
        std::cout << "White Wins" << std::endl;
        return true;
    }
    if (white_left == false) {
        std::cout << "Black Wins" << std::endl;
        return true;
    }
    return false;
}

void Board::print_board(std::ostream& os) {
    // prints the board
    os << "  ";
    for (int i = 0; i < board_.size(); ++i) {
        os << "  " << i << " ";
    }
    os << std::endl;
    os << "  ┌";
    for (int i = 0; i < board_.size() - 1; ++i) {
        os << "───┬";
    }
    os << "───┐";
    os << std::endl;
    for (int i = 0; i < board_.size(); ++i) {
        os << i << " │ ";
        for (int j = 0; j < board_.size(); ++j) {
            if (nullptr != board_[i][j]) {
                board_[i][j]->print(os);
                os << " │ ";
            }
            else {
                os << "  │ ";
            }
        }

        os << std::endl;
        if (i != board_.size() - 1) {
            os << "  ├";
        }
        else {
            os << "  └";
        }

        for (int j = 0; j < board_.size(); ++j) {
            os << "───";
            if (i == board_.size() - 1 && j == board_.size() - 1)
                os << "┘";
            else if (i == board_.size() - 1)
                os << "┴";
            else if (j == board_.size() - 1)
                os << "┤";
            else
                os << "┼";
        }

        os << std::endl;
    }
}

bool Board::move(Coordinate beg, dir d, color c) {
    // checks if the starting position is possible
    if (beg.get_row() < 0 || 
            beg.get_row() >= board_[0].size() || 
            beg.get_col() < 0 || 
            beg.get_col() >= board_.size() || 
            (beg.get_row() + beg.get_col()) % 2 != 0) {
        std::cout << "there cannot be pieces in that spot" << std::endl;
        return false;
    }
    // checks if the starting position is the right color
    if (board_[beg.get_row()][beg.get_col()]->get_color() != c) {
        std::cout << "that's not your piece" << std::endl;
        return false;
    }

    auto [mid, kill] = board_[beg.get_row()][beg.get_col()]->move(beg, d);
    // checks if the move is trying to go off the board
    if (mid.get_row() < 0 || 
            mid.get_row() >= board_[0].size() || 
            mid.get_col() < 0 || 
            mid.get_col() >= board_.size()) {
        std::cout << "you can't move like that" << std::endl;
        return false;
    }
    // if the piece can move, move the piece
    if (board_[mid.get_row()][mid.get_col()]->get_color() == none) {
        board_[beg.get_row()][beg.get_col()]->set_color(none);
        board_[mid.get_row()][mid.get_col()]->set_color(c);
        return true;
    }
    // checks if the player is trying to go out of bounds or jump over its own piece
    if (board_[mid.get_row()][mid.get_col()]->get_color() == c || 
            kill.get_row() < 0 || 
            kill.get_row() >= board_[0].size() || 
            kill.get_col() < 0 || 
            kill.get_col() >= board_.size()) {
        std::cout << "you can't jump over your own piece or go out of bounds" << std::endl;
        return false;
    }
    // if the move works, do it
    if (board_[kill.get_row()][kill.get_col()]->get_color() == none) {
        board_[beg.get_row()][beg.get_col()]->set_color(none);
        board_[mid.get_row()][mid.get_col()]->set_color(none);
        board_[kill.get_row()][kill.get_col()]->set_color(c);
        return true;
    }
    else {
        std::cout << "you can't take or jump over your own piece" << std::endl;
        return false;
    }

    std::cout << "something unexptected happend" << std::endl;
    return false;
}

void Board::promote_pieces() {
    // iterates through the top row and bottom row and promotes pieces. 
    for_each(board_[0].begin(), board_[0].end(), [](auto& p) {
        if (p != nullptr) {
            if (p->get_color() == white) {
                delete p;
                p = new King(white);
            }
        }
    });

    for_each(board_[board_.size() - 1].begin(), board_[board_.size() - 1].end(), [](auto& p) {
            if (p != nullptr) {
                if (p->get_color() == black) {
                    delete p;
                    p = new King(black);
                }
            }
    });
}