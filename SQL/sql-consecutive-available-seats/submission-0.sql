-- Write your query below
WITH seats AS (
    SELECT
        seat_id,
        free,
        LAG(free) OVER (ORDER BY seat_id) AS previous_free,
        LEAD(free) OVER (ORDER BY seat_id) AS next_free
    FROM cinema
)

SELECT seat_id
FROM seats
WHERE free = 1
  AND (
      previous_free = 1
      OR next_free = 1
  )
ORDER BY seat_id;