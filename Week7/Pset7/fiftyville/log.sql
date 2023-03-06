-- Keep a log of any SQL queries you execute as you solve the mystery.
-- 1 - Getting to know with the description of the theft
SELECT description FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND year = 2021
AND street= 'Humphrey Street';
--We have the hour: 10:15am  and place: bakery; there are 3 witnesses, they were present at this time in bakery, every interview with them mentions
-- bakery

--2 - finding the interviews with 3 witnesses
SELECT transcript FROM interviews
WHERE month = 7
AND day = 28
AND year = 2021
AND transcript LIKE '%bakery%';
-- within 10 mins after the theft the thief got into the car in bakery parking lot - check out the cctv cameras
-- Name of the bakery: Emma's, before the witness arrived at bakery he/she saw that thief withdrew some money from the ATM on Leggett Street,
-- he/she also knows the thief
-- After the thief left the bakery he called someone and was talking less than a minute, they planned to take the earlist flight out of
--Fiftiville the next day, the other person were to buy the plane tickets

-- Checking out the cctv cameras - getting to know the thief's car's license plate - the list of suspects
SELECT license_plate, activity, minute FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND year = 2021
AND hour = 10
AND minute BETWEEN 15 AND 25;
-- Got the license plates of 8 cars that left the parking within 10 mins after the theft

-- Checking out the ATM from which the thief withdrew some money before the crime
SELECT account_number, amount FROM atm_transactions
WHERE month = 7
AND day = 28
AND year = 2021
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- Got the list of 8 account numbers with the amounts of money withdrew - Can later connect the account numbers with license plates (via people table)

--Names of the people who withdrew the money:
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE month = 7
AND day = 28
AND year = 2021
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw');

-- Checking out the phone calls that took place after the theft - probably between the thief and the accomplice
SELECT caller, receiver FROM phone_calls
WHERE month = 7
AND day = 28
AND year = 2021
AND duration < 60;
--List of 9 calls (2 times the same number but to different receivers)

--Checking out the flights - the suspect wanted to take the earliest flight out of the city the next day
--id of Fiftyille airport:
SELECT id, full_name FROM airports
WHERE city = 'Fiftyville';      --id = 8

--Finding the earliest flight out of Fiftyville the next day after the crime
SELECT origin_airport_id, destination_airport_id, hour, minute FROM flights
WHERE month = 7
AND day = 29
AND year = 2021
AND origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville')
ORDER BY hour, minute;
-- flight at 8:20 to LaGuardia Airport

--name of the city
SELECT full_name, city FROM airports WHERE full_name = 'LaGuardia Airport';
--name of the city: New York City

--id of the flight:
SELECT id FROM flights
WHERE month = 7
AND day = 29
AND year = 2021
AND origin_airport_id = 8
AND destination_airport_id = 4;
-- id = 36

--List of numbers of passports of passengers from the flight the theft took:
SELECT passport_number FROM passengers
WHERE flight_id = 36;
--list of 8 passport numbers

--Combination of the information - passport number, bank accounts, telephone number and license plate - one person should appear on those 3 lists - this
-- will probably be the thief
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE phone_calls.caller IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60)
AND passengers.passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36)
AND bakery_security_logs.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND name IN (SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE month = 7
AND day = 28
AND year = 2021
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw'))
-- name of the thief - Bruce

--finding out the name of accomplice - who Bruce was talking with
SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE caller IN (SELECT phone_number FROM people WHERE name = 'Bruce')
AND month = 7
AND day = 28
AND year = 2021
AND duration < 60;
-- name of accomplice - Robin

