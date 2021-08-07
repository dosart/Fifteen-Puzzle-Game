#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_

#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

using coordinate = std::pair<int, int>;

namespace Game {

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Board final {
 public:
  Board();
  ~Board() = default;

  bool Correct();
  void SwapWithEmpty(Direction direction);

 private:
  const int kRowCount = 4;
  const int kBoardSize = kRowCount*kRowCount;
  int empty_index;

  std::vector<int> board;

  coordinate Convert1DIndexTo2DIndex(int index1d, int row_count, int column_count);
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
