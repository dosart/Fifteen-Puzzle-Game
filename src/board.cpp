#include "board.h"

Game::Board::Board(int rows, int columns)
    : _row_count{rows},
      _column_count{columns},
      _cell_count{rows*_column_count},
      _empty_index{_cell_count - 1},
      _board(16, 0) {

  Init();
}

void Game::Board::Init() {
  std::iota(std::begin(_board), std::end(_board), 1);
  auto index = static_cast<std::vector<int>::size_type>(_empty_index);
  _board[index] = 0;
}

bool Game::Board::IsSolved() const {
  return std::is_sorted(std::begin(_board), std::end(_board) - 1);
}

bool Game::Board::isElementCorrect(int row, int column) {
  auto index = static_cast<std::vector<int>::size_type>(Convert2DIndexTo1DIndex(row, column, _row_count));
  return _board[index]==_board[index] + 1;
}

void Game::Board::MoveEmptyPlate(Game::Direction direction) {
  auto[row, column] = Convert1DIndexTo2DIndex(_empty_index, _row_count, _row_count);

  int move_index = -1;
  if (direction==Direction::Left && column < (_row_count - 1)) move_index = _empty_index + 1;
  if (direction==Direction::Right && column > 0) move_index = _empty_index - 1;
  if (direction==Direction::Up && row < (_row_count - 1)) move_index = _empty_index + _row_count;
  if (direction==Direction::Down && row > 0) move_index = _empty_index - _row_count;

  if (_empty_index >= 0 && move_index >= 0) {
    std::iter_swap(std::begin(_board) + _empty_index, std::begin(_board) + move_index);
    std::swap(_empty_index, move_index);
  }

}

coordinate Game::Board::Convert1DIndexTo2DIndex(int index1d, int rows, int columns) {
  return std::make_pair(index1d/rows, index1d%columns);
}

bool Game::Board::isNotEmptyElement(int row, int column) {
  int value = this->at(row, column);
  return value > 0;
}

int Game::Board::at(int row, int column) {
  auto index = static_cast<std::vector<int>::size_type>(Convert2DIndexTo1DIndex(row, column, _row_count));
  return _board[index];
}

int Game::Board::Convert2DIndexTo1DIndex(int row, int column, int row_count) {
  return row*row_count + column;
}

int Game::Board::GetRowCount() const {
  return _row_count;
}

int Game::Board::GetColumnCount() const {
  return _column_count;
}

