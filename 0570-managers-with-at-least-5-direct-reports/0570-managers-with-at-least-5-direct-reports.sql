# Write your MySQL query statement below
-- SELECT 
--     e1.name
-- FROM Employee e1
-- JOIN (SELECT * FROM Employee e3 group by e3.managerId having count(e3.managerId) >=5) as e2
-- ON e1.id = e2.managerId;

SELECT 
    e1.name
FROM Employee e1
JOIN Employee e2
ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerId) >=5;
