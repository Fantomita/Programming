--a
select * from elevi
--b
if exists(select * from elevi where clasa='12B')
	select * from elevi where clasa='12B' and absente>10
else
	select 'Nu exista clasa 12B' as Mesaj
--c
delete from elevi where absente=0
select * from elevi