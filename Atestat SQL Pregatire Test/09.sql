--a
select * from telefon
--b
if exists(select * from telefon where nume='Scarlat Vasile' and tel='0740123444')
	delete from telefon where nume='Scarlat Vasile' and tel='0740123444'
else
	select 'Nu exista abonatul Scarlat Vasile cu numarul dat' as Mesaj
--c
select sum(impuls) as 'Impulsuri Folosite' from telefon