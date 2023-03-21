cmake_minimum_required(VERSION 3.15)
project(BeefRogue)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src/Game)
include_directories(${PROJECT_SOURCE_DIR}/src/Characters)

add_executable(BeefRogue src/main.cpp src/Game/Game.cpp src/Game/Game.h src/Characters/Character.h src/Characters/Character.h src/Controls/Command.h src/Characters/Character.cpp src/Controls/InputHandler.cpp src/Controls/InputHandler.h src/Game/Definitions.h src/Game/Structs.h src/Game/Init.cpp src/Game/Init.h src/Game/Common.h src/main.h)

target_link_libraries(BeefRogue ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2)