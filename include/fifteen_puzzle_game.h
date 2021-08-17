
#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_

#include "board.h"

namespace Game {
class FifteenPuzzleGame final {

 public:
  FifteenPuzzleGame();
  ~FifteenPuzzleGame() = default;

  Board &GetBoard();

  void Reload();
  void MoveEmptyPlate(Direction direction);

  bool isSolved() const;
 private:
  const int _kRowCount = 4;
  const int _kColumnCount = 4;

  Board _board;
};
}
#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
