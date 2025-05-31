USE music_store_db;

INSERT INTO music_items (id, category, type, name, artist, price, quantity) VALUES
(1, 'CD', 'Pop', '1989', 'Taylor Swift', 15.99, 20),
(2, 'CD', 'Rock', 'Hybrid Theory', 'Linkin Park', 12.50, 15),
(3, 'Vinyl', 'Jazz', 'Kind of Blue', 'Miles Davis', 25.00, 10),
(4, 'Digital', 'EDM', 'Levels', 'Avicii', 1.29, 0),
(5, 'Digital', 'Pop', 'Shape of You', 'Ed Sheeran', 1.29, 5);

INSERT INTO customers (id, name, type, points) VALUES
(1, 'Nguyễn Văn Tuấn', 'VIP', 120),
(2, 'Trần Thị Xuân', 'Regular', 30),
(3, 'Bùi Thanh Tú', 'Regular', 30);

INSERT INTO users (username, password, salt, role, customer_id) VALUES
('admin', 'admin','', 'Admin', 1),
('user1', 'userpass','', 'User', 2),
('user2', 'userpass', '', 'User', 3);

INSERT INTO orders (id, customer_id, order_date) VALUES 
(1, 1, '2025-05-05 14:30:00'),
(2, 1, '2025-05-06 15:00:00'),
(3, 3, '2025-05-07 09:15:00');

INSERT INTO order_details (order_id, music_item_id, quantity, price) VALUES
(1, 1, 1, 15.99),
(1, 4, 1, 12.50),
(2, 3, 2, 10.50),
(3, 2, 4, 15.10);