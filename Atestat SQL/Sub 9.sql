--a
select * from telefon
--b
if exists(select * from telefon where nume='Scarlat Vasile' and tel='0740123444')
	delete from telefon where nume='Scarlat Vasile' and tel='0740123444'
else
	select 'Abonatul cautat nu este in tabela' as Mesaj
--c
select sum(Impuls) as 'Numar total impulsuri' from telefon