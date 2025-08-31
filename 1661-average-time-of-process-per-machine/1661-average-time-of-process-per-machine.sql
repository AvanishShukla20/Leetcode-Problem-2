# Write your MySQL query statement below
select w1.machine_id, ROUND(AVG(w1.timestamp - w2.timestamp), 3) as processing_time from Activity as w1 inner join Activity as w2 on w1.machine_id = w2.machine_id  AND w1.process_id = w2.process_id where w1.activity_type = 'end' AND w2.activity_type = 'start'
Group by w1.machine_id
