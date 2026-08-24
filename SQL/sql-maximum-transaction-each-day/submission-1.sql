-- Write your query below
select transaction_id 
from transactions
where (Date(day),amount) in(
  select Date(day),max(amount)  
  from transactions
  group by date(day)
)
order by transaction_id asc;