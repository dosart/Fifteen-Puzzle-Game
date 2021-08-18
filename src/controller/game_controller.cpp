#include <controller/game_controller.h>

namespace Game {

GameController::GameController(FifteenPuzzleGame *game, GameRender *render)
    : m_game(game), m_render(render) {

}
void GameController::Run() {
  sf::Event event;

  while (m_render->Window().isOpen()) {
    while (m_render->Window().pollEvent(event)) {
      if (event.type==sf::Event::Closed) m_render->Window().close();
      if (event.type==sf::Event::KeyPressed) {
        // Получаем нажатую клавишу - выполняем соответствующее действие
        if (event.key.code==sf::Keyboard::Escape) m_render->Window().close();
        if (event.key.code==sf::Keyboard::Left) m_game->MoveEmptyPlate(Direction::Left);
        if (event.key.code==sf::Keyboard::Right) m_game->MoveEmptyPlate(Direction::Right);
        if (event.key.code==sf::Keyboard::Up) m_game->MoveEmptyPlate(Direction::Up);
        if (event.key.code==sf::Keyboard::Down) m_game->MoveEmptyPlate(Direction::Down);
        // Новая игра
        if (event.key.code==sf::Keyboard::F2) {
          m_game->Reload();
        }
      }
    }
    m_render->Render();
  }

}
}