-- Write your query below
select min(log_id) as start_id,
max(log_id) as end_id
from(
select log_id,
log_id-row_number()over(order by log_id) as grp
from logs
) t
group by grp
order by start_id