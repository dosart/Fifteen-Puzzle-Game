
#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_

#include "board.h"

namespace Game {
class FifteenPuzzleGame final {

 public:
  FifteenPuzzleGame();
  ~FifteenPuzzleGame() = default;

  void Reload();
  void MoveEmptyPlate(Direction direction);
 private:
  const int kRowCount = 4;
  const int kColumnCount = 4;

  Board board;
};
}
#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
