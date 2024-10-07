--a
select * from scoala
--b
if exists (select * from scoala where varsta>18)
	select * from scoala where varsta>18
else
	select 'Nu exista elevi cu vasrsta peste 18 ani' as Mesaj
--c
select * from scoala order by varsta desc