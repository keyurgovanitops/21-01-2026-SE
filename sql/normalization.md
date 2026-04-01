# Database Normalization (1NF, 2NF, 3NF)

## What is Normalization?

Normalization is a process used in database design to organize data in a structured way.

The goal is simple:

* reduce duplicate data
* avoid data inconsistency
* make updates, inserts, and deletes safe and predictable

These rules are called **Normal Forms (NF)**.

When someone says:
“This table is in 3NF”

It means:
“This table follows normalization rules up to Third Normal Form.”

---

## Why Normalization is Important

If a database is not normalized:

* Same data is repeated in many rows
* Updating data requires changing multiple places
* Missing one update leads to incorrect data
* Inserting new data may require unrelated data
* Deleting data may remove important information unintentionally

These are called:

* Update anomaly
* Insert anomaly
* Delete anomaly

---

## First Normal Form (1NF)

Rule:

* Each column must contain a single value (atomic value)
* No multiple values in one cell

Example (Not in 1NF):

| student_id | name  | skills        |
| ---------- | ----- | ------------- |
| 1          | Karan | HTML, CSS, JS |

Problem:

* "skills" contains multiple values in one cell

Example (In 1NF):

| student_id | name  | skill |
| ---------- | ----- | ----- |
| 1          | Karan | HTML  |
| 1          | Karan | CSS   |
| 1          | Karan | JS    |

Understanding:

* Each cell must store only one value

---

## Second Normal Form (2NF)

Rule:

* Table must already be in 1NF
* All non-key columns must depend on the full primary key

This applies when the primary key is made of multiple columns (composite key)

Example (Not in 2NF):

| student_id | course_id | student_name | course_name |
| ---------- | --------- | ------------ | ----------- |
| 1          | 101       | Karan        | React       |

Primary Key: (student_id, course_id)

Problems:

* student_name depends only on student_id
* course_name depends only on course_id

They do not depend on the full key

Example (In 2NF):

Students Table:

| student_id | student_name |
| ---------- | ------------ |
| 1          | Karan        |

Courses Table:

| course_id | course_name |
| --------- | ----------- |
| 101       | React       |

Enrollments Table:

| student_id | course_id |
| ---------- | --------- |
| 1          | 101       |

Understanding:

* Every column must depend on the complete primary key

---

## Third Normal Form (3NF)

Rule:

* Table must already be in 2NF
* Non-key columns must not depend on other non-key columns

Example (Not in 3NF):

| student_id | department_id | department_name |
| ---------- | ------------- | --------------- |
| 1          | 10            | IT              |

Problems:

* department_name depends on department_id
* department_id depends on student_id

This creates indirect (transitive) dependency

Example (In 3NF):

Students Table:

| student_id | department_id |
| ---------- | ------------- |
| 1          | 10            |

Departments Table:

| department_id | department_name |
| ------------- | --------------- |
| 10            | IT              |

Understanding:

* Columns should depend only on the primary key, not on other columns

---

## How It Is Used in Practice

In real-world development:

* Developers do not explicitly say they are applying 1NF, 2NF, or 3NF step by step
* Instead, they design tables logically
* Proper design naturally follows normalization rules

Common usage:

* “This database is designed up to 3NF”

---

## Summary

1NF:

* Single value per cell

2NF:

* Full dependency on primary key

3NF:

* No dependency between non-key columns

---

## Practical Note

* 3NF is sufficient for most applications
* Higher normal forms exist but are rarely required in typical systems
* Focus on understanding structure, not memorizing definitions
