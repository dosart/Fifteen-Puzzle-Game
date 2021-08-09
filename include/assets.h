/*!
\file
\brief Header file for work on resources of  game

This file contains functions for work on resources of game
*/

#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

namespace Game {

/**
 * @brief Load font from resources
 *
 * @param fontName Name of font for load
 *
 * @return SFML format font
 */
sf::Font LoadFont(std::string fontName) {
  sf::Font font;
  if (!font.loadFromFile(fontName))
    throw std::runtime_error("Could not open file");
  return font;
}
}
#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
