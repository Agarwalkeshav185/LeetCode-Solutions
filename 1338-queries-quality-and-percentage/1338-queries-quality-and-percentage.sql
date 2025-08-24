# Write your MySQL query statement below
SELECT 
    query_name,
    ROUND( AVG(q.rating/q.position) ,2) AS quality,
    ROUND( AVG(case when q.rating < 3 then 1.00 else 0.00 end)*100,2)AS poor_query_percentage
FROM Queries q
GROUP BY query_name;