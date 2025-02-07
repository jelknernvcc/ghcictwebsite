







CREATE TYPE suit 
AS ENUM ('heart', 'diamond', 'club', 'spade');







CREATE TYPE rank 
AS ENUM ('A',  '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K');



CREATE TYPE color 
AS ENUM ('red', 'blue');














CREATE TABLE your_cards (
    rank rank,
    suit suit,
    back_color color
);




INSERT INTO your_cards(rank, suit, back_color)
SELECT rank, suit, back_color
FROM all_cards
ORDER BY RANDOM()
LIMIT 30;







SELECT COUNT(*) FROM your_cards WHERE rank = '7';





SELECT COUNT(*) FROM your_cards WHERE rank = '7';





SELECT COUNT(*) FROM your_cards WHERE rank = '8';






CREATE INDEX idx_rank ON your_cards(rank);





SELECT count(*) FROM your_cards WHERE rank = 'A';





SELECT suit, count(*) FROM your_cards WHERE rank = '7';





CLUSTER your_cards USING idx_rank;






INSERT INTO your_cards (rank, suit, back_color) VALUES ('7', 'hearts', 'red');
DELETE FROM your_cards WHERE rank = 'A';







CREATE TABLE your_cards (
    rank rank,
    suit suit,
    back_color color
) PARTITION BY LIST (back_color);

CREATE TABLE your_cards_red PARTITION OF your_cards FOR VALUES IN ('red');
CREATE TABLE your_cards_blue PARTITION OF your_cards FOR VALUES IN ('blue');



--Run these next two queries in parallel
SELECT COUNT(*) FROM your_cards WHERE rank = '7';




SELECT rank, suit FROM your_cards WHERE rank = '7' GROUP BY rank, suit HAVING COUNT(*) > 1;






--JOIN
SELECT y.rank, o.rank
FROM your_cards y
JOIN opponent_cards o
ON y.rank = o.rank;

