# Write your MySQL query statement below
# select Students.student_id, student_name, subject_name, count(*) from Students LEFT JOIN Examinations on Students.student_id = Examinations.student_id Group by Students.student_id, subject_name -> this give no of times student attended his selected subject

SELECT
  s.student_id,
  s.student_name,
  sub.subject_name,
  COUNT(e.student_id) AS attended_exams
FROM
  Students AS s
CROSS JOIN
  Subjects AS sub
LEFT JOIN
  Examinations AS e
  ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY
  s.student_id,
  s.student_name,
  sub.subject_name
ORDER BY
  s.student_id,
  sub.subject_name;