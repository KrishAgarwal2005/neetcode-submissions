-- Write your query below
with titles as(
    select wimbledon as player_id from championships
    union all
    select fr_open from championships
    union all
    select us_open from championships
    union all
    select au_open from championships
    
)
select p.player_id,p.player_name,
count(*) as grand_slams_count
from players p
join titles t on t.player_id=p.player_id
group by p.player_id,p.player_name