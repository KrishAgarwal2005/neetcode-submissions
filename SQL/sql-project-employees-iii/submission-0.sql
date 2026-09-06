-- Write your query below
select project_id,
employee_id
from (
    select p.project_id,p.employee_id,
    rank() over (partition by p.project_id
    order by e.experience_years desc) rnk
    from project p
    join employee e on e.employee_id=p.employee_id
)ranked
where rnk=1