/*!
\file
\brief Header file for logger class
*/

#ifndef FIFTEEN_PUZZLE_GAME_INCLUDE_LOG_H_
#define FIFTEEN_PUZZLE_GAME_INCLUDE_LOG_H_

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <memory>

namespace Game {

/*!
	\brief Logger class
	\author Dosart
	\version 1.0
	\date 09.08.2021

	Simple static logger for game.
*/
class Log final {
 public:
  /**
    * @brief Initialize logger
 */
  static void Init();

  /**
    * @brief Return logger
    *
    * @return spdlog format logger
*/
  static std::shared_ptr<spdlog::logger> GetLogger() { return logger; }

 private:
  static std::shared_ptr<spdlog::logger> logger;
};
}

#define GAME_TRACE(...)    ::Game::Log::GetLogger()->trace(__VA_ARGS__)
#define GAME_INFO(...)     ::Game::Log::GetLogger()->info(__VA_ARGS__)
#define GAME_WARN(...)     ::Game::Log::GetLogger()->warn(__VA_ARGS__)
#define GAME_ERROR(...)    ::Game::Log::GetLogger()->error(__VA_ARGS__)
#define GAME_CRITICAL(...) ::Game::Log::GetLogger()->critical(__VA_ARGS__)

#endif //FIFTEEN_PUZZLE_GAME_INCLUDE_LOG_H_
