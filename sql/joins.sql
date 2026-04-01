CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    order_date DATE,
    amount DECIMAL(10,2),
    customer_id INT,
    FOREIGN KEY (customer_id)  REFERENCES customers(customer_id)
);

INSERT INTO customers VALUES
(1, 'Alice', 'alice@example.com'),
(2, 'Bob', 'bob@example.com'),
(3, 'Charlie', 'charlie@example.com');

INSERT INTO orders VALUES	
(101, '2025-01-01', 250.00, 1),
(102, '2025-01-05', 150.00, 1),
(103, '2025-01-10', 300.00, 2);

select * from customers;
select * from orders;

use something;
show tables;

SELECT customers.name, orders.order_id, orders.amount
FROM customers
INNER JOIN orders
ON customers.customer_id = orders.customer_id;

SELECT customers.name, orders.order_id, orders.amount
FROM customers
LEFT JOIN orders
ON customers.customer_id = orders.customer_id;

SELECT customers.name, orders.order_id, orders.amount
FROM customers
RIGHT JOIN orders
ON customers.customer_id = orders.customer_id;

SELECT customers.name, orders.order_id, orders.amount
FROM customers
FULL OUTER JOIN orders
ON customers.customer_id = orders.customer_id;


SELECT name FROM customers
UNION
SELECT name FROM orders;
