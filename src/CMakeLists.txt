cmake_minimum_required (VERSION 3.8)

set(CORE_SOURCES
"Random.cpp")

set(BUILD_SHARED_LIBS OFF)

add_subdirectory ("sfml")

add_library(SBSources STATIC ${CORE_SOURCES} "Block.h" "Blocks.h" "Block.cpp" "Game.h" "Game.cpp" "Player.h" "Player.cpp" 
"Bullet.h" "Bullet.cpp" "Enemy.h" "Enemy.cpp" "BackStrike.cpp" "Semaphore.h" "Destroyer.cpp")

target_link_libraries(SBSources 
PUBLIC sfml-system PUBLIC sfml-graphics PUBLIC sfml-network 
PUBLIC) 

target_include_directories(SBSources 
	PUBLIC "./")