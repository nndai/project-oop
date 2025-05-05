# Music Store Management System

## Thành viên nhóm

- Nguyễn Ngọc Đại - 23120226 - trưởng nhóm
- Nguyễn Hà Đạt - 23120229

## Phân Công & Mô Tả Công Việc

### Thành viên 1: Nguyễn Ngọc Đại (Nhóm trưởng)

- Xây dựng các hành động: `AddCustomerAction`, `EditCustomerAction`, `RemoveCustomerAction`
- Tính năng phân quyền người dùng: `AuthManager`
- Giao diện console (`TableUI`)
- Thực hiện các chức năng:
  - `AddItemAction`, `EditItemAction`, `RemoveItemAction`
  - `CreateOrderAction`, `ViewOrdersAction`, `SoldItemsAction`
  - `ItemInStockAction`, `FindItemAction`

### Thành viên 2: Nguyễn Hà Đạt

- Thiết kế lớp `Customer`, `CustomerManager`, `User`, `Order`

- Thiết kế hệ thống menu động (`MenuManager`, `MenuActionFactory`)
- Kiểm thử thủ công toàn bộ chương trình

- Viết README.md mô tả công việc

## Tỉ lệ đóng góp (100%)

## D. Cách Thức Đánh Giá - Mô Tả Cụ Thể

### 1. **Teamwork (15%)**

- Nhóm có 2 thành viên, phân công rõ ràng.
- Có sử dụng Git riêng của từng người.
- Mỗi thành viên đảm nhận các module khác nhau:

### 2. **UI/UX (20%)**

- Thiết kế lại hệ thống mẫu theo hướng đối tượng.
- Thêm chức năng như phân quyền, tích điểm, thống kê đơn hàng.
- Giao diện console logic, dễ thao tác.
- Sử dụng `TableUI` để hiển thị dữ liệu dạng bảng trực quan.
- Menu động được quản lý bởi `MenuManager`, dễ mở rộng.

### 3. **Kiến trúc phần mềm + Design Pattern (20%)**

- Thiết kế module rõ ràng.
- Áp dụng **SOLID**
  - S: Mỗi class chỉ đảm nhận một nhiệm vụ.
  - O: Các chức năng như `AddItemAction`, `EditItemAction`,... có thể mở rộng qua kế thừa.
  - D: Giao tiếp thông qua interface/factory.
- Dùng **Factory Pattern** (`MenuActionFactory`) tạo ra các hành động động theo input người dùng.
- Dùng **Singleton Pattern** để đảm bảo `Database` chỉ có một instance duy nhất.
- Cấu trúc chia theo MVC:
  - Model: `Customer`, `Order`, `MusicItem`
  - View: `TableUI`
  - Controller: `Action` classes như `AddItemAction`, `DisplayAllItemsAction`,...

### 4. **Đảm bảo chất lượng (20%)**

- Theo chuẩn coding convention:
  - Tên class PascalCase, tên biến snake_case.
  - Mỗi class trong file riêng (`.h`/`.cpp`).
- Có kiểm thử thủ công đầu vào:
  - Kiểm tra logic thêm, xóa, sửa.
  - Xử lý ngoại lệ khi nhập sai.
- Không rò rỉ bộ nhớ:
  - Dọn dẹp con trỏ động.
  - Không có cảnh báo từ trình biên dịch.

### 5. **Tài liệu kiến trúc (10%)**

- README.md mô tả tổng thể dự án, module, design pattern.
- Có sơ đồ class minh họa mối quan hệ giữa các thành phần.
- Mỗi module được chú thích chức năng, cách hoạt động.

### 6. **Chủ đề nâng cao (15%)**

- Xây dựng hệ thống phân quyền người dùng (`AuthManager`).
- dùng MySQL quản lí database

## Công nghệ sử dụng

- Ngôn ngữ: C++
- CSDL: MySQL
- Công cụ: VSCode, Git

## Hướng Dẫn Cài Đặt & Chạy Dự Án

### Bước 1. Yêu Cầu Hệ Thống

- **Cần cài đặt:**
  - [MySQL Community Server](https://dev.mysql.com/downloads/mysql/)
  - [MySQL Workbench](https://dev.mysql.com/downloads/workbench/)

### Bước 2: Tạo CSDL và bảng

1. Mở MySQL Workbench, kết nối với server (`localhost`, user `root`)
2. Tạo database bằng cách chạy file bd.sql trên MySQL Workbench

### 3. Build & Chạy Chương Trình

**Build Solution**:

- Menu Build → Build Solution
- Phím tắt: `Ctrl + Shift + B`

**Chạy file output**

- program.exe
