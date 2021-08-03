cmake_minimum_required(VERSION 3.19)

set(PROJECT_NAME Fifteen_Puzzle_Game)
project(${PROJECT_NAME} VERSION 0.0.1
                  DESCRIPTION "Fifteen puzzle game"
                  LANGUAGES CXX
)
                  
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
 )
 
 set(SOURCES
        src/main.cpp
  )
  
   set(HEADERS
        include/assets.h
  )

include_directories(include)

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)

find_package(SFML REQUIRED 2.5 COMPONENTS audio graphics)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

add_subdirectory(external/spdlog)
target_link_libraries(${PROJECT_NAME} spdlog)

