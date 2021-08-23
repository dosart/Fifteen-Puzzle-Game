
#include "view/game_render.h"

Game::GameRender::GameRender(Game::FifteenPuzzleGame *game, sf::Font font)
    : m_game{game}, m_font{font} {
  _init();
}

sf::RenderWindow &Game::GameRender::Window() {
  return m_window;
}

bool Game::GameRender::_init() {
  setPosition(50.f, 50.f);
  m_window.create(sf::VideoMode(600, 600), "Fifteen-Puzzle-Game");
  m_window.setFramerateLimit(60);
  m_text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", m_font, 20);
  m_text.setFillColor(sf::Color::Cyan);
  m_text.setPosition(5.f, 5.f);
  return true;
}

void Game::GameRender::Render() {
  m_window.clear();
  m_window.draw(*this);
  m_window.draw(m_text);
  m_window.display();
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

  sf::Text textInCell("", m_font, 52);

  auto &board = m_game->GetBoard();
  for (size_t row = 0; row < board.GetRowCount(); ++row) {
    for (size_t column = 0; column < board.GetColumnCount(); ++column) {

      auto numberAsString = std::to_string(board.at(row, column));
      textInCell.setString(numberAsString);

      _setPosition(cellOfBoard, textInCell, row, column);

      cellOfBoard.setOutlineColor(color);
      textInCell.setFillColor(color);

      if (m_game->IsSolved()) {
        frameOfBoard.setOutlineColor(sf::Color::Cyan);
        textInCell.setFillColor(sf::Color::Cyan);
      } else if (board.isCellCorrect(row, column)) {
        textInCell.setFillColor(sf::Color::Green);
      }

      target.draw(cellOfBoard, states);
      if (board.isNotEmptyElement(row, column))
        target.draw(textInCell, states);
    }
  }
}

void Game::GameRender::_setPosition(sf::RectangleShape &cellOfBoard,
                                    sf::Text &textInCell,
                                    size_t row,
                                    size_t column) const {
  float column_float = static_cast<float>(column);
  float row_float = static_cast<float>(row);

  sf::Vector2f position(column_float*kCellSize + 10.f, row_float*kCellSize + 10.f);
  cellOfBoard.setPosition(position);
  textInCell.setPosition(position.x + 30.f, position.y + 30.f);
}

