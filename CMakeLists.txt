cmake_minimum_required(VERSION 3.25)
project(Igra)

find_package(raylib REQUIRED)



set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)



set(SOURCES
    main.c
    matrix2d.c
    game.c
)
set(HEADER
    matrix.h
    game.h
)



add_executable(Igra ${SOURCES})
target_link_libraries(Igra raylib)
