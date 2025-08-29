# Write your MySQL query statement below
SELECT 
    s.user_id,
    IFNULL(ROUND( SUM(CASE WHEN action='confirmed' THEN 1 ELSE 0 END) / COUNT(c.action),2),0) AS confirmation_rate
FROM signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id OR s.user_id IS NULL
GROUP BY c.user_id, s.user_id;