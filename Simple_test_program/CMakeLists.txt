cmake_minimum_required(VERSION 3.16)
project(simple_test_program VERSION 1.0)

add_subdirectory(appLib)

add_executable(main_src main.c)
target_link_libraries(main_src appLib)

add_executable(test_src test_program.c)
target_link_libraries(test_src appLib)
