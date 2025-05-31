# Music Store Management System


## Thành viên nhóm
- Nguyễn Ngọc Đại - 23120226
- Nguyễn Hà Đạt - 23120229

## Phân Công & Mô Tả Công Việc
### Thành viên 1: Nguyễn Ngọc Đại (Nhóm trưởng)
- Thiết kế lớp `MusicItem`, `MusicStore`, `AuthManager`, `Database`, `ExportInvoice`
- Xây dựng các class hành động (`...Action`)
- Thiết kế Database
- Giao diện console (`TableUI`)

### Thành viên 2: Nguyễn Hà Đạt
- Thiết kế lớp `Customer`, `CustomerManager`, `User`, `Order`, `OrderManager`
- Thiết kế hệ thống menu động (`MenuManager`, `MenuActionFactory`)
- Thêm tính năng mã hóa mật khẩu người dùng (`Hasher`)
- Tạo class diagram UML cho các lớp trong hệ thống
- Tạo tài liệu bằng Doxygen
- Tạo test tự động cho các class
- Kiểm thử thủ công toàn bộ chương trình
- Viết README.md

## Tỉ lệ đóng góp(100%)
- Nguyễn Ngọc Đại : 50%
- Nguyễn Hà Đạt : 50%

## Tỉ lệ điểm
Chia đều điểm cho các thành viên

