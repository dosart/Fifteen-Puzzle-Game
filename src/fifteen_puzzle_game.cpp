#include "fifteen_puzzle_game.h"
#include "board.h"

namespace Game {
FifteenPuzzleGame::FifteenPuzzleGame() : _board{_kRowCount, _kColumnCount} {}

void FifteenPuzzleGame::Reload() {
  _board.Init();
}

void FifteenPuzzleGame::MoveEmptyPlate(Direction direction) {
  _board.MoveEmptyPlate(direction);
}

Board &FifteenPuzzleGame::GetBoard() {
  return _board;
}
bool FifteenPuzzleGame::isSolved() const {
  return _board.IsSolved();
}
}
