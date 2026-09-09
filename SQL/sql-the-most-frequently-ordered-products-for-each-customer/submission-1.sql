-- Write your query below
select o.customer_id,
o.product_id,p.product_name
from(
    select
    customer_id,product_id,
    rank() over(partition by customer_id order by count(*) desc)
    as rnk
    from orders
    where customer_id in (select customer_id from customers)
    group by customer_id,product_id
)o
join products p on p.product_id=o.product_id
where o.rnk=1;