-- Keep a log of any SQL queries you execute as you solve the mystery.
-- knowing the schema of the table
-- .schema

-- description of the event
-- SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = "Humphrey Street";
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today 
-- with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- Littering took place at 16:36. No known witnesses.

-- interviews of the event
-- SELECT transcript FROM interviews WHERE day = 28 AND month = 7;
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. 
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in 
-- that time frame.
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
-- I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- check the bakery cctv footage
SELECT activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute = 20;
-- exit | 94KL13X
-- exit | 4328GD8
-- exit | L93JTIZ
-- exit | 322W7JE

-- check the atm logs
-- SELECT account_number, amount, transaction_type FROM atm_transactions WHERE year = 2021 AND day = 28 AND month = 7 AND atm_location = "Leggett Street";
-- finding the person id
-- SELECT person_id FROM bank_accounts WHERE account_number = 28500762;
-- SELECT person_id FROM bank_accounts WHERE account_number = 28296815;
-- SELECT person_id FROM bank_accounts WHERE account_number = 76054385;
-- SELECT person_id FROM bank_accounts WHERE account_number = 49610011;
-- SELECT person_id FROM bank_accounts WHERE account_number = 16153065;
-- SELECT person_id FROM bank_accounts WHERE account_number = 25506511;
-- SELECT person_id FROM bank_accounts WHERE account_number = 81061156;
-- SELECT person_id FROM bank_accounts WHERE account_number = 26013199;

-- finding the person details
-- SUSPECT DETAILS
-- ACCOUNTNO|AMT|TRANS||||PERSON ID||||PERSON NAME||PHONE NUMBER||||PASSPORT NUMBER||||LICENSE PLATE
-- 28500762|48|withdraw - 467400    -   LUCA    -   (389) 555-5198  -   8496433585  -   4328GD8 SUSPECT
-- 28296815|20|withdraw - 395717    -   KENNY   -   (826) 555-1652  -   9878712108  -   30G67EN
-- 76054385|60|withdraw - 449774    -   TAYLOR  -   (286) 555-6063  -   1988161715  -   1106N58
-- 49610011|50|withdraw - 686048    -   BRUCE   -   (367) 555-5533  -   5773159633  -   94KL13X SUSPECT
-- 16153065|80|withdraw - 458378    -   BROOKE  -   (122) 555-4581  -   4408372428  -   QX4YZN3
-- 25506511|20|withdraw - 396669    -   IMAN    -   (829) 555-5269  -   7049073643  -   L93JTIZ SUSPECT
-- 81061156|30|withdraw - 438727    -   BENISTA -   (338) 555-6650  -   9586786673  -   8X428L0
-- 26013199|35|withdraw - 514354    -   DIANA   -   (770) 555-1861  -   3592750733  -   322W7JE SUSPECT

-- I reached here on the basis of people who did the transaction at the bank
-- SUSPECT LIST
-- ACCOUNTNO|AMT|TRANS||||PERSON ID||||PERSON NAME||PHONE NUMBER||||PASSPORT NUMBER||||LICENSE PLATE
-- 28500762|48|withdraw - 467400    -   LUCA    -   (389) 555-5198  -   8496433585  -   4328GD8 
-- 49610011|50|withdraw - 686048    -   BRUCE   -   (367) 555-5533  -   5773159633  -   94KL13X CALLED ID = 233
-- 25506511|20|withdraw - 396669    -   IMAN    -   (829) 555-5269  -   7049073643  -   L93JTIZ 
-- 26013199|35|withdraw - 514354    -   DIANA   -   (770) 555-1861  -   3592750733  -   322W7JE CALLED ID = 255

-- searching the phone calls for the numbers to match in the suspect list
-- lowest call duration are - 51, 36, 45, 60, 69, 50, 43, 49, 67, 38, 88, 61, 55, 54, 75(seconds)
-- details of matching call lists
-- PERSON NAME  PHONE NUMBER    PASSPORT NUMBER    LICENSE PLATE  WHOM CALLED     ID   DURATION
-- BRUCE   -   (367) 555-5533  -   5773159633  -   94KL13X  -   (375) 555-8161 - 233 - 45 (ROBIN)
-- DIANA   -   (770) 555-1861  -   3592750733  -   322W7JE  -   (725) 555-3243 - 255 - 49 (PHILLIPS)
-- Receiver Details
-- ROBIN   -   (375) 555-8161   -   NULL
-- PHILLIPS-   (725) 555-3243   -   3391710505

-- Searching the airports for the suspects
-- Airport in Fiftyville is listed below
-- ID   ABB     NAME                    CITY
-- 8    CSF     Fiftyville Regional     Fiftyville

-- Searching the passengers list of the airport above
-- Bruce took a flight of id 36 and seat at 4A.
-- Diana took mulitple flights - 18, 4C | 24, 2C | 54, 6C
-- Phillips took multiple flights - 10, 2A | 28, 2A | 47, 4D

-- Searching the flights list on the date of 29 July, 2021
-- Bruce took the flight from origin_id = 8 and destination_id = 4 to LaGuardia Airport, New York.
-- Diana took the flight of (id = 18, origin = 8, dest = 6) none other flights were taken on the date to Logan International Airport, Boston.

-- Thereby, we can conclude that the,
-- Thief : Bruce
-- Accomplice : Robin
-- Destination : LaGuardia Airport, New York City