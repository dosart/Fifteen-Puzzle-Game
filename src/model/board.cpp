#include "model/board.h"

Game::Board::Board(size_t rows, size_t columns)
    : m_row_count{rows},
      m_column_count{columns},
      m_cell_count{m_row_count*m_column_count},
      m_empty_index{m_cell_count - 1},
      m_board(m_cell_count, 0) {

  Init();
}

void Game::Board::Init() {
  std::iota(std::begin(m_board), std::end(m_board), 1);
  m_board[m_empty_index] = 0;
}

bool Game::Board::IsSolved() const {
  return std::is_sorted(std::begin(m_board), std::end(m_board) - 1);
}

bool Game::Board::isCellCorrect(size_t row, size_t column) {
  auto index = Utils::Convert2DIndexTo1DIndex(row, column, m_row_count);
  return m_board[index]==int(index + 1);
}

void Game::Board::MoveEmptyPlate(Game::Direction direction) {
  auto[row, column] = Utils::Convert1DIndexTo2DIndex(m_empty_index, m_row_count, m_row_count);

  bool isIndexValid = false;
  size_t move_index = 0;
  if (direction==Direction::Left && column < (m_row_count - 1)) {
    isIndexValid = true;
    move_index = m_empty_index + 1;
  }
  if (direction==Direction::Right && column > 0) {
    isIndexValid = true;
    move_index = m_empty_index - 1;
  }
  if (direction==Direction::Up && row < (m_row_count - 1)) {
    isIndexValid = true;
    move_index = m_empty_index + m_row_count;
  }
  if (direction==Direction::Down && row > 0) {
    isIndexValid = true;
    move_index = m_empty_index - m_row_count;
  }

  if (isIndexValid) {
    std::swap(m_board[m_empty_index], m_board[move_index]);
    std::swap(m_empty_index, move_index);
  }

}

bool Game::Board::isNotEmptyElement(size_t row, size_t column) {
  int value = this->at(row, column);
  return value > 0;
}

int Game::Board::at(size_t row, size_t column) {
  auto index = Utils::Convert2DIndexTo1DIndex(row, column, m_row_count);
  return m_board[index];
}

size_t Game::Board::GetRowCount() const {
  return m_row_count;
}

size_t Game::Board::GetColumnCount() const {
  return m_column_count;
}

