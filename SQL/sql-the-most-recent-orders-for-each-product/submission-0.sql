-- Write your query below
select p.product_name,
p.product_id,
o.order_id,
o.order_date
from products p
join orders o on p.product_id=o.product_id
where o.order_date=(
    select max(o2.order_date)
    from orders o2
    where o2.product_id=p.product_id
)
order by p.product_name asc,
p.product_id asc,o.order_id asc