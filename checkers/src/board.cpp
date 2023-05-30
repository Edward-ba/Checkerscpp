#include <iostream>
#include "../include/board.h"

Board::Board() {
    reset_board();
}

Board::~Board() {
    clear_board3();
}

void Board::clear_board0() {
    for (int i = 0; i < board_.size(); ++i)  {
        for (int j = 0; j < board_[i].size(); ++j)
            if (nullptr != board_[i][j])
                delete board_[i][j];                 
    }
    board_.resize(0);
}

void Board::clear_board1() {
    for (std::vector<std::vector<Piece*>>::iterator it = board_.begin(); it != board_.end(); ++it) {
        for (std::vector<Piece*>::iterator jt = it->begin(); jt != it->end(); ++jt) {
            if (nullptr != *jt)
                delete *jt;
        }
    }
    board_.resize(0);
}

void Board::clear_board2() {
    for (auto& it : board_ ) {
        for (auto& jt : it) {
            if (nullptr != jt) 
                delete jt;           
        }
    }
    board_.resize(0);
}

void Board::clear_board3() {
    for_each(board_.begin(), board_.end(), [](auto& vec) {
        for_each(vec.begin(), vec.end(), [](auto& p){
            if (p != nullptr)
                delete p;
        });
    });
}


void Board::reset_board() {
    clear_board3();

    board_.resize(8);
    for_each(board_.begin(), board_.end(), [](auto& vec) {
        vec.resize(8);
    });

    for (int i = 0; i < board_.size(); ++i) {
        for (int j = 0; j < board_[i].size(); j+=2) {
            if (i < 3) {
                board_[i][i%2+j] = new Pawn(black);
            }
            else if (i > 4) {
                board_[i][i%2+j] = new Pawn(white);
            }
            else {
                board_[i][i%2+j] = new Pawn();
            }
        }
    }
    
}

bool Board::check_win() {
    return false;
}

void Board::print_board(std::ostream& os) {
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
            if (i != board_.size() - 1)
                os << "  ├";
            else
                os << "  └";
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
    if (beg.get_row() < 0 || 
            beg.get_row() >= board_[0].size() || 
            beg.get_col() < 0 || 
            beg.get_col() >= board_.size() || 
            (beg.get_row() + beg.get_col()) % 2 != 0) {
        return false;
    }
    auto [mid, kill] = board_[beg.get_row()][beg.get_col()]->move(beg, d);
    if (mid.get_row() < 0 || 
            mid.get_row() >= board_[0].size() || 
            mid.get_col() < 0 || 
            mid.get_col() >= board_.size()) {
        return false;
    }
    if (board_[mid.get_row()][mid.get_col()]->get_color() == none) {
        board_[beg.get_row()][beg.get_col()]->set_color(none);
        board_[mid.get_row()][mid.get_col()]->set_color(c);
        return true;
    }
    if (board_[mid.get_row()][mid.get_col()]->get_color() != c && 
            kill.get_row() >= 0 && 
            kill.get_row() < board_[0].size() && 
            kill.get_col() >= 0 && 
            kill.get_col() < board_.size()) {
        board_[beg.get_row()][beg.get_col()]->set_color(none);
        board_[mid.get_row()][mid.get_col()]->set_color(none);
        board_[kill.get_row()][kill.get_col()]->set_color(c);
    }
    return false;
}