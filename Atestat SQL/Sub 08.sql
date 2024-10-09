--a
select * from telefon
--b
if exists(select * from telefon where tel='0359123456')
	select 'Abonatul cu numarul dat exista' as Mesaj
else
	insert into telefon (Nume, Tel, Adresa, Impuls) values ('Popescu', '0359123456', 'F', 125)
--c
select * from telefon order by Nume