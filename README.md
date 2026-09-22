# 🚀 Chuỗi Bài Học C++ & CMake từ Cơ Bản đến Thực Hành

Chào mừng bạn đến với repository lưu trữ bài học và dự án thực hành CMake. Repository này được tổ chức theo cấu trúc đa dự án (Monorepo), bao gồm các hướng dẫn lý thuyết và chương trình test mẫu.

---

## 📂 Danh Sách Bài Học & Dự Án

| Thư mục | Tên Project | Mục Đích / Nội Dung | Hướng Dẫn |
| :--- | :--- | :--- | :---: |
| [`/CMake_Tutorial_Subdirectory`](./CMake_Tutorial_Subdirectory/) | **CMake Tutorial** | Hướng dẫn cấu hình CMake dạng `add_subdirectory` chia tách App và Library. | [Xem chi tiết](./CMake_Tutorial_Subdirectory/README.md) |
| [`/Simple_test_program`](./Simple_test_program/) | **Simple Test App** | Chương trình mẫu dùng để test build song song, verify môi trường. | [Xem chi tiết](./Simple_test_program/README.md) |

---

## 🛠️ Yêu Cầu Môi Trường (Prerequisites)

Để build và chạy các dự án trong repo này, bạn cần chuẩn bị:
- **C++ Compiler:** GCC / MinGW (hỗ trợ C++17 trở lên)
- **Build System:** CMake `>= 3.16`

---

## ⚡ Hướng Dẫn Build Nhanh (Quick Start)

1. **Clone repository về máy:**
   ```bash
   git clone <URL_REPO_CUA_BAN>
   cd <TEN_THU_MUC_REPO>