--a
select * from produse
--b
if exists(select * from produse where cantitate=0)
	delete from produse where cantitate=0
else
	select 'Nu exista produse care nu sunt pe stoc' as Mesaj
--c
update produse set pret=pret*1.1
select * from produse
