###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Fifteen_Puzzle_Game)
project(${PROJECT_NAME} VERSION 0.0.1
        DESCRIPTION "Fifteen puzzle game"
        LANGUAGES CXX
        )

###################################################################################################
##
##      Project options
##
###################################################################################################

option(USE_DOC "Turn on documentation" ON)
option(USE_TEST "Turn on testing" ON)

###################################################################################################
##
##      Compilation options
##
###################################################################################################

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

###################################################################################################
##
##      Source files
##
###################################################################################################

set(PROJECT_INCLUDE_DIR include)


add_executable(${PROJECT_NAME})
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_sources(
        ${PROJECT_NAME}
        PRIVATE
        src/main.cpp
        src/log.cpp
        src/model/board.cpp
        src/model/fifteen_puzzle_game.cpp
        src/view/game_render.cpp
        src/controller/game_controller.cpp
)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_INCLUDE_DIR}
)

###################################################################################################
##
##      SFML link
##
###################################################################################################

find_package(SFML 2.5 COMPONENTS audio graphics)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

###################################################################################################
##
##      spdlog link
##
###################################################################################################

add_subdirectory(external/spdlog)
target_link_libraries(${PROJECT_NAME} spdlog)

###################################################################################################
##
##      Documentation
##
###################################################################################################

if (NOT USE_DOC)
    message(STATUS "Autodocumentation is disabled")
else ()
    add_subdirectory(doc)
endif ()

###################################################################################################
##
##      Tests
##
###################################################################################################

if (NOT USE_TEST)
    message(STATUS "Tests is disabled")
else ()
    add_subdirectory(test)
endif ()