add_library(appLib applib.c)

target_include_directories(appLib PUBLIC ./
  ${PROJECT_SOURCE_DIR}/
)
target_compile_features(appLib PUBLIC cxx_std_20)