cmake_minimum_required(VERSION 3.16)

add_library(CoreLogic_Lib src/CoreLogic.cpp)  
target_include_directories(CoreLogic_Lib PUBLIC    
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(CoreLogic_Lib PUBLIC cxx_std_20)