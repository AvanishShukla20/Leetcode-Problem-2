# Write your MySQL query statement below

# get the table with grouped values .Then on that group 


select DATE_FORMAT(trans_date, '%Y-%m') as month,
        country,
        Count(trans_date) as trans_count,
        SUM(state = 'approved') as approved_count,
        SUM(amount) as trans_total_amount,
        SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount
from
        Transactions 
Group by 
        DATE_FORMAT(trans_date, '%Y-%m') , country
