-- # Write your MySQL query statement below
-- SELECT p.product_id,
-- ROUND(SUM(p.price*u.units)*1.0 / SUM(u.units),2) as average_price
-- from Prices p 
-- LEFT JOIN UnitsSold u 
-- ON p.product_id = u.product_id GROUP BY p.product_id ;

SELECT 
    p.product_id,
    ROUND(IFNULL(SUM(p.price * u.units) * 1.0 / SUM(u.units), 0), 2) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u 
    ON p.product_id = u.product_id AND purchase_date between p.start_date and p.end_date
GROUP BY p.product_id;
