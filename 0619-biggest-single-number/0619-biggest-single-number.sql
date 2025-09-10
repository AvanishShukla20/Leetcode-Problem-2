# Write your MySQL query statement below
Select max(X.num) as num from (select num from MyNumbers group by num having count(num) = 1) X ;