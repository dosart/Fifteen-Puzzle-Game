#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

namespace Game {

class AssetsSingleton final {

 public:
  static AssetsSingleton &Instance() {
    static AssetsSingleton settings;
    return settings;
  }

  sf::Font LoadFont(std::string fontName) {
    sf::Font font;
    if (!font.loadFromFile(fontName))
      throw std::runtime_error("Could not open file");
    return font;
  }

  AssetsSingleton() = default;
  ~AssetsSingleton() = default;

  AssetsSingleton(const AssetsSingleton &) = delete;
  AssetsSingleton &operator=(const AssetsSingleton &) = delete;

  AssetsSingleton(const AssetsSingleton &&) = delete;
  AssetsSingleton &operator=(const AssetsSingleton &&) = delete;
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
