--a
select * from produse29
--b
select sum(pret*cantitate) as 'Valoare totala produse' from produse29
--c
if exists(select * from produse29 where year(dataex)=year(getdate()) and month(dataex)=month(getdate()) and day(dataex)=day(getdate())+1)
	select * from produse29 where year(dataex)=year(getdate()) and month(dataex)=month(getdate()) and day(dataex)=day(getdate())+1
else
	select 'Nu exista produse care expira maine' as Mesaj