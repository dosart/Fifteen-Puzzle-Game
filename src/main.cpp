
#include "log.h"
#include "assets.h"
#include "model/fifteen_puzzle_game.h"
#include "view/game_render.h"
#include "controller/game_controller.h"

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