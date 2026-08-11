-- Write your query below
select distinct c.title
from tv_program tv
right join content c on c.content_id=tv.content_id
where c.content_type='Movies' and c.kids_content='Y'
and tv.program_date like '2020-06%';