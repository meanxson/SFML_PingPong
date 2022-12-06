cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME PingPongEditor)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

add_executable(${PROJECT_NAME}
	src/main.cpp
	)
	
target_link_libraries(${PROJECT_NAME} Game)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)