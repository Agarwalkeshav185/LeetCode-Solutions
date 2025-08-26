# Write your MySQL query statement below
SELECT 
    v.customer_id,
    COUNT(distinct(v.visit_id)) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON t.visit_id = v.visit_id
where v.visit_id not in (select visit_id from transactions)
GROUP BY v.customer_id;