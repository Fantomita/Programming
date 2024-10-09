--a
select * from clasa
--b
if exists(select * from clasa where nota_b>=7 and nota_p>=7)
	update clasa set media = (nota_b + nota_p) / 2 where nota_b>=7 and nota_p>=7
else
	select 'Nu exista elevi reusiti la examen' as Mesaj
select * from clasa
--c
select * from clasa where nota_b >= 7 and nota_p >= 7 order by limbaj