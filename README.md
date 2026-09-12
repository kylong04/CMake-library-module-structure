# Hướng dẫn cấu hình và biên dịch dự án C++ với CMake & MinGW

Dự án sử dụng thư viện `my_library` để build một chương trình đơn giản nhằm demo thiết kế thư viện theo hướng module hóa

## Mục tiêu
Hướng dẫn tạo thư viện `my_library` với cấu hình CMake module hóa (modularization).

Ưu điểm:

- Dễ bảo trì (maintainable)
- Tái sử dụng (reusable)
- Có thể mở rộng (scalable)
- Dễ phân phối (distributable) tới nhiều người dùng khi release 

## 1. Môi trường & Thiết lập

**Môi trường**: chạy **môi trường Unix** trên Window

**Trình biên dịch & Build tool:** GCC/G++ (MinGW-w64) và CMake

**Công cụ cần cài đặt:**

- **CMake**: Tải tool tại [CMake](https://cmake.org/download/) và lựa chọn phiên bản phù hợp với hệ điều hành của máy

- **MinGW-w64**: 
    - **Cài đặt MinGW** tại [link](https://www.msys2.org/)   
        1. Sau khi cài đặt `MinGW`, mở `MSYS2` và chạy lệnh bên dưới để cài đặt `GCC` toolchain (Lưu ý: Để toàn bộ đường dẫn cài đặt là mặc định)
            ```powershell
            pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
            ```
        2. Nhấn `Enter` để đồng ý cài đặt toàn bộ số lượng gói mặc định.

        3. Nhấn `Y` để đồng ý bắt đầu cái đặt.
  
        4. Thêm đường dẫn vào môi trường của Windows:
  
  - Truy cập `Windows search` tìm kiếm `Edit environment variables for your account` .
  
  - Ở mục `User variables for ADMIN`, chọn Variable `Path` và sau đó nhấn Edit

  - Chọn `New` và thêm đường dẫn `C:\msys64\ucrt64\bin` (Nếu cài mặc định, không thay đổi đường dẫn trong quá trình cài MSYS2) sau đó nhấn OK

  - Chọn `OK` trong `Edit environment variables for your account` để Windows update môi trường variable `Path`.

  - Khởi động lại máy tính để cập nhật đường dẫn cho MinGW.

## 2. Cấu trúc Dự án & Cấu hình Cmake
```
 📁 Project1/
 ├── 📁 my_library/                           #Module thư viện
 │    ├── 📁 include/
 │    │    └── 📄 CoreLogic.h
 │    ├── 📁 src/
 │    │    └── 📄 CoreLogic.cpp
 │    └── 📄 CMakeLists.txt
 │
 ├── 📁 app/                                  # Mã nguồn ứng dụng (source program application)
 │    ├── 📁 src/
 │    │    └── 📄 main.cpp
 │    └── 📄 CMakeLists.txt
 │   
 └── 📄 CMakeLists.txt                        #Root CMake
 ```

### Root `CMakeLists.txt`
 __Chức năng__: Chứa thông tin cấu hình toàn bộ dự án.
#### Nội dung của root `CMakeLists.txt`
 ```cmake
 cmake_minimum_required(VERSION 3.16)

# Tên của dự án
project(Project1)

# Thêm các module của dự án
add_subdirectory(my_library) # The library 
add_subdirectory(app)        # The executable
```
File CMakeLists.txt thuộc cấp thư mục `Project1` được gọi là __*root CMakeLists*__, các lệnh thực thi cấu hình CMake sẽ bắt đầu từ file này. Dựa theo đối số truyền vào `add_subdirectory()`. CMake sẽ xác định được các file CMakeList con thuộc thư mục my_library và app
### CMakeLists.txt ở thư mục my_library
Mỗi module thư viện đều chứa file CMakeLists.txt trong thư mục của chính nó. 
#### Nội dung 
```cmake
cmake_minimum_required(VERSION 3.16)

add_library(my_libraryLib src/CoreLogic.cpp)
target_include_directories(my_libraryLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(my_libraryLib PUBLIC cxx_std_20)
```
__Chức năng__: dùng để cấu hình thư viện `my_library`
 
`add_library`: tạo ra một đối tượng CMake (CMake target) có tên là `my_libraryLib` từ file source là `src/CoreLogic.cpp`

Đối tượng CMake này sử dụng các file header trong thư mục `include` tính từ đường dẫn CMakeList hiện tại đang thao tác `${CMAKE_CURRENT_SOURCE_DIR}`. Vì các hàm định nghĩa(function prototype) trong file header được gọi  bởi chương trình `main.c` trong thư mục app, do đó cần cấu hình lan truyền header (propagation) ở chế độ PUBLIC để trong `main.c` có thể thấy được các hàm định nghĩa trong `CoreLogic.h`

Đối tượng CMake `my_libraryLib` được biên dịch với ngôn ngữ C++ 20

### CMakeLists.txt ở thư mục app

#### Nội dung 
```cmake
cmake_minimum_required(VERSION 3.16)

add_executable(FinalGame src/main.cpp)
target_compile_features(FinalGame PUBLIC cxx_std_20)
target_link_libraries(FinalGame my_libraryLib)
```
__Chức năng__: dùng để cấu hình ứng dụng `app` 

`add_executable`: tạo ra một đối tượng CMake (CMake target) có tên là `FinalGame` từ file source là `src/main.cpp`

Đối tượng CMake `FinalGame` được biên dịch với ngôn ngữ C++ 20

`target_link_libraries`: Sau khi tạo ra đối tượng CMake là `FinalGame` thì `FinalGame` được liên kết thư viện `my_libraryLib`.

## Nội dung của các file source code và header
### CoreLogic.h
```C
#pragma once
#include <string>

std::string get_greeting();
```
### CoreLogic.cpp
```C
#include "CoreLogic.h"

std::string get_greeting() {
  return "Hello from the Greeter library!";
}
```
### main.cpp
```C
#include <iostream>
#include "CoreLogic.h"

int main() {
  std::cout << get_greeting();
  return 0;
}
```
## 3. Quy trình build và biên dịch
### Tạo thư mục build
```powershell
mkdir build && cd build
```
### Cấu hình và Khởi tạo file build
```powershell
cmake -G "MinGW Makefiles" ..
```
Kết quả:
```powelshell
cmake -G "MinGW Makefiles" ..
-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/msys64/ucrt64/bin/cc.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/msys64/ucrt64/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (6.8s)
-- Generating done (0.0s)
-- Build files have been written to: <path/to/project>/Project1/build
```
### Build & Compilation
```powershell
mingw32-make 
```
Kết quả:
```powershell
mingw32-make 
[ 25%] Building CXX object my_library/CMakeFiles/my_libraryLib.dir/src/CoreLogic.cpp.obj
[ 50%] Linking CXX static library libmy_libraryLib.a
[ 50%] Built target my_libraryLib
[ 75%] Building CXX object app/CMakeFiles/FinalGame.dir/src/main.cpp.obj
[100%] Linking CXX executable FinalGame.exe
[100%] Built target FinalGame
```
### Chạy chương trình
```powershell
cd app
.\FinalGame.exe
```
### Kết quả đạt được
```
Hello from the Greeter library!
```
