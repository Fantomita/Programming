--a
select nume, tel, impuls, plata from telefon
--b
update telefon set plata=impuls*5
select nume, tel, impuls, plata from telefon
--c
select nume, tel, impuls, plata from telefon where plata=(select min(plata) from telefon)