#include <controller/game_controller.h>

namespace Game {

GameController::GameController(FifteenPuzzleGame *game, GameRender *render)
    : m_game{game}, m_render{render} {

}
void GameController::Run() {
  sf::Event event;

  int move_counter = 0;

  while (m_render->Window().isOpen()) {
    while (m_render->Window().pollEvent(event)) {
      if (event.type==sf::Event::Closed) {
        m_render->Window().close();
        GAME_INFO("The window closed. Finish game");
      }
      if (event.type==sf::Event::KeyPressed) {

        if (event.key.code==sf::Keyboard::Escape) {
          m_render->Window().close();
          GAME_INFO("The escape button is pressed");
        }
        if (event.key.code==sf::Keyboard::Left) {
          m_game->MoveEmptyPlate(Direction::Left);
          GAME_INFO("The left button is pressed");
        }
        if (event.key.code==sf::Keyboard::Right) {
          m_game->MoveEmptyPlate(Direction::Right);
          GAME_INFO("The right button is pressed");
        }
        if (event.key.code==sf::Keyboard::Up) {
          m_game->MoveEmptyPlate(Direction::Up);
          GAME_INFO("The up button is pressed");
        }
        if (event.key.code==sf::Keyboard::Down) {
          m_game->MoveEmptyPlate(Direction::Down);
          GAME_INFO("The down button is pressed");
        }

        if (event.key.code==sf::Keyboard::F2) {
          m_game->StartNewGame();
          move_counter = 100;
          GAME_INFO("The F2 button is pressed. New game.");
        }
      }
    }
    if (move_counter-- > 0)
      m_game->MoveEmptyPlate(direction[size_t(rand()%4)]);

    m_render->Render();
  }
}
}