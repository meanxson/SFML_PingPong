cmake_minimum_required(VERSION 3.12)
project(SFML_PingPong)

set(CMAKE_GENERATOR "MinGW Makefiles ")
message("generator is set to ${CMAKE_GENERATOR}")


set(PROJECT_NAME PingPong)

add_subdirectory(Engine)
add_subdirectory(Game)