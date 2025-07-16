cmake_minimum_required(VERSION 3.0)

project(slide)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(SOURCE_FILES
    src/main.cpp
    src/app.cpp
    src/renderer.cpp
    src/input.cpp
    src/page.cpp
    src/component.cpp
    src/state_machine.cpp
    src/text_component_state.cpp
    )



add_executable(slide ${SOURCE_FILES})

include_directories(include)
target_link_libraries(slide raylib GL pthread dl rt X11)
