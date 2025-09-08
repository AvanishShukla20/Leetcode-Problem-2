# Write your MySQL query statement below


# find no of users who are active on a single day

select activity_date day , COUNT(distinct user_id) active_users from Activity group by activity_date having activity_date BETWEEN '2019-06-28' AND '2019-07-27';