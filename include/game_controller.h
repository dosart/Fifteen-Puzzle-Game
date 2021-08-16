#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_

#include "game_render.h"
#include "game_controller.h"

namespace Game {
class GameController final {
  FifteenPuzzleGame *_game;
  GameRender *_render;
 public:
  GameController(FifteenPuzzleGame *game, GameRender *render);
  ~GameController() = default;
  void Run();
};
}

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_GAME_CONTROLLER_H_
