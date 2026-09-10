-- Write your query below
select user_id,
max(gap) as biggest_window
from(
    select user_id,
   (lead(visit_date,1,DATE '2021-01-01') over(partition by
   user_id order by visit_date) - visit_date) as gap
from user_visits
) t
group by user_id
order by user_id;