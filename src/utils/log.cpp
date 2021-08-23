#include "utils/log.h"

namespace Game {

std::shared_ptr<spdlog::logger> Log::logger;

void Log::Init() {
  logger = spdlog::basic_logger_mt("game_logger", "logs/game-log.txt");
  logger->set_pattern("%^[%T] %n: %v%$");
  logger->flush_on(spdlog::level::trace);
}
}