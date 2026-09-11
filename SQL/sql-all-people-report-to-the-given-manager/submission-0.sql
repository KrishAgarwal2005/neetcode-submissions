-- Write your query below
with recursive sub as(
    select employee_id
    from employees 
    where manager_id=1
    and employee_id<>1
    union
    select e.employee_id
    from employees e
    join sub s on
    e.manager_id=s.employee_id
)
select employee_id
from sub