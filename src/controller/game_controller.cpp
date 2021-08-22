#include <controller/game_controller.h>

namespace Game {

GameController::GameController(FifteenPuzzleGame *game, GameRender *render)
    : m_game(game), m_render(render) {

}
void GameController::Run() {
  sf::Event event;

  std::array<Direction, 4> direction = {Direction::Left, Direction::Right, Direction::Down, Direction::Up};
  int move_counter = 0;

  while (m_render->Window().isOpen()) {
    while (m_render->Window().pollEvent(event)) {
      if (event.type==sf::Event::Closed) m_render->Window().close();
      if (event.type==sf::Event::KeyPressed) {

        if (event.key.code==sf::Keyboard::Escape) m_render->Window().close();
        if (event.key.code==sf::Keyboard::Left) m_game->MoveEmptyPlate(Direction::Left);
        if (event.key.code==sf::Keyboard::Right) m_game->MoveEmptyPlate(Direction::Right);
        if (event.key.code==sf::Keyboard::Up) m_game->MoveEmptyPlate(Direction::Up);
        if (event.key.code==sf::Keyboard::Down) m_game->MoveEmptyPlate(Direction::Down);

        if (event.key.code==sf::Keyboard::F2) {
          m_game->StartNewGame();
          move_counter = 100;
        }
      }
    }
    if (move_counter-- > 0)
      m_game->MoveEmptyPlate(direction[size_t(rand()%4)]);

    m_render->Render();
  }

}
}