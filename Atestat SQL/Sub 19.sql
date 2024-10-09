--a
select * from produse
--b
if exists(select * from produse where denumire='tastatura')
	select pret, cantitate from produse where denumire='tastatura'
else
	insert into produse (denumire, pret, cantitate) values ('tastatura', 11.57, 25)
	select * from produse
--c
update produse set pret=1.19*pret
select * from produse
	