#include "game_model.h"
#include "board.h"

namespace Game {
FifteenPuzzleGame::FifteenPuzzleGame() : board{kRowCount, kColumnCount} {}

void FifteenPuzzleGame::Reload() {
  board.Init();
}

void FifteenPuzzleGame::MoveEmptyPlate(Direction direction) {
  board.MoveEmptyPlate(direction);
}
}
