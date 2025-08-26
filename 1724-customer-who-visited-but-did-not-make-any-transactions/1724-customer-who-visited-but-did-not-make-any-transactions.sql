# Write your MySQL query statement below
SELECT 
    v.customer_id,
    COUNT(distinct(v.visit_id)) AS count_no_trans
FROM Visits v
where v.visit_id not in (select visit_id from transactions)
GROUP BY v.customer_id;