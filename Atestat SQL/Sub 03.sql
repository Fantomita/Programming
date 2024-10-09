--a
select * from scoala
--b
if exists(select * from scoala where Nume='Ionescu Dan')
	select clasa as 'Clasa lui Ionescu Dan' from scoala where Nume='Ionescu Dan'
else
	insert into scoala (Nume, Clasa, Varsta) values ('Ionescu Dan', '12A', 17)
--c
select * from scoala where Nume<>'Ionescu Dan' and clasa=(select clasa from scoala where Nume='Ionescu Dan')