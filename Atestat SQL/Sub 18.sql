--a
select * from produse
--b
if exists(select * from produse where denumire='mouse')
	select pret, cantitate from produse where denumire='mouse'
else
	select 'Nu exista in tabela produsul mouse' as Mesaj
--c
select * from produse where pret=(select max(pret) from produse)