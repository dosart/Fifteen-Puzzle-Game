#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

namespace Game {

sf::Font LoadFont(std::string fontName) {
  sf::Font font;
  if (!font.loadFromFile(fontName))
    throw std::runtime_error("Could not open file");
  return font;
}
}
#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
