--a
select * from scoala
--b
if exists(select * from scoala where varsta>18)
	select * from scoala where varsta>18
else
	select 'Nu exista elevi majori' as Mesaj
--c
select * from scoala order by varsta desc