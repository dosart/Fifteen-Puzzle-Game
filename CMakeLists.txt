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

set(SOURCES
        src/main.cpp
        src/log.cpp
        src/board.cpp)

set(HEADERS
        include/assets.h
        include/log.h
        include/board.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        include
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

if(NOT USE_DOC)
    message(STATUS "Autodocumentation is disabled")
else()
    add_subdirectory(doc)
endif()

###################################################################################################
##
##      Tests
##
###################################################################################################

if(NOT USE_TEST)
    message(STATUS "Tests is disabled")
else()
    add_subdirectory(test)
endif()
