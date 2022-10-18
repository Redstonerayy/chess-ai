cmake_minimum_required(VERSION 3.24)
project(chess_ai)

set(CMAKE_CXX_STANDARD 20)

# build chess
FILE(GLOB SOURCE_FILES src/chess/*.cpp)
add_library(chess ${SOURCE_FILES})
target_include_directories(chess PRIVATE src/chess)

# main file
add_executable(main src/main.cpp ${SOURCE_FILES})
target_include_directories(main PRIVATE src/include)
target_link_libraries(main PRIVATE chess)
