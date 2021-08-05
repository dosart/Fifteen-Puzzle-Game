
#include "log.h"
#include "assets.h"

int main() {
  ::Game::Log::Init();
  GAME_WARN("Initialized log!");

  try {
    auto font = Game::LoadFont("../resources/calibri.ttf");
  }
  catch (...) {
    GAME_CRITICAL("Font could not find!");
  }
  return 0;
}