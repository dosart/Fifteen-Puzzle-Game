/*!
\file
\brief Header file for implementation game.
*/
#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_

#include "model/board.h"

namespace Game {
/*!
	\brief Game class.
	\author Dosart
    \ingroup model
	\version 1.0
*/
class FifteenPuzzleGame final {

 public:
  FifteenPuzzleGame();
  ~FifteenPuzzleGame() = default;

  /**
    * @brief Returns game's board.
    * @return board
 */
  Board &GetBoard();

  /**
    * @brief  Starts new game.
 */
  void StartNewGame();

  /**
   * @brief  Swaps an empty cell with an adjacent one.
*/
  void MoveEmptyPlate(Direction direction);

  /**
   * @brief  Returns true if puzzle is solved.
   * @return true if puzzle is solved.
*/
  bool IsSolved() const;
 private:
  const int m_kRowCount = 4;
  const int m_kColumnCount = 4;

  Board m_board;
};
}
#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_MODEL_H_
