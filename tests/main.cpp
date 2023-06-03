#include <gtest/gtest.h>

#include "../checkerslib/include/board.h"
#include "../checkerslib/include/pawn.h"
#include "../checkerslib/include/king.h"
#include "../checkerslib/include/coordinate.h"


// Demonstrate some basic assertions.
TEST(IntroTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(8 * 6, 41);
}

// Demonstrate some basic assertions.
TEST(BoardTest, Test0) {
  Board board;
  EXPECT_EQ(board.board_.size(), 8);
  for (int i = 0;  i < board.board_.size() ;++i)
    EXPECT_EQ(board.board_[i].size(), 8);
}


TEST(BoardTest, Test1) {
  Board board;
  
  EXPECT_EQ(board.board_[2][2]->get_color(), color::black);
  board.move(Coordinate(2,2), dir::se, color::black);
  EXPECT_EQ(board.board_[2][2]->get_color(), color::none);



}
