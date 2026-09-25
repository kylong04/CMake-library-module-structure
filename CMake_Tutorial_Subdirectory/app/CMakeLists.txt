cmake_minimum_required(VERSION 3.16)

add_executable(main_src src/main.cpp)                
target_compile_features(main_src PUBLIC cxx_std_20)   
target_link_libraries(main_src CoreLogic_Lib)          