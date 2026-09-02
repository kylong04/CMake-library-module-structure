cmake_minimum_required(VERSION 3.16)

# Name the overall project
project(Project1)

# Bring in our components
add_subdirectory(greeter_test) # The library Bảo CMake đi vào thư mục greeter_test để xây dựng thư viện trước.
add_subdirectory(app)     # The executable   Sau đó đi vào thư mục app để xây dựng file thực thi.