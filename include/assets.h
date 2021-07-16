#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_

#include <SFML/Graphics.hpp>

class AssetsSingleton final {

 public:
  static AssetsSingleton &Instance() {
    static AssetsSingleton settings;
    return settings;
  }

  AssetsSingleton(const AssetsSingleton &) = delete;
  AssetsSingleton &operator=(const AssetsSingleton &) = delete;
};

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_SETTINGS_H_
