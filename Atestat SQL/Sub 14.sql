--a
select * from bibliot
--b
if exists(select * from bibliot where Autor='Sadoveanu')
	select count(Autor) as 'Numarul cartilor avandu-l ca autor pe Sadoveanu' from bibliot where Autor='Sadoveanu'
else
	select 'Nu exista carti scrise de Sadoveanu' as Mesaj
--c
select * from bibliot order by An