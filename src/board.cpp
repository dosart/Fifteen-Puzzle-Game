#include "board.h"

Game::Board::Board(int rows, int columns)
    : row_count{rows}, column_count{columns}, cell_count{rows*column_count}, empty_index{cell_count - 1} {
  std::iota(std::begin(board), std::end(board), 1);
  auto index = static_cast<std::vector<int>::size_type>(empty_index);
  board[index] = 0;
}

bool Game::Board::Correct() {
  return std::is_sorted(std::begin(board), std::end(board) - 1);
}

void Game::Board::moveEmptyPlate(Game::Direction direction) {
  auto[row, column] = Convert1DIndexTo2DIndex(empty_index, row_count, row_count);

  int move_index = -1;
  if (direction==Direction::Left && column < (row_count - 1)) move_index = empty_index + 1;
  if (direction==Direction::Right && column > 0) move_index = empty_index - 1;
  if (direction==Direction::Up && row < (row_count - 1)) move_index = empty_index + row_count;
  if (direction==Direction::Down && row > 0) move_index = empty_index - row_count;

  if (empty_index >= 0 && move_index >= 0) {
    std::iter_swap(std::begin(board) + empty_index, std::begin(board) + move_index);
  }

}

coordinate Game::Board::Convert1DIndexTo2DIndex(int index1d, int rows, int columns) {
  return std::make_pair(index1d/rows, index1d%columns);
}
