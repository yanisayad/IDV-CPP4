cmake_minimum_required(VERSION 3.2)
project(workshop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AbstractEntity.cpp AbstractEntity.h EntityFactory.cpp EntityFactory.h TimeManager.cpp TimeManager.h Menu.cpp Menu.h Snake.cpp Snake.h Options.cpp Options.h Apple.cpp Apple.h Game.cpp Game.h EndMenu.cpp EndMenu.h)

add_executable(workshop ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(workshop ${SFML_LIBRARIES})
endif()