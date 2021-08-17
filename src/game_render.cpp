
#include "game_render.h"

Game::GameRender::GameRender(Game::FifteenPuzzleGame *game, sf::Font font)
    : _game{game}, _font{font} {
  Init();
}

bool Game::GameRender::Init() {
  setPosition(50.f, 50.f);
  _window.create(sf::VideoMode(600, 600), "Fifteen-Puzzle-Game");
  _window.setFramerateLimit(60);
  _text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", _font, 20);
  _text.setFillColor(sf::Color::Cyan);
  _text.setPosition(5.f, 5.f);
  return true;
}

void Game::GameRender::Render() {
  _window.clear();
  _window.draw(*this);
  _window.draw(_text);
  _window.display();
}

void Game::GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {

  states.transform *= getTransform();
  sf::Color color = sf::Color(200, 100, 200);

  sf::RectangleShape frameOfBoard(sf::Vector2f(kFieldSize, kFieldSize));
  frameOfBoard.setOutlineThickness(2.f);
  frameOfBoard.setOutlineColor(color);
  frameOfBoard.setFillColor(sf::Color::Transparent);
  target.draw(frameOfBoard, states);

  sf::RectangleShape cellOfBoard(sf::Vector2f(kCellSize, kCellSize));
  cellOfBoard.setOutlineThickness(2.f);
  cellOfBoard.setOutlineColor(color);
  cellOfBoard.setFillColor(sf::Color::Transparent);

  auto &board = _game->GetBoard();
  for (auto row = 0; row < board.GetRowCount(); ++row) {
    for (auto column = 0; column < board.GetColumnCount(); ++column) {
      float column_float = static_cast<float>(column);
      float row_float = static_cast<float>(row);

      sf::Vector2f position(column_float * kCellSize + 10.f, row_float * kCellSize + 10.f);
      cellOfBoard.setPosition(position);
      target.draw(cellOfBoard, states);
    }
  }

}

sf::RenderWindow &Game::GameRender::Window() {
  return _window;
}

