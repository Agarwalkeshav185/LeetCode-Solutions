# Write your MySQL query statement below
SELECT employee_id, department_id FROM Employee 
where primary_flag = 'Y' or 
employee_id in (Select employee_id from Employee group by employee_id having count(department_id) = 1);