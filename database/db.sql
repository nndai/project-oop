-- Create database
CREATE DATABASE music_store_db;
USE music_store_db;

-- Table: music_items
CREATE TABLE music_items (
    id INT PRIMARY KEY AUTO_INCREMENT,
    category VARCHAR(100) NOT NULL,
    type VARCHAR(100) NOT NULL,
    name VARCHAR(255) NOT NULL,
    artist VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    quantity INT NOT NULL
);

-- Table: customers
CREATE TABLE customers (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    type ENUM('Regular', 'VIP') DEFAULT 'Regular',
    points INT DEFAULT 0
);

-- Table: orders
CREATE TABLE orders (
    id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT NOT NULL,
    order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    total_price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

-- Table: order_details
CREATE TABLE order_details (
    id INT PRIMARY KEY AUTO_INCREMENT,
    order_id INT NOT NULL,
    music_item_id INT NOT NULL,
    quantity INT NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(id),
    FOREIGN KEY (music_item_id) REFERENCES music_items(id)
);

-- Table: users
CREATE TABLE users (
    username VARCHAR(50) PRIMARY KEY,
    password VARCHAR(255) NOT NULL,
    role ENUM('Admin', 'User') DEFAULT 'User'
);

-- Insert sample data into music_items
INSERT INTO music_items (category, type, name, artist, price, quantity) VALUES
('Pop', 'CD', 'Thriller', 'Michael Jackson', 15.99, 50),
('Rock', 'Vinyl', 'Back in Black', 'AC/DC', 20.99, 30),
('Jazz', 'CD', 'Kind of Blue', 'Miles Davis', 12.99, 40),
('Classical', 'Vinyl', 'The Four Seasons', 'Vivaldi', 25.99, 20);

-- Insert sample data into customers
INSERT INTO customers (name, type, points) VALUES
('John Doe', 'Regular', 10),
('Jane Smith', 'VIP', 200),
('Alice Johnson', 'Regular', 50),
('Bob Brown', 'VIP', 300);

-- Insert sample data into users
INSERT INTO users (username, password, role) VALUES
('admin', 'admin123', 'Admin'),
('user1', 'user123', 'User'),
('user2', 'user456', 'User');

-- Insert sample data into orders
INSERT INTO orders (customer_id, total_price) VALUES
(1, 31.98),
(2, 41.98);

-- Insert sample data into order_details
INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES
(1, 1, 2, 31.98),
(2, 2, 1, 20.99),
(2, 3, 1, 20.99);