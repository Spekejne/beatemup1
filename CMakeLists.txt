cmake_minimum_required(VERSION 3.10)
project(beatemup)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(beatemup
    main.cpp
    Game.cpp
    Player.cpp
    Enemy.cpp
    Stage.cpp
)

target_include_directories(beatemup PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries(beatemup
    SDL2::SDL2
    SDL2_image::SDL2_image
)
