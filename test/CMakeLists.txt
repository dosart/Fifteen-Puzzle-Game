###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Test_Fifteen_Puzzle_Game)
project(${PROJECT_NAME} VERSION 0.0.1
        LANGUAGES CXX
        )

find_package(GTest REQUIRED)

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
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${GTEST_INCLUDE_DIRS}
        ../include)
target_sources(${PROJECT_NAME}
        PRIVATE
        ../include/assets.h
        test_main.cpp
        game_test/test_assets.cpp
        game_test/test_utils.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${GTEST_BOTH_LIBRARIES}
        pthread
        sfml-graphics
        sfml-audio)
