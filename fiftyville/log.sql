-- Keep a log of any SQL queries you execute as you solve the mystery.

.schema
-- finding details when the theft took place - the result is 10:15
SELECT description from crime_scene_reports WHERE month = 7 AND day = 28 or day = 29 AND street = 'Humphrey Street'
-- searching for interviews mentioning bakery
SELECT * FROM interviews WHERE month = 7 AND day = 29 AND transcript LIKE '%bakery%';
-- seraching for flights taking of earliest in the morning - result is flight ID 36
SELECT * FROM flights WHERE month = 7 AND day = 29
-- flight 36 is going to airport id 4 whisch happens to be LaGuardia in New York
SELECT * FROM airports WHERE id = 4
--superquery to narrow everything down, namelyu find a person whose passport is on the list of passengers of flight 36 to NY, that made a trx at ATM on Legget Street and was caught on camera leaving the bakery parking within 10 minutes from theft
SELECT * FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street')) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28  AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit') AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36 )
-- the thief seems to be BRUCE 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
-- now whom did he call on that day and the call was shorter than a minute?
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533'
-- the call receiver was (375) 555-8161, who happens to be
SELECT * FROM people WHERE phone_number = '(375) 555-8161'
-- 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
