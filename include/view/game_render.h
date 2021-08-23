/*!
\file
\brief Header file for Simple class for game draw.
\defgroup view
\defgroup model
*/
#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_

#include <SFML/Graphics.hpp>
#include "model/fifteen_puzzle_game.h"

namespace Game {

/*!
	\brief Class for drawing game.
	\author Dosart
    \ingroup view
	\version 1.0
*/
class GameRender : public sf::Drawable, public sf::Transformable {
 public:
  /**
    * @brief Make simple render.
    *
    * @param game Game.
    * @param font Font for game.

*/
  GameRender(FifteenPuzzleGame *game, sf::Font font);
  ~GameRender() = default;

  /**
    * @brief Refresh window state.
*/
  void Render();

  /**
  * @brief Returns game's window.
  * @return game's window
*/
  sf::RenderWindow &Window();

  /**
  * @brief Draws board's frame and cells.
*/
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
  FifteenPuzzleGame *m_game;
  sf::Font m_font;

  sf::RenderWindow m_window;
  sf::Text m_text;

  const float kFieldSize = 500.0;
  const float kCellSize = 120.0;

  bool _init();
  void _setPosition(sf::RectangleShape &cellOfBoard, sf::Text &textInCell, size_t row, size_t column) const;
};
}

#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_
