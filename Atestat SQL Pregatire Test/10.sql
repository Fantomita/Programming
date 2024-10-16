--a
select* from telefon
--b
if exists(select * from telefon where nume='Popescu Maria')
	select * from telefon where nume='Popescu Maria'
else
	select 'Abonatul cautat nu exista in tabela' as Mesaj
--c
select * from telefon where impuls=(select max(impuls) from telefon)