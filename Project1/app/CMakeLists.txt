cmake_minimum_required(VERSION 3.16)

add_executable(FinalGame src/main.cpp)                 #Tạo ra file chạy từ mã nguồn chính.
target_compile_features(FinalGame PUBLIC cxx_std_20)   
target_link_libraries(FinalGame my_libraryLib)          #Đây là "sợi dây liên kết".

                                                        #Lệnh này bảo CMake: "Hãy lấy toàn bộ code đã biên dịch của Project1Lib 
                                                        #gắn vào Project1App".

                                                        #Nhờ từ khóa PUBLIC ở bước trước, main.cpp bây giờ có thể #include "CoreLogic.h" 
                                                        #mà không bị báo lỗi thiếu file.