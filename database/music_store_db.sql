CREATE DATABASE music_store_db;
USE music_store_db;

-- Bảng: music_items
CREATE TABLE music_items (
    id INT PRIMARY KEY AUTO_INCREMENT,
    category VARCHAR(100) NOT NULL,
    type VARCHAR(100) NOT NULL,
    name VARCHAR(255) NOT NULL,
    artist VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    quantity INT NOT NULL
);


-- Bảng: customers (khách hàng mua hàng – có thể có tài khoản hoặc không)
CREATE TABLE customers (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    type ENUM('Regular', 'VIP') DEFAULT 'Regular',
    points INT DEFAULT 0
);

-- Bảng: users (người dùng hệ thống: Admin hoặc User)
CREATE TABLE users (
    username VARCHAR(50) PRIMARY KEY,
    password VARCHAR(255) NOT NULL,
    salt VARCHAR(32) NOT NULL,
    role ENUM('Admin', 'User') DEFAULT 'User',
    customer_id INT NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

-- Bảng: orders (đơn hàng – gắn người đặt hàng và khách mua hàng)
CREATE TABLE orders (
    id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

-- Bảng: order_details (chi tiết đơn hàng)
CREATE TABLE order_details (
    order_id INT NOT NULL,
    music_item_id INT NOT NULL,
    quantity INT NOT NULL,
    price DECIMAL(10, 2) NOT NULL, -- giá tại thời điểm mua
    PRIMARY KEY (order_id, music_item_id),
    FOREIGN KEY (order_id) REFERENCES orders(id),
    FOREIGN KEY (music_item_id) REFERENCES music_items(id)
);

DELIMITER $$

CREATE PROCEDURE CreateUserAccount(
    IN p_username VARCHAR(50),
    IN p_password VARCHAR(255),
    IN p_salt VARCHAR(32),
    IN p_customer_name VARCHAR(255)
)
BEGIN
    DECLARE new_customer_id INT;

    -- Xử lý lỗi SQL: rollback khi có lỗi
    DECLARE EXIT HANDLER FOR SQLEXCEPTION 
    BEGIN
        ROLLBACK;
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Error occurred. Operation aborted.';
    END;

    -- Bắt đầu transaction
    START TRANSACTION;

    -- 1. Kiểm tra username đã tồn tại chưa
    IF EXISTS (SELECT 1 FROM users WHERE username = p_username) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Username already exists.';
    END IF;

    -- 2. Tạo khách hàng mới
    INSERT INTO customers(name) VALUES(p_customer_name);
    SET new_customer_id = LAST_INSERT_ID();

    -- 3. Tạo user với customer_id vừa tạo
    INSERT INTO users(username, password, salt, customer_id)
    VALUES(p_username, p_password, p_salt, new_customer_id);

    -- Hoàn tất
    COMMIT;
END$$

DELIMITER ;
