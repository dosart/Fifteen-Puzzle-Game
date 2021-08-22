find_package(GTest REQUIRED)

add_executable(Test)
target_include_directories(Test PRIVATE ${GTEST_INCLUDE_DIRS})
target_sources(Test PRIVATE  ../include/assets.h test_main.cpp game_test/test_assets.cpp)
target_link_libraries(Test PRIVATE ${GTEST_BOTH_LIBRARIES})
target_link_libraries(Test PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)