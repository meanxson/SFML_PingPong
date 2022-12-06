cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Engine)

add_library(${PROJECT_NAME} STATIC 
		    src/EngineCore/Utils/test.cpp
			includes/EngineCore/Utils/test.hpp
		src/EngineCore/Maths/Vector2.cpp includes/EngineCore/Maths/Vector2.h includes/EngineCore/Utils/Constants.h src/EngineCore/IO/Keyboard.cpp includes/EngineCore/IO/Keyboard.h src/EngineCore/IO/Screen.cpp includes/EngineCore/IO/Screen.h includes/EngineCore/Utils/Log.hpp src/EngineCore/Utils/ResourceManager.cpp includes/EngineCore/Utils/ResourceManager.h)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
#target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)

if(APPLE OR UNIX)
	include_directories(/usr/local/include)
else()
	set(SFML_DIR "C:/Libraries/SFML/lib/cmake/SFML")
	set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

if (SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
endif()

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# OpenGL part
if (APPLE)
	set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
	set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
	include_directories(${GLEW_H} ${GLFW_H})

	set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
	set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
	link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

	target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
	target_link_libraries(${CMAKE_PROJECT_NAME} "-framework GLUT")
elseif(UNIX)
	find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)

	target_link_libraries(${CMAKE_PROJECT_NAME} ${OPENGL_LIBRARIES})
	target_link_libraries(${CMAKE_PROJECT_NAME} ${GLUT_LIBRARY})
endif()