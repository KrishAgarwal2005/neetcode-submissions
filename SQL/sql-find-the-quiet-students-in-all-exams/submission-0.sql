with marked_stats as(
    select exam_id,
    max(score) as high,
    min(score) as low
    from exam
    group by exam_id
),
loud_students as (
    select distinct e.student_id
    from exam e
    join marked_stats as m on m.exam_id=e.exam_id
    where e.score=m.high or e.score=m.low
)
select s.student_id,
s.student_name
from student s
where s.student_id in(select
student_id from exam) and s.student_id
not in(select student_id from loud_students)
order by s.student_id;