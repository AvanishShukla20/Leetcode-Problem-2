# Write your MySQL query statement below


-- MUST REALISE THESE MISTAKES and their meanings ->
-- 1. select product_id, min(year) as first_year, quantity, price from Sales group by product_id;

-- query below will return only one row per group 
-- 2. select product_id, min(year) as first_year, quantity, price from (select * from Sales group by product_id) X;

-- if you want to return multiple rows of the group in that group

-- SELECT s.*
-- FROM Sales s
-- JOIN (
--   SELECT product_id
--   FROM Sales
--   GROUP BY product_id
--   HAVING COUNT(*) > 1
-- ) g USING (product_id);


-- select product_id, min(year) as year from Sales group by product_id;

-- apply join back to table to get entries specific to each group

select s.product_id, s.year as first_year , quantity, price
 from Sales as s 
 JOIN (select product_id, min(year) as year 
 from Sales group by product_id) X ON s.product_id = X.product_id AND s.year = X.year



