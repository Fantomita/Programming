--a
select * from produse
--b
if exists(select * from produse where cantitate=0)
	delete from produse where cantitate=0
else
	select 'Nu exista produse cu stoc 0' as Mesaj
--c
update produse set pret=pret*1.10
select * from produse