cmake_minimum_required(VERSION 3.0.0)
project(DesignPatternStudySamples VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# link all files in codes(CURRENT_SOURCE_DIR)
# But changing the CMakeLists.txt file triggers running cmake.
# without rerun CMake, the new files are not added to the build file.
# https://stackoverflow.com/questions/25072485/cmake-add-all-sources-in-subdirectory-to-cmake-project
#[===[  # multiline comment in cmake file
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SUB_SOURCES)

set(SOURCE
  ${SOURCE}
  ${SUB_SOURCES}
)
add_executable(DesignPatternStudySamples main.cpp ${SOURCE})#Mazes/Maze.cpp Mazes/Maze.h Mazes/MazeFactory.h MazeGame.hpp CustomException.hpp)
]===] # end of multiline comment in cmake file

file(GLOB SOURCES
        Mazes/*.h
        Mazes/*.cpp
        CustomException.hpp
        MazeGame.hpp
)

add_executable(DesignPatternStudySamples main.cpp ${SOURCES})#Mazes/Maze.cpp Mazes/Maze.h Mazes/MazeFactory.h MazeGame.hpp CustomException.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)