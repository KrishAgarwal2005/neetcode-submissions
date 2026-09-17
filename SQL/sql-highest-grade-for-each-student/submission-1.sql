-- Write your query below
with ranked as(
    select student_id,exam_id,score,
   row_number() over( partition by student_id order by
   score desc,exam_id) as rn
   from exam_results
)
select student_id,exam_id,score
from ranked 
where rn=1
order by student_id;