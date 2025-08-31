# Write your MySQL query statement below
select
 r.contest_id, 
 ROUND( COUNT(r.user_id) * 100 / ( SELECT COUNT(user_id) from Users), 2) as percentage
  from Register as r group by r.contest_id order by percentage DESC, contest_id ASC