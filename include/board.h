/*!
\file
\brief Header file for implementation game board
*/

#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_

#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

using coordinate = std::pair<int, int>;

namespace Game {

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

/*!
	\brief Game board class
	\author Dosart
	\version 1.0
	\date 09.08.2021
*/
class Board final {
 public:
  /**
     * @brief Fills the array with elements in the correct order
 */
  Board();
  ~Board() = default;

  /**
    * @brief Checks if the puzzle is solved and returns the result of the check
    *
    * @return result of the check
 */
  bool Correct();

  /**
    * @brief Swap an empty plate and a user plate
    *
    * @return result of the check
*/
  void moveEmptyPlate(Direction direction);

 private:
  const int kRowCount = 4;
  const int kBoardSize = kRowCount*kRowCount;
  int empty_index;

  std::vector<int> board;

  coordinate Convert1DIndexTo2DIndex(int index1d, int row_count, int column_count);
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
