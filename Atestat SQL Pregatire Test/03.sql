--a
select * from scoala
--b
if exists(select * from scoala where nume='Ionescu Dan')
	select CLASA from scoala where nume='Ionescu Dan'
else
	insert into scoala (nume, clasa, varsta) values ('Ionescu Dan', 17, '12B')
--c
select * from scoala where nume<>'Ionescu Dan' and clasa=(select clasa from scoala where nume='Ionescu Dan')