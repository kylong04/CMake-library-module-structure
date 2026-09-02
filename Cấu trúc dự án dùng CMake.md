# Tổng quan 
Dự án sử dụng thư viện my_library để build một chương trình đơn giản nhằm demo thiết kế thư viện theo hướng module hóa
# Mục tiêu
Hướng dẫn tạo thư viện my_library với cấu hình CMake module hóa (modularization).
#### Ưu điểm:
- Dễ bảo trì (maintainable)
- Tái sử dụng (reusable)
- Có thể mở rộng (scalable)
- Dễ phân phối (distributable) tới nhiều người dùng khi release
# Dự án với cấu trúc module thư viện
```
 📁 Project1/
 ├── 📁 my_library/
 │    ├── 📁 include/
 │    │    └── 📁 CoreLogic/
 │    │         └── 📄 CoreLogic.h
 │    ├── 📁 src/
 │    │    └── 📄 CoreLogic.cpp
 │    └── 📄 CMakeLists.txt

 ├── 📁 app/
 │    ├── 📁 src/
 │    │    └── 📄 main.cpp
 │    └── 📄 CMakeLists.txt
 │   
 └── 📄 CMakeLists.txt (gốc)
 ```
 Mỗi module thư viện đều chứa file CMakeLists.txt trong thư mục của chính nó. File CMakeLists.txt thuộc cấp thư mục Project1 được gọi là root CMakeLists, các lệnh thực thi cấu hình CMake sẽ bắt đầu từ file này.
Dựa theo đối số truyền vào add_subdirectory(). CMake sẽ xác định được các file CMakeList con thuộc thư mục my_library và app
 - ```my_library```: là thư mực thư viện
 - ```app```: là thư mục chứ file thực thi
 - ```Project1/CMakeLists.txt```: đây là file CMakeLists gốc, có quyền cao nhất, điều phối toàn bộ dự án và liên kết các thư mục con
 #### Các file CMakeLists ở các thư mục
 - ```Project1/my_library/CMakeLists.txt```: Phục vụ cấu hình CMake cho thư viện my_library
 - ```Project1/app/CMakeLists.txt```:  CMakeLists trong thư mục app phục vụ cấu hình để build ra file thực thi (executable) và không phải là module thư viện
 ## ```Project1/CMakeLists.txt```
 Chức năng: định nghĩa thiết lập cho toàn bộ dự án và sau đó sử dụng phương thức ```add_subdirectory()```
 ### Nội dung của ```Project1/CMakeLists.txt```
 ```
 cmake_minimum_required(VERSION 3.16)

# Tên của dự án
project(Project1)

# Thêm các module của dự án
add_subdirectory(my_library) # The library 
add_subdirectory(app)        # The executable
```
#### Thứ tự biên dịch
Luôn khai báo add_subdirectory() của thư viên trước file thực thi. CMkake sẽ đóng gói thư viện, công khai các đường dẫn Header rồi sau đó mới qua thư mục ```app``` để biên dịch và liên kết với my_library được tạo ở bước trước.
## Project1/my_library/CMakeLists.txt
Chức năng: Tạo ra một đối tượng CMake (CMake target) có tên là my_libraryLib từ file source là src/CoreLogic.cpp

Đối tượng CMake này sử dụng các file header trong thư mục include tính từ đường dẫn CMakeList hiện tại đang thao tác (${CMAKE_CURRENT_SOURCE_DIR}). Vì các hàm định nghĩa(function prototype) trong file header được gọi  bởi chương trình main.c trong thư mục app, do đó cần cấu hình lan truyền header (propagation) ở chế độ PUBLIC để trong main.c có thể thấy được các hàm định nghĩa trong CoreLogic.h

Đối tượng CMake my_libraryLib được biên dịch với ngôn ngữ C++ 20

### Nội dung của ```Project1/CMakeLists.txt```
```
cmake_minimum_required(VERSION 3.16)

add_library(my_libraryLib src/CoreLogic.cpp)
target_include_directories(my_libraryLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(my_libraryLib PUBLIC cxx_std_20)
```
### Project1/app/CMakeLists.txt
Chức năng: chịu trách nhiệm định nghĩa thư mục thực thi app.
Chúng ta sử dụng nó để định nghĩa tệp thực thi mục tiêu cần tạo ra là Project1App, sử dụng tiêu chuẩn C++20 và liên kết với my_libraryLib.
```
cmake_minimum_required(VERSION 3.16)

add_executable(Project1App src/main.cpp)
target_compile_features(Project1App PUBLIC cxx_std_20)
target_link_libraries(Project1App my_libraryLib)
```
# Nội dung của các file
### CoreLogic.h
```
#pragma once
#include <string>

std::string get_greeting();
```
### CoreLogic.cpp
```
#include "CoreLogic.h"

std::string get_greeting() {
  return "Hello from the Greeter library!";
}
```
### main.cpp
```
#include <iostream>
#include "CoreLogic.h"

int main() {
  std::cout << get_greeting();
  return 0;
}
```
## Hướng dẫn buil và biên dịch trên Power shell terminal
### Tạo thư mục build
```
mkdir build && cd build
```
### Build mã nguồn và biên dịch
```
cmake -G "MinGW Makefiles" ..
mingw32-make 
```
### Chạy file thực thi
```
cd app
.\GreeterApp.exe
```
## Kết quả đạt được
```
Hello from the Greeter library!
```