-- Write your query below
select a.player_id,
a.device_id
from activity a
inner join(
    select player_id,min(event_date) as 
    first_login
    from activity
    group by player_id
) first_logins on a.player_id=first_logins.player_id
and a.event_date=first_logins.first_login