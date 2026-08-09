-- Write your query below
select a.sale_date,
a.sold_num-o.sold_num as diff
from sales a
join sales o on a.sale_date=o.sale_date
where a.fruit='apples' and o.fruit='oranges'
order by a.sale_date;