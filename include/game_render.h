#ifndef FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_
#define FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_

#include <SFML/Graphics.hpp>
#include "fifteen_puzzle_game.h"

namespace Game {

class GameRender : public sf::Drawable, public sf::Transformable {
 public:
  GameRender(FifteenPuzzleGame *game, sf::Font font);
  ~GameRender() = default;

  bool Init();
  void Render();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
  FifteenPuzzleGame *_game;
  sf::Font _font;

  sf::RenderWindow _window;
  sf::Text _text;

  const float kFieldSize = 500.0;
  const float kCellSize = 120.0;
};
}

#endif //FIFTEEN_PUZZLE_GAME_SRC_GAME_RENDER_H_
