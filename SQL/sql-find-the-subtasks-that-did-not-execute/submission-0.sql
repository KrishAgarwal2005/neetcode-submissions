-- Write your query below
with recursive nums as(
    select 1 as n
    union all
    select n+1 from nums where n<20
)
select t.task_id,
n.n as subtask_id
from tasks t
join nums n on n.n<=t.subtasks_count
where not exists(
    select 1
    from executed e
    where e.task_id=t.task_id
    and e.subtask_id=n.n
)