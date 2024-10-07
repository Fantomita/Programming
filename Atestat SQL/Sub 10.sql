--a
select * from telefon
--b
if exists(select * from telefon where nume='Popescu Maria')
	select tel, adresa, impuls from telefon where nume='Popescu Maria'
else
	select 'Nu exista abonatul cu numele Popescu Maria in tabela'
--c
select * from telefon where impuls=(select max(impuls) from telefon)