## Cách Thức Đánh Giá
### 1. Teamwork
- Nhóm có 2 thành viên, phân công rõ ràng.
- Sử dụng git riêng của từng người, chia thành nhiều nhánh theo `feature branch workflow`
- [Insights github](https://drive.google.com/file/d/1ygYbFPedFhnDDZEm23T7JO8O0Ii5JFWP/view?usp=sharing)

### 2. UI/UX
- Các chức năng thêm và cải tiến:
  - Chức năng tạo tài khoản và đăng nhập
  - Chức năng phân quyền người dùng(admin, user)
  - Xem các đơn hàng đã mua, bán
  - Chức năng quản lí khách hàng
  - In hóa đơn
- Giao diện console, sử dụng `TableUI` để hiển thị dữ liệu dạng bảng trực quan

### 3. Kiến trúc phần mềm + Design Pattern
#### SOLID:
  - Single Responsibility Principle: Mỗi class chỉ đảm nhận một nhiệm vụ: 
    - `MusicStore`: Quản lý mặt hàng âm nhạc.
    - `CustomerManager`: Quản lý khách hàng.
    - `OrderManager`: Quản lý đơn hàng.
    - `AuthManager`: Xác thực và đăng ký người dùng.
    - `Hasher`: Mã hóa, xác thực mật khẩu.
    - `TableUI`: Hiển thị dữ liệu dạng bảng.
    - `ExportInvoice`: Xuất hóa đơn.
    - Các class `...Action`: Thực hiện từng hành động cụ thể trong menu.

  - Open/Closed Principle:
    - Các hành động như `AddItemAction`, `EditItemAction` kế thừa từ `IMenuAction`, có thể thêm hành động mới mà không ảnh hưởng đến hành động cũ.
    - `MenuActionFactory` giúp ánh xạ lựa chọn menu sang hành động, dễ mở rộng menu mà không thay đổi logic xử lý.
  
  - Liskov Substitution Principle: Các class kế thừa `IMenuAction` đều có thể sử dụng ở bất kỳ đâu mà interface này được yêu cầu.
  
  - Interface Segregation Principle: Các interface được chia nhỏ theo chức năng, ví dụ `IMenuAction` chỉ chứa các phương thức cần thiết cho hành động menu.
  
  - Dependency Inversion Principle: 
    - Các đối tượng như `MusicStore`, `CustomerManager`, `OrderManager`, `AuthManager`, `MenuManager` đều không tự tạo kết nối database mà nhận một con trỏ `Database* db` từ bên ngoài (inject qua constructor).
    - `MenuManager` nhận các dependency là `AuthManager*`, `MusicStore*`, `CustomerManager*`, `OrderManager*` qua constructor, thay vì tự tạo mới bên trong.

#### Design Patterns:
- **Factory Pattern**: `MenuActionFactory` tạo ra các hành động (`IMenuAction`) dựa trên lựa chọn menu của người dùng mà không cần biết cụ thể class nào sẽ được khởi tạo.

- **Singleton Pattern**: `Database` được thiết kế theo singleton để đảm bảo chỉ có một kết nối duy nhất đến cơ sở dữ liệu trong suốt vòng đời ứng dụng.

- **Cấu trúc chia theo MVC**:
  - Model: `Customer`, `Order`, `MusicItem`
  - View: `TableUI`
  - Controller: `Action` classes như `AddItemAction`, `DisplayAllItemsAction`,...

### 4. Đảm bảo chất lượng
- Theo chuẩn coding convention:
  - Quy ước đặt tên: 
      - hàm: camelCase
      - biến: snake_case
      - class: PascalCase
      - hằng số: UPPER_SNAKE_CASE
  - Tránh magic constants mà sử dụng tên
  - Đưa hằng số ra trước khi so sánh
  - Ưu tiên bắt lỗi trước và return sớm
  - Không sử dụng using namespace ở đầu header file
  - Khi so sánh các điều kiện phức tạp, sử dụng dấu ngoặc
  - Tránh đặt tên hàm có kiểu dữ liệu
  - Sử dụng nullptr thay cho NULL
  - Nếu code dài, hãy sử dụng cặp ngoặc cho dù đoạn lệnh chỉ có 1 dòng lệnh
  - Không cần thêm so sánh bằng dư thừa con trỏ

- Tạo test tự động cho các class và test thủ công toàn bộ chương trình

### 5. Tài liệu mô tả kiến trúc phần mềm và các module
- README.md mô tả tổng thể dự án, module, design pattern.
- Sơ đồ class diagram UML mô tả mối quan hệ giữa các thành phần trong hệ thống.
- Tạo tài liệu bằng Doxygen cho các class và phương thức.

### 6. Chủ đề nâng cao
- Xây dựng hệ thống phân quyền người dùng (`AuthManager`).
- Sử dụng MySQL để quản lý database.
- Sử dụng `Hasher` dùng thuật toán SHA-256 để mã hóa mật khẩu người dùng và xác thực đăng nhập.


## Hướng dẫn cài đặt và chạy chương trình
### 1. Tải và Cài Đặt MySQL và Kết Nối Bằng C++
- Tải và cài đặt [**MySQL Server**](https://dev.mysql.com/downloads/mysql/)
- Cài đặt [**MySQL Workbench**](https://dev.mysql.com/downloads/workbench/)
- Cài đặt [**g++**](https://winlibs.com/) và thêm đường dẫn `bin` của MinGW vào biến môi trường `PATH` (ví dụ: `C:\mingw64\bin`)

> **Lưu ý:** Ghi nhớ đường dẫn cài đặt MySQL Server để cấu hình build chương trình, ví dụ: `C:\Program Files\MySQL\MySQL Server 9.3\`

### 2. Cấu Hình MySQL Server và Workbench
#### Khởi tạo MySQL Server:
- Thiết lập cổng mặc định: `3306`
- Chế độ xác thực: chọn `Use Legacy Authentication` (để dùng được với một số thư viện C++)
- Tạo user `root` và nhập mật khẩu, ví dụ: `123456`
- Sau khi cài, MySQL Server sẽ tự chạy dưới dạng **Windows Service**

#### Kết nối với MySQL Workbench:
- Mở MySQL Workbench
- Tạo `New Connection`:
  - **Hostname**: `localhost`
  - **Port**: `3306`
  - **Username**: `root`
  - **Password**: nhập mật khẩu đã đặt

### 3. Tạo Database và Chạy File SQL
- Mở MySQL Workbench
- Chạy lần lượt các file `music_store_db.sql` và `data_music_store_db.sql`

### 4. Cấu hình file .env và chạy chương trình được biên dịch sẵn
- Đảm bảo file `.env` chứa thông tin kết nối:
  ```
  DB_HOST=localhost
  DB_USER=root
  DB_PASS= <your_password>
  DB_NAME=music_store
  ```
- Chạy chương trình đã biên dịch sẵn:
  - Mở terminal tại thư mục project
  - Chạy lệnh: `out\program.exe`

> **Lưu ý:** Nếu gặp lỗi liên quan đến các file có đuôi `.dll`, hãy vào thư mục cài đặt MySQL (ví dụ: `C:\Program Files\MySQL\MySQL Server 9.3\lib`) và copy các file `.dll` cần thiết vào thư mục chứa file thực thi của chương trình.
> Nếu chương trình bị dừng và không báo lỗi gì, hãy thử chạy lại chương trình bằng cách ấn đúp chuột vào file `out\program.exe` trong thư mục `out` để hiển thị lỗi.

### 5. Biên dịch chương trình từ mã nguồn
- Dùng Visual Studio Code:
  - Chỉnh sửa hai đường dẫn thư viện trong file `c_cpp_properties.json` và `tasks.json` theo đường dẫn cài đặt MySQL của bạn, ví dụ:
    ```json
    "C:/Program Files/MySQL/MySQL Server 9.3/include",
    "C:/Program Files/MySQL/MySQL Server 9.3/lib"
    ```
  - Build chương trình bằng tông hợp phím `Ctrl + Shift + B`

- Dùng cmd:
  - Mở cmd và chuyển đến thư mục chứa mã nguồn
  - Chạy lệnh biên dịch (thay đổi đường dẫn theo cài đặt MySQL của bạn):
    ```bash
    g++ -std=c++23 src\*.cpp -o out\program.exe "-IC:/Program Files/MySQL/MySQL Server 9.3/include" "-LC:/Program Files/MySQL/MySQL Server 9.3/lib" -lmysql
    ```
- Chạy chương trình như đã hướng dẫn ở bước 4.

## [Video demo chương trình](https://youtu.be/lKffoqGTMdk)