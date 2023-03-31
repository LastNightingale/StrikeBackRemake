cmake_minimum_required (VERSION 3.8)

project(StrikeBack)

add_subdirectory ("src")

add_executable(StrikeBack Application.cpp "src/BackStrike.h")

target_link_libraries(StrikeBack SBSources)