#include "model/fifteen_puzzle_game.h"
#include "model/board.h"

namespace Game {
FifteenPuzzleGame::FifteenPuzzleGame() : m_board{m_kRowCount, m_kColumnCount} {}

void FifteenPuzzleGame::StartNewGame() {
  m_board.Init();
}

void FifteenPuzzleGame::MoveEmptyPlate(Direction direction) {
  m_board.MoveEmptyPlate(direction);
}

Board &FifteenPuzzleGame::GetBoard() {
  return m_board;
}
bool FifteenPuzzleGame::IsSolved() const {
  return m_board.IsSolved();
}
}
