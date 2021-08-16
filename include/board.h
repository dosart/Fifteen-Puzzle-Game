/*!
\file
\brief Header file for implementation _game _board
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
	\brief Game _board class
	\author Dosart
	\version 1.0
	\date 09.08.2021
*/
class Board final {
 public:
  /**
     * @brief Fills the array with elements in the correct order
 */
  Board(int row_count = 4, int column_count = 4);
  ~Board() = default;

  void Init();

  /**
    * @brief Checks if the puzzle is solved and returns the result of the check
    *
    * @return result of the check
 */
  bool Correct();
  bool isElementCorrect(int row, int column);
  bool isNotEmpty(int row, int column);

  /**
    * @brief Swap an empty plate and a user plate
    *
    * @return result of the check
*/
  void MoveEmptyPlate(Direction direction);

  int at(int row, int column);
  int GetRowCount() const;
  int GetColumnCount() const;
 private:
  int _row_count = 4;
  int _column_count = 4;
  int _cell_count = _row_count*_row_count;
  int _empty_index;

  std::vector<int> _board;

  coordinate Convert1DIndexTo2DIndex(int index1d, int rows, int columns);
  int Convert2DIndexTo1DIndex(int row, int column, int row_count);
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
