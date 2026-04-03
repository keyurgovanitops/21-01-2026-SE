## 2. What we are learning here

Till now you were only asking database for data.
Now you will make database DO work.

This includes:

* Storing values
* Making decisions
* Running loops
* Writing reusable logic

---

## 3. Setup (Do this first and run it)

Copy and run this:

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    salary INT
);

INSERT INTO employees (name, salary) VALUES
('Amit', 40000),
('Riya', 60000),
('John', 55000);
```

Now you have data to work with.

---

## 4. First Concept: Variables

Database can store temporary values.

Run this:

```sql
DELIMITER //

CREATE PROCEDURE test_variables()
BEGIN
    DECLARE v_name VARCHAR(50);
    DECLARE v_salary INT;

    SET v_name = 'Karan';
    SET v_salary = 50000;

    SELECT v_name, v_salary;
END //

DELIMITER ;
```

Then run:

```sql
CALL test_variables();
```

You will see values printed.

Concept:

* Variables store temporary data
* They exist only inside procedure

---

## 5. Getting Data from Table (SELECT INTO)

Now fetch real data.

```sql
DELIMITER //

CREATE PROCEDURE get_data()
BEGIN
    DECLARE v_name VARCHAR(50);
    DECLARE v_salary INT;

    SELECT name, salary INTO v_name, v_salary
    FROM employees
    WHERE id = 1;

    SELECT v_name, v_salary;
END //

DELIMITER ;
```

Run:

```sql
CALL get_data();
```

Concept:

* SELECT INTO stores query result into variables
* Must return only one row

---

## 6. Decision Making (IF)

Now add logic.

```sql
DELIMITER //

CREATE PROCEDURE check_salary()
BEGIN
    DECLARE v_salary INT;

    SELECT salary INTO v_salary FROM employees WHERE id = 2;

    IF v_salary > 50000 THEN
        SELECT 'High Salary';
    ELSE
        SELECT 'Low Salary';
    END IF;
END //

DELIMITER ;
```

Run:

```sql
CALL check_salary();
```

Concept:

* Database can make decisions

---

## 7. Loops (Repeat work)

```sql
DELIMITER //

CREATE PROCEDURE loop_demo()
BEGIN
    DECLARE i INT DEFAULT 1;

    WHILE i <= 5 DO
        SELECT i;
        SET i = i + 1;
    END WHILE;
END //

DELIMITER ;
```

Run:

```sql
CALL loop_demo();
```

Concept:

* Loop repeats work

---

## 8. Real Use Case: Process Multiple Rows (Cursor)

Now real world.

```sql
DELIMITER //

CREATE PROCEDURE print_all_names()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_name VARCHAR(50);

    DECLARE cur CURSOR FOR SELECT name FROM employees;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO v_name;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT v_name;
    END LOOP;

    CLOSE cur;
END //

DELIMITER ;
```

Run:

```sql
CALL print_all_names();
```

Concept:

* Cursor lets you go row by row
* Used when working with large data

---

## 9. Real Use Case: Salary Update Logic

```sql
DELIMITER //

CREATE PROCEDURE increase_salary()
BEGIN
    UPDATE employees
    SET salary = salary + 5000
    WHERE salary < 60000;
END //

DELIMITER ;
```

Run:

```sql
CALL increase_salary();
SELECT * FROM employees;
```

Concept:

* Automate business rules inside DB

---

## 10. Functions (Return Value)

```sql
DELIMITER //

CREATE FUNCTION get_bonus(salary INT)
RETURNS INT
DETERMINISTIC
BEGIN
    RETURN salary * 0.10;
END //

DELIMITER ;
```

Run:

```sql
SELECT name, get_bonus(salary) FROM employees;
```

Concept:

* Function returns value
* Can be used inside queries

---

## 11. Triggers (Automatic Execution)

```sql
CREATE TABLE logs (
    message VARCHAR(100)
);

CREATE TRIGGER log_insert
AFTER INSERT ON employees
FOR EACH ROW
INSERT INTO logs VALUES ('New employee added');
```

Test it:

```sql
INSERT INTO employees (name, salary) VALUES ('NewUser', 45000);
SELECT * FROM logs;
```

Concept:

* Trigger runs automatically

---

## 12. Transactions (Safety)

```sql
START TRANSACTION;

UPDATE employees SET salary = salary - 1000 WHERE id = 1;
UPDATE employees SET salary = salary + 1000 WHERE id = 2;

COMMIT;
```

If something goes wrong:

```sql
ROLLBACK;
```

Concept:

* Ensures safe updates

---

## Final Understanding

Step by step you learned:

* Variables
* Fetching data
* Conditions
* Loops
* Real use cases

Now database is not just storing data.
It is executing logic like a program.
