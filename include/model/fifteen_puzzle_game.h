
#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_

#include "model/board.h"

namespace Game {
class FifteenPuzzleGame final {

 public:
  FifteenPuzzleGame();
  ~FifteenPuzzleGame() = default;

  Board &GetBoard();

  void Reload();
  void MoveEmptyPlate(Direction direction);

  bool IsSolved() const;
 private:
  const int m_kRowCount = 4;
  const int m_kColumnCount = 4;

  Board m_board;
};
}
#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
