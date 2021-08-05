#include "log.h"

int main()
{
  ::Game::Log::Init();
  GAME_WARN("Initialized log!");

  return 0;
}