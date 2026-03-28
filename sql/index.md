# MySQL Index Demo Guide

This guide is designed to demonstrate how an index improves query performance in MySQL using a large table.

## Goal

We will:

* create a database and a large table
* insert 100000 rows of sample data
* run a query without an index and observe performance
* create a normal index
* run the same query again and compare the difference

## Step 1: Create the Database and Table

Run the following SQL exactly as given:

```sql
DROP DATABASE IF EXISTS index_demo;
CREATE DATABASE index_demo;
USE index_demo;

DROP TABLE IF EXISTS nums;
CREATE TABLE nums (
    n TINYINT NOT NULL
);

INSERT INTO nums (n) VALUES
(0),(1),(2),(3),(4),(5),(6),(7),(8),(9);

DROP TABLE IF EXISTS employees_big;
CREATE TABLE employees_big (
    id INT PRIMARY KEY AUTO_INCREMENT,
    employee_code VARCHAR(20) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    gender ENUM('Male', 'Female') NOT NULL,
    department VARCHAR(50) NOT NULL,
    job_title VARCHAR(100) NOT NULL,
    city VARCHAR(50) NOT NULL,
    state_name VARCHAR(50) NOT NULL,
    country_name VARCHAR(50) NOT NULL,
    salary DECIMAL(10,2) NOT NULL,
    experience_years INT NOT NULL,
    joining_date DATE NOT NULL,
    email VARCHAR(120) NOT NULL,
    phone VARCHAR(20) NOT NULL,
    performance_rating INT NOT NULL,
    is_active TINYINT(1) NOT NULL,
    notes VARCHAR(255) NULL
);

INSERT INTO employees_big (
    employee_code,
    first_name,
    last_name,
    gender,
    department,
    job_title,
    city,
    state_name,
    country_name,
    salary,
    experience_years,
    joining_date,
    email,
    phone,
    performance_rating,
    is_active,
    notes
)
SELECT
    CONCAT('EMP', LPAD(serial_no, 6, '0')) AS employee_code,
    ELT((serial_no % 10) + 1, 'Aarav', 'Vivaan', 'Aditya', 'Vihaan', 'Arjun', 'Sai', 'Reyansh', 'Krish', 'Ishaan', 'Kabir') AS first_name,
    ELT((serial_no % 10) + 1, 'Sharma', 'Patel', 'Mehta', 'Verma', 'Yadav', 'Singh', 'Joshi', 'Gupta', 'Nair', 'Reddy') AS last_name,
    ELT((serial_no % 2) + 1, 'Male', 'Female') AS gender,
    ELT((serial_no % 8) + 1, 'HR', 'IT', 'Finance', 'Sales', 'Marketing', 'Support', 'Admin', 'Operations') AS department,
    ELT((serial_no % 8) + 1, 'Executive', 'Developer', 'Analyst', 'Manager', 'Coordinator', 'Engineer', 'Consultant', 'Associate') AS job_title,
    ELT((serial_no % 10) + 1, 'Ahmedabad', 'Mumbai', 'Delhi', 'Pune', 'Bengaluru', 'Surat', 'Jaipur', 'Hyderabad', 'Chennai', 'Kolkata') AS city,
    ELT((serial_no % 10) + 1, 'Gujarat', 'Maharashtra', 'Delhi', 'Maharashtra', 'Karnataka', 'Gujarat', 'Rajasthan', 'Telangana', 'Tamil Nadu', 'West Bengal') AS state_name,
    'India' AS country_name,
    20000 + (serial_no % 180000) AS salary,
    (serial_no % 16) AS experience_years,
    DATE_ADD('2015-01-01', INTERVAL (serial_no % 3650) DAY) AS joining_date,
    CONCAT('employee', serial_no, '@company.com') AS email,
    CONCAT('9', LPAD(serial_no % 1000000000, 9, '0')) AS phone,
    (serial_no % 5) + 1 AS performance_rating,
    (serial_no % 2) AS is_active,
    CONCAT('Record number ', serial_no) AS notes
FROM (
    SELECT
        a.n
        + b.n * 10
        + c.n * 100
        + d.n * 1000
        + e.n * 10000
        + 1 AS serial_no
    FROM nums a
    CROSS JOIN nums b
    CROSS JOIN nums c
    CROSS JOIN nums d
    CROSS JOIN nums e
) AS x
WHERE serial_no <= 100000;
```

## Step 2: Verify the Number of Rows

Run this query to confirm that the table contains 100000 rows:

```sql
SELECT COUNT(*) AS total_rows
FROM employees_big;
```

Expected result:

```text
total_rows
100000
```

## Step 3: Run a Query Before Creating the Index

First test the query without an index on the `email` column.

### Option A: Use `EXPLAIN ANALYZE`

Use this if your MySQL version supports it:

```sql
EXPLAIN ANALYZE
SELECT *
FROM employees_big
WHERE email = 'employee99999@company.com';
```

This shows the execution plan and actual timing.

### Option B: Use Profiling

If `EXPLAIN ANALYZE` is not supported, use profiling:

```sql
SET profiling = 1;

SELECT *
FROM employees_big
WHERE email = 'employee99999@company.com';

SHOW PROFILES;
```

This shows how long the query took.

## Step 4: Create a Normal Index

Now create a normal index on the `email` column:

```sql
CREATE INDEX idx_email ON employees_big(email);
```

## Step 5: Run the Same Query Again After Creating the Index

Run the exact same query again.

### Option A: With `EXPLAIN ANALYZE`

```sql
EXPLAIN ANALYZE
SELECT *
FROM employees_big
WHERE email = 'employee99999@company.com';
```

### Option B: With Profiling

```sql
SET profiling = 1;

SELECT *
FROM employees_big
WHERE email = 'employee99999@company.com';

SHOW PROFILES;
```

Now compare the result with the first run.

## Step 6: A Cleaner Performance Test

For a cleaner demonstration, use fewer columns in the query:

```sql
EXPLAIN ANALYZE
SELECT id, email
FROM employees_big
WHERE email = 'employee99999@company.com';
```

This makes the demo easier to understand because less data is returned.

## What to Observe

Before the index:

* MySQL may scan many rows to find the matching email.
* Query time is usually higher.

After the index:

* MySQL can directly locate the row much faster.
* Query time usually becomes lower.

## Why `email` Was Chosen

The `email` column is a good column for indexing in this demo because each value is different for each row.

Example values:

* `employee1@company.com`
* `employee50000@company.com`
* `employee99999@company.com`

Since the values are highly selective, the index becomes very useful.

## Why Columns Like `gender` Are Bad for This Demo

Columns such as `gender` have very few distinct values.

Example:

* `Male`
* `Female`

In such cases, an index may not provide much benefit because many rows still match the same value.

## Important Notes

* An index improves read performance for many queries.
* An index also takes storage space.
* Insert, update, and delete operations can become slightly slower because MySQL has to maintain the index.
* Indexes should be created on columns that are searched, filtered, sorted, or joined frequently.

## Optional: Check Existing Indexes

You can see the indexes on the table using:

```sql
SHOW INDEX FROM employees_big;
```

## Optional: Remove the Index

You can remove the index using:

```sql
DROP INDEX idx_email ON employees_big;
```

## Final Summary

This demo shows a simple and practical use of indexing in MySQL:

1. create a large table
2. run a query without an index
3. observe the timing
4. create an index on the searched column
5. run the same query again
6. compare the improvement

This is one of the easiest ways to demonstrate what an index does in real life.
