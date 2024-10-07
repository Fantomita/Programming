--a
select * from elevi
--b
if exists(select * from elevi where clasa='12A')
	select * from elevi where absente=(select max(absente) from elevi where clasa='12A') and clasa='12A'
else
	select 'Nu exista clasa 12A' as Mesaj
--c
select sum(absente) as 'Total absente pe scoala' from elevi