# Write your MySQL query statement below

UPDATE Salary s
SET s.sex = 
CASE
    WHEN s.sex = 'm' THEN 'f'
    ELSE 'm'
END;
