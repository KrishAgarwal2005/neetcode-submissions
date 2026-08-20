-- Write your query below
select d.name as department,
e.name as employee , e.salary
from employee e
join department d on e.department_id=d.id
where e.salary=(
    select max(e2.salary)
    from employee e2
    where e2.department_id=e.department_id
)