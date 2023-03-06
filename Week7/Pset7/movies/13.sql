SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN
(SELECT movies.id FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE name = "Kevin Bacon"
AND birth = 1958)     --to nam daje listę tytułów z Kevinem
AND name != "Kevin Bacon";