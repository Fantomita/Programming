--a
select * from telefon28
--b
if exists(select * from telefon28 where achitat=0)
	select * from telefon28 where achitat=0 order by nume, prenume
else
	select 'Nu exita persoane care nu au achitat' as Mesaj
--c
insert into telefon28 (nume, prenume, telefon, valoare, achitat) values ('Mocanu', 'Mircea', '0359002626', 49, 1)
select * from telefon28