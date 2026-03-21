# MySQL `ALTER TABLE` — Simplified Beginner Guide

This file is only about **`ALTER TABLE`**.
It does not cover `ALTER DATABASE`, `ALTER VIEW`, or anything else.

The goal here is simple:
this should feel easy to understand for a beginner.

`ALTER TABLE` is used when a table already exists and you want to change something in it.

That “something” can be:

* adding a new column
* removing a column
* changing a column name
* changing a data type
* changing column position
* adding a constraint
* removing a constraint
* renaming the table

So the easiest way to think about it is:

**`CREATE TABLE` builds the table first, `ALTER TABLE` changes it later.**

---

# Basic Syntax

```sql
ALTER TABLE table_name
change_you_want_to_make;
```

Example:

```sql
ALTER TABLE students
ADD COLUMN city VARCHAR(100);
```

---

# 1) Add a New Column

## Add one column

```sql
ALTER TABLE students
ADD COLUMN city VARCHAR(100);
```

## Add multiple columns

```sql
ALTER TABLE students
ADD COLUMN city VARCHAR(100),
ADD COLUMN marks DECIMAL(5,2);
```

## Add column at the beginning

```sql
ALTER TABLE students
ADD COLUMN roll_no INT FIRST;
```

## Add column after a specific column

```sql
ALTER TABLE students
ADD COLUMN email VARCHAR(100) AFTER name;
```

---

# 2) Change Data Type of a Column

Use `MODIFY COLUMN` when the column name stays the same but its definition changes.

```sql
ALTER TABLE students
MODIFY COLUMN name VARCHAR(150);
```

## More examples

```sql
ALTER TABLE students
MODIFY COLUMN marks DECIMAL(6,2);
```

```sql
ALTER TABLE students
MODIFY COLUMN age BIGINT;
```

---

# 3) Change Column Name

## Modern and easy way

```sql
ALTER TABLE students
RENAME COLUMN name TO full_name;
```

## Older common way

```sql
ALTER TABLE students
CHANGE COLUMN name full_name VARCHAR(100);
```

Important thing:
When you use `CHANGE COLUMN`, you must write the full new definition too.
That is why the data type appears again.

---

# 4) Change Both Column Name and Data Type Together

Use `CHANGE COLUMN`.

```sql
ALTER TABLE students
CHANGE COLUMN name full_name VARCHAR(150);
```

Another example:

```sql
ALTER TABLE students
CHANGE COLUMN marks percentage DECIMAL(6,2);
```

---

# 5) Change Position of a Column

This is one of the things beginners often forget.
Yes, MySQL lets you change column position.

## Move column to first position

```sql
ALTER TABLE students
MODIFY COLUMN email VARCHAR(100) FIRST;
```

## Move column after another column

```sql
ALTER TABLE students
MODIFY COLUMN email VARCHAR(100) AFTER full_name;
```

Important:
When changing position with `MODIFY COLUMN`, you usually write the full column definition again.

---

# 6) Drop a Column

```sql
ALTER TABLE students
DROP COLUMN city;
```

## Drop multiple columns

```sql
ALTER TABLE students
DROP COLUMN city,
DROP COLUMN marks;
```

---

# 7) Add Constraints

Constraints are rules.
You can add them later using `ALTER TABLE`.

## Add `PRIMARY KEY`

```sql
ALTER TABLE students
ADD PRIMARY KEY (id);
```

## Add `UNIQUE`

```sql
ALTER TABLE students
ADD UNIQUE (email);
```

## Add named `UNIQUE`

```sql
ALTER TABLE students
ADD CONSTRAINT uq_email UNIQUE (email);
```

## Add `FOREIGN KEY`

```sql
ALTER TABLE students
ADD CONSTRAINT fk_dept
FOREIGN KEY (department_id)
REFERENCES departments(id);
```

## Add `CHECK`

```sql
ALTER TABLE students
ADD CONSTRAINT chk_age CHECK (age >= 18);
```

---

# 8) Remove Constraints

## Drop primary key

```sql
ALTER TABLE students
DROP PRIMARY KEY;
```

## Drop unique

Usually done by dropping the related index.

```sql
ALTER TABLE students
DROP INDEX email;
```

If the unique constraint was given a custom name:

```sql
ALTER TABLE students
DROP INDEX uq_email;
```

## Drop foreign key

```sql
ALTER TABLE students
DROP FOREIGN KEY fk_dept;
```

## Drop check constraint

```sql
ALTER TABLE students
DROP CHECK chk_age;
```

---

# 9) Change `NOT NULL` or `NULL`

Yes, this is where beginners get confused.

You do this with `MODIFY COLUMN` by rewriting the column definition.

