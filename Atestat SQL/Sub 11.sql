--a
select * from telefon
--b
update telefon set plata=5*impuls
select * from telefon
--c
select * from telefon where plata=(select min(plata) from telefon)