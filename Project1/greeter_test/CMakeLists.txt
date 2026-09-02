cmake_minimum_required(VERSION 3.16)

add_library(CoreLogic src/Greeter.cpp)  #Tạo ra một mục tiêu (target) tên là Project1Lib từ file code.
target_include_directories(CoreLogic PUBLIC     #Đây là phần quan trọng nhất:
                                                  #Nó nói với CMake rằng: "Bất cứ ai dùng Project1Lib đều được quyền truy cập 
                                                  #vào các file .h trong thư mục include/greeter".

                                                  #Từ khóa PUBLIC có nghĩa là: cả bản thân thư viện và các project bên ngoài (như app)
                                                  #đều nhìn thấy các file header này.
  ${CMAKE_CURRENT_SOURCE_DIR}/include/greeter
)
target_compile_features(CoreLogic PUBLIC cxx_std_20) #Ép dự án sử dụng chuẩn C++20.