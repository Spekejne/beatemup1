cmake_minimum_required(VERSION 3.10)
project(BeatEmUp)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main
        main.cpp
        Game.cpp
        Player.cpp
        Enemy.cpp
        Stage.cpp
        Menu.cpp
        Input.cpp
        Score.cpp
        Config.cpp
        Input.cpp
        Input.h
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        Stage.cpp
        Stage.h
        Menu.cpp
        Menu.h
        Score.cpp
        Score.h
        Config.cpp
        Config.h
)

target_link_libraries(main ${SDL2_LIBRARIES})
