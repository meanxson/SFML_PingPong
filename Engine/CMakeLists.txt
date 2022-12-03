cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Engine)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

add_library(${PROJECT_NAME} STATIC 
		    src/EngineCore/Utils/test.cpp
			includes/EngineCore/Utils/test.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
