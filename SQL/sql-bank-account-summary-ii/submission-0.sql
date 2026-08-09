-- Write your query below
select u.name,
sum(t.amount) as balance
from users u
left join transactions t on u.account=t.account
group by u.name
having sum(t.amount)>10000;

