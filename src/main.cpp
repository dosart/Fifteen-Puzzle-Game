
#include "utils/log.h"
#include "assets.h"
#include "model/fifteen_puzzle_game.h"
#include "view/game_render.h"
#include "controller/game_controller.h"

int main() {
  ::Game::Log::Init();
  GAME_INFO("Initialized log!");

  if (auto font = Game::LoadFont("../resources/calibri.ttf"); font.has_value()) {
      GAME_INFO("Font loadded.");
    
    ::Game::FifteenPuzzleGame game;
     GAME_INFO("Game created.");
    
    ::Game::GameRender render(&game, font.value());
     GAME_INFO("Render created.");
    
    ::Game::GameController controller(&game, &render);
    GAME_INFO("Controller created.");
    
    GAME_INFO("Game runing.");
    controller.Run();
    GAME_INFO("Game finished.");
    
  } else
    GAME_CRITICAL("Font could not find!");

  return 0;
}