## Make a column `NOT NULL`

```sql
ALTER TABLE students
MODIFY COLUMN name VARCHAR(100) NOT NULL;
```

## Allow `NULL`

```sql
ALTER TABLE students
MODIFY COLUMN name VARCHAR(100) NULL;
```

---

# 10) Add or Change `DEFAULT` Value

## Add default value

```sql
ALTER TABLE students
MODIFY COLUMN city VARCHAR(100) DEFAULT 'Ahmedabad';
```

## Change default value

```sql
ALTER TABLE students
MODIFY COLUMN city VARCHAR(100) DEFAULT 'Surat';
```

## Remove default value

```sql
ALTER TABLE students
ALTER COLUMN city DROP DEFAULT;
```

---

# 11) Add `AUTO_INCREMENT`

```sql
ALTER TABLE students
MODIFY COLUMN id INT AUTO_INCREMENT;
```

## Change starting auto increment value

```sql
ALTER TABLE students
AUTO_INCREMENT = 100;
```

---

# 12) Rename the Table

```sql
ALTER TABLE students
RENAME TO learners;
```

Another common syntax:

```sql
RENAME TABLE students TO learners;
```

---

# 13) One Line Memory Trick for Main Alter Uses

Think of `ALTER TABLE` like this:

* add something
* remove something
* rename something
* modify something
* reorder something
* add a rule
* remove a rule

That is basically the heart of it.

---

# 14) Most Important Beginner Patterns

These are the patterns you will use again and again.

## Add column

```sql
ALTER TABLE table_name
ADD COLUMN column_name datatype;
```

## Change data type

```sql
ALTER TABLE table_name
MODIFY COLUMN column_name new_datatype;
```

## Rename column

```sql
ALTER TABLE table_name
RENAME COLUMN old_name TO new_name;
```

## Rename and redefine column together

```sql
ALTER TABLE table_name
CHANGE COLUMN old_name new_name datatype;
```

## Drop column

```sql
ALTER TABLE table_name
DROP COLUMN column_name;
```

## Add primary key

```sql
ALTER TABLE table_name
ADD PRIMARY KEY (column_name);
```

## Add foreign key

```sql
ALTER TABLE table_name
ADD CONSTRAINT constraint_name
FOREIGN KEY (column_name)
REFERENCES parent_table(parent_column);
```

## Make column not null

```sql
ALTER TABLE table_name
MODIFY COLUMN column_name datatype NOT NULL;
```

## Add default value

```sql
ALTER TABLE table_name
MODIFY COLUMN column_name datatype DEFAULT value;
```

## Change column position

```sql
ALTER TABLE table_name
MODIFY COLUMN column_name datatype AFTER another_column;
```

---

# 15) One Full Example

Suppose this table already exists:

```sql
CREATE TABLE students (
    id INT,
    name VARCHAR(100),
    age INT
);
```

Now let us alter it step by step.

## Add email column

```sql
ALTER TABLE students
ADD COLUMN email VARCHAR(100);
```

## Rename name to full_name

```sql
ALTER TABLE students
RENAME COLUMN name TO full_name;
```

## Change age data type

```sql
ALTER TABLE students
MODIFY COLUMN age BIGINT;
```

## Make full_name not null

```sql
ALTER TABLE students
MODIFY COLUMN full_name VARCHAR(100) NOT NULL;
```

## Move email after full_name

```sql
ALTER TABLE students
MODIFY COLUMN email VARCHAR(100) AFTER full_name;
```

## Add primary key on id

```sql
ALTER TABLE students
ADD PRIMARY KEY (id);
```

---

# 16) Final Beginner Note About `MODIFY COLUMN`

A common beginner doubt is:

**Can `MODIFY COLUMN` change constraints?**

The clean answer is:

**It can change column-level properties that are written as part of the column definition.**

For example, with `MODIFY COLUMN`, you can change things like:

* data type
* size
* `NOT NULL`
* `NULL`
* `DEFAULT`
* `AUTO_INCREMENT`
* position using `FIRST` or `AFTER`

But `MODIFY COLUMN` is not the usual way to add table-level constraints like:

* `PRIMARY KEY`
* `FOREIGN KEY`
* separate named `UNIQUE`
* separate named `CHECK`

Those are usually added with `ADD`, like:

```sql
ALTER TABLE students
ADD PRIMARY KEY (id);
```

So the safe beginner rule is:

* use `MODIFY COLUMN` to rewrite a column definition
* use `ADD` to add big constraints like primary key or foreign key
* use `CHANGE COLUMN` when renaming plus redefining
* use `RENAME COLUMN` when only the name changes

That rule will keep you out of most beginner confusion.
