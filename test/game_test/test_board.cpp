#include <gtest/gtest.h>
#include "model/board.h"

#include "iostream"

TEST(BoardTests, MakeBoardWithParametrs) {
  Game::Board board(10, 10);

  ASSERT_EQ(board.GetRowCount(), 10);
  ASSERT_EQ(board.GetColumnCount(), 10);
  ASSERT_EQ(board.IsSolved(), true);

  for (size_t row = 0; row < board.GetRowCount(); ++row) {
    for (size_t column = 0; column < board.GetColumnCount(); ++column) {
      //last element
      if (row==9 && column==9)
        break;
      ASSERT_EQ(board.isCellCorrect(row, column), true);
    }
  }
}

TEST(BoardTests, MakeBoardWithoutParametrs) {
  Game::Board board;

  ASSERT_EQ(board.GetRowCount(), 4);
  ASSERT_EQ(board.GetColumnCount(), 4);
  ASSERT_EQ(board.IsSolved(), true);

  for (size_t row = 0; row < board.GetRowCount(); ++row) {
    for (size_t column = 0; column < board.GetColumnCount(); ++column) {
      //last element
      if (row==3 && column==3)
        break;
      ASSERT_EQ(board.isCellCorrect(row, column), true);
    }
  }
}

TEST(BoardTests, MoveEmptyCellOnLeft) {
  Game::Board board;
  board.MoveEmptyPlate(Game::Direction::Left);

  ASSERT_EQ(board.IsSolved(), true);
  ASSERT_EQ(board.isCellCorrect(3, 3), false);
}

TEST(BoardTests, MoveEmptyCellOnRight) {
  Game::Board board;
  board.MoveEmptyPlate(Game::Direction::Right);

  ASSERT_EQ(board.IsSolved(), false);
  ASSERT_EQ(board.isCellCorrect(3, 2), false);
  ASSERT_EQ(board.isCellCorrect(3, 3), false);

  for (size_t row = 0; row < board.GetRowCount(); ++row) {
    for (size_t column = 0; column < board.GetColumnCount(); ++column) {
      if ((row==3 && column==3) || (row==3 && column==2))
        break;
      ASSERT_EQ(board.isCellCorrect(row, column), true);
    }
  }
}



