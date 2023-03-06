-- SELECT AVG(rating) FROM
-- (SELECT title, rating FROM ratings
-- JOIN movies ON ratings.movie_id = movies.id
-- WHERE year = 2012
-- LIMIT 55);

SELECT AVG(rating) FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;