select c.name as customer_name,
c.customer_id,
o.order_id,
o.order_date
from customers c
join orders o on c.customer_id=o.customer_id
where(select count(*)
from orders o2
where o2.customer_id=o.customer_id
and o2.order_date>o.order_date
)<3
order by c.name asc,
c.customer_id asc,o.order_date desc