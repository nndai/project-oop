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

-- Bảng: users (người dùng hệ thống: Admin hoặc User)
CREATE TABLE users (
    username VARCHAR(50) PRIMARY KEY,
    password VARCHAR(255) NOT NULL,
    salt VARCHAR(32) NOT NULL,
    role ENUM('Admin', 'User') DEFAULT 'User'
);

-- Bảng: customers (khách hàng mua hàng – có thể có tài khoản hoặc không)
CREATE TABLE customers (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    type ENUM('Regular', 'VIP') DEFAULT 'Regular',
    points INT DEFAULT 0,
    username VARCHAR(50) DEFAULT NULL, -- nếu khách có tài khoản
    FOREIGN KEY (username) REFERENCES users(username)
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

INSERT INTO music_items (id, category, type, name, artist, price, quantity) VALUES
(1, 'CD', 'Pop', '1989', 'Taylor Swift', 15.99, 20),
(2, 'CD', 'Rock', 'Hybrid Theory', 'Linkin Park', 12.50, 15),
(3, 'Vinyl', 'Jazz', 'Kind of Blue', 'Miles Davis', 25.00, 10),
(4, 'Digital', 'EDM', 'Levels', 'Avicii', 1.29, 0),
(5, 'Digital', 'Pop', 'Shape of You', 'Ed Sheeran', 1.29, 5);

INSERT INTO users (username, password, salt, role) VALUES
('admin', 'admin',' ', 'Admin'),
('user1', 'userpass',' ', 'User'),
('user2', 'userpass', ' ', 'User');

-- Khách có tài khoản
INSERT INTO customers (id, name, type, points, username) VALUES
(1, 'Nguyen Văn A', 'VIP', 120, 'user1'),
(2, 'Tran Thi B', 'Regular', 30, 'user2');

-- Khách vãng lai (không có username)
INSERT INTO customers (id, name, type, points) VALUES
(3, 'Nguyen Ngoc Dai', 'Regular', 0),
(4, 'Nguyen Ha Dat', 'Regular', 0);


INSERT INTO orders (id, customer_id, order_date) VALUES 
(1, 1, '2025-05-05 14:30:00'),
(2, 1, '2025-05-06 15:00:00'),
(3, 3, '2025-05-07 09:15:00');

INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES
(1, 1, 1, 15.99),
(1, 4, 1, 12.50),
(2, 3, 2, 10.50),
(3, 2, 4, 15.10);