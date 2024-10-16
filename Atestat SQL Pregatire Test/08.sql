--a
select * from telefon
--b
if exists(select * from telefon where tel='0740123444')
	select 'Abonatul exista deja' as Mesaj
else
	insert into telefon (nume, tel, adresa) values ('Popescu', '0740123444', 'Vasile Alecsandri 1')
--c
select * from telefon order by nume