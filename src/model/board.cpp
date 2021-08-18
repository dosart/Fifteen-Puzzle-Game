#include "model/board.h"

Game::Board::Board(int rows, int columns)
    : m_row_count{rows},
      m_column_count{columns},
      m_cell_count{rows*m_column_count},
      m_empty_index{m_cell_count - 1},
      m_board(16, 0) {

  Init();
}

void Game::Board::Init() {
  std::iota(std::begin(m_board), std::end(m_board), 1);
  auto index = static_cast<std::vector<int>::size_type>(m_empty_index);
  m_board[index] = 0;
}

bool Game::Board::IsSolved() const {
  return std::is_sorted(std::begin(m_board), std::end(m_board) - 1);
}

bool Game::Board::isCellCorrect(int row, int column) {
  auto index = static_cast<std::vector<int>::size_type>(Convert2DIndexTo1DIndex(row, column, m_row_count));
  return m_board[index]==m_board[index] + 1;
}

void Game::Board::MoveEmptyPlate(Game::Direction direction) {
  auto[row, column] = Convert1DIndexTo2DIndex(m_empty_index, m_row_count, m_row_count);

  int move_index = -1;
  if (direction==Direction::Left && column < (m_row_count - 1)) move_index = m_empty_index + 1;
  if (direction==Direction::Right && column > 0) move_index = m_empty_index - 1;
  if (direction==Direction::Up && row < (m_row_count - 1)) move_index = m_empty_index + m_row_count;
  if (direction==Direction::Down && row > 0) move_index = m_empty_index - m_row_count;

  if (m_empty_index >= 0 && move_index >= 0) {
    std::iter_swap(std::begin(m_board) + m_empty_index, std::begin(m_board) + move_index);
    std::swap(m_empty_index, move_index);
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
  auto index = static_cast<std::vector<int>::size_type>(Convert2DIndexTo1DIndex(row, column, m_row_count));
  return m_board[index];
}

int Game::Board::Convert2DIndexTo1DIndex(int row, int column, int row_count) {
  return row*row_count + column;
}

int Game::Board::GetRowCount() const {
  return m_row_count;
}

int Game::Board::GetColumnCount() const {
  return m_column_count;
}

