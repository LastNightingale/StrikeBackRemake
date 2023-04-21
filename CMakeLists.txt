cmake_minimum_required (VERSION 3.8)

project(StrikeBack)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory ("src")

add_executable(StrikeBack Application.cpp  "src/Wall.h")

target_link_libraries(StrikeBack SBSources)