/*!
\file
\brief Header file for implementation controller.

 Implements the Game Loop Design Pattern:
    - polling I/O devices;
    - state update;
    - frame drawing.
*/
#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_

#include "view/game_render.h"
#include "game_controller.h"

namespace Game {

/*!
	\brief Controller class.
	\author Dosart
	\version 1.0
*/
class GameController final {
 public:

  /**
   * @brief Constructor.
   *
   * @param game Game.
   * @param render Render for drawing game.

*/
  GameController(FifteenPuzzleGame *game, GameRender *render);
  ~GameController() = default;

  /**
    * @brief Implements the Game Loop Design Pattern.
 */
  void Run();
 private:
  FifteenPuzzleGame *m_game;
  GameRender *m_render;
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_
