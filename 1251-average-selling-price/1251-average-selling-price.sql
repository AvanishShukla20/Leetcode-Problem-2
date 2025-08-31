# Write your MySQL query statement below

-- select Prices.product_id, AVG(units*price) from Prices JOIN UnitsSold on Prices.product_id = UnitsSold.product_id where UnitsSold.purchase_date >= Prices.start_date AND UnitsSold.purchase_date <= Prices.end_date  Group by Prices.product_id

select Prices.product_id, IFNULL(ROUND( SUM(UnitsSold.units*Prices.price) / SUM(UnitsSold.units), 2), 0)  AS average_price from Prices JOIN UnitsSold on Prices.product_id = UnitsSold.product_id where UnitsSold.purchase_date >= Prices.start_date AND UnitsSold.purchase_date <= Prices.end_date  Group by Prices.product_id