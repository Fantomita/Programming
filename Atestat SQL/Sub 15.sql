--a
select * from elevi
--b
if exists(select * from elevi where clasa='12A' and varsta>=18)
	select * from elevi where clasa='12A' and varsta>=18
else
	select 'Nu exista elevi majori in clasa 12A' as Mesaj
--c
select * from elevi order by clasa, nume