--a
select * from turism
--b
if exists(select * from turism where categorie=1)
	select * from turism where categorie=1
else
	select 'Nu exista unitati de categoria 1' as Mesaj
--c
select count(categorie) as 'Unitati de categoria 4' from turism where categorie=4