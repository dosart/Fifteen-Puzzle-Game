#include <game_controller.h>

namespace Game {

GameController::GameController(FifteenPuzzleGame *game, GameRender *render)
    : _game(game), _render(render) {

}
void GameController::Run() {
  sf::Event event;

  while (_render->Window().isOpen()) {
    while (_render->Window().pollEvent(event)) {
      if (event.type==sf::Event::Closed) _render->Window().close();
      if (event.type==sf::Event::KeyPressed) {
        // Получаем нажатую клавишу - выполняем соответствующее действие
        if (event.key.code==sf::Keyboard::Escape) _render->Window().close();
        if (event.key.code==sf::Keyboard::Left) _game->MoveEmptyPlate(Direction::Left);
        if (event.key.code==sf::Keyboard::Right) _game->MoveEmptyPlate(Direction::Right);
        if (event.key.code==sf::Keyboard::Up) _game->MoveEmptyPlate(Direction::Up);
        if (event.key.code==sf::Keyboard::Down) _game->MoveEmptyPlate(Direction::Down);
        // Новая игра
        if (event.key.code==sf::Keyboard::F2) {
          _game->Reload();
        }
      }
    }
    _render->Render();
  }

}
}