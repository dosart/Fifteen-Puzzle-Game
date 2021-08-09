#include "board.h"

Game::Board::Board() {
  std::iota(std::begin(board), std::end(board), 1);
  empty_index = kBoardSize - 1;
  auto index =  static_cast<std::vector<int>::size_type>(empty_index);
  board[index] = 0;
}

bool Game::Board::Correct() {
  return std::is_sorted(std::begin(board), std::end(board) - 1);
}

void Game::Board::moveEmptyPlate(Game::Direction direction) {
  auto[row, column] = Convert1DIndexTo2DIndex(empty_index, kRowCount, kRowCount);

  int move_index = -1;
  if (direction==Direction::Left && column < (kRowCount - 1)) move_index = empty_index + 1;
  if (direction==Direction::Right && column > 0) move_index = empty_index - 1;
  if (direction==Direction::Up && row < (kRowCount - 1)) move_index = empty_index + kRowCount;
  if (direction==Direction::Down && row > 0) move_index = empty_index - kRowCount;

  if (empty_index >= 0 && move_index >= 0) {
    std::iter_swap(std::begin(board) + empty_index, std::begin(board) + move_index);
  }

}

coordinate Game::Board::Convert1DIndexTo2DIndex(int index1d, int row_count, int column_count) {
  return std::make_pair(index1d/row_count, index1d%column_count);
}
