//
// Created by meanx on 06/12/2022.
//

#ifndef SFML_PINGPONG_LOG_H
#define SFML_PINGPONG_LOG_H

namespace Log {
#define LOG_INFO(...)       spdlog::info(__VA_ARGS__)
#define LOG_WARN(...)       spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...)      spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...)   spdlog::critical(__VA_ARGS__)s
}


#endif //SFML_PINGPONG_LOG_H
