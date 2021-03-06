/*!
\file
\brief Header file for implementation game board for Fifteen Puzzle Game.

\defgroup model
*/
#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_

#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>
#include <assert.h>

#include "utils/converter.h"

namespace Game {

/*!
	\brief Keyboard arrow keys class.
    \ingroup model
	\version 1.0
*/
enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

/*!
	\brief Game board class.
	\author Dosart
	\version 1.0
*/
class Board final {
 public:
  /**
     * @brief Make a new game board.
     *
     * @param row_count Row count of game board.
     * @param row_count Column count of game board.
 */
  Board(size_t row_count = 4, size_t column_count = 4);
  ~Board() = default;

  /**
   * @brief Initializes the cells of the board in the correct order.
*/
  void Init();

  /**
    * @brief Checks if the puzzle is solved and returns the result of the check.
    *
    * @return Result of the check.
 */
  bool IsSolved() const;

  /**
    * @brief Returns true if cell in right place.
    *
    * @param row Cell's coordinates.
    * @param column Cell's coordinates.
    *
    * @return Result of the check
 */
  bool isCellCorrect(size_t row, size_t column);

  /**
    * @brief Returns true if cell empty.
    *
    * @param row Cell's coordinates.
    * @param column Cell's coordinates.
    *
    * @return Result of the check
*/
  bool isNotEmptyElement(size_t row, size_t column);

  /**
    * @brief Swap an empty plate and a user plate
*/
  void MoveEmptyPlate(Direction direction);

  /**
    * @brief Returns contains of cell by coordinates.
    *
    * @param row Cell's coordinates.
    * @param column Cell's coordinates.
    *
    * @return Contains of cell
*/
  int at(size_t row, size_t column);

  /**
    * @brief Returns rows count of board.
    *
    * @return Row count of board/
*/
  size_t GetRowCount() const;

  /**
  * @brief Returns columns count of board.
  *
  * @return columns count of board/
*/
  size_t GetColumnCount() const;
 private:
  size_t m_row_count = 4;
  size_t m_column_count = 4;
  size_t m_cell_count = m_row_count*m_row_count;
  size_t m_empty_index;

  std::vector<int> m_board;
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_BOARD_H_
