
#include "log.h"
#include "assets.h"
#include "fifteen_puzzle_game.h"
#include "game_render.h"
#include "game_controller.h"

int main() {
  ::Game::Log::Init();
  GAME_WARN("Initialized log!");

  try {
    auto font = Game::LoadFont("../resources/calibri.ttf");

    ::Game::FifteenPuzzleGame game;
    ::Game::GameRender render(&game, font);
    ::Game::GameController controller(&game, &render);
    controller.Run();
  }
  catch (...) {
    GAME_CRITICAL("Font could not find!");
  }
  return 0;
}