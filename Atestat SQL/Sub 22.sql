--a
select * from carti
--b
if exists(select * from carti where [an apar]>2000)
	select * from carti where [an apar]>2000 order by [an apar]
else
	select 'Nu exista carti aparute dupa 2000' as Mesaj
--c
insert into carti (autor, titlu, editura, [an apar]) values ('Thomas Mann', 'Muntele vrajit', 'Corint', 2009)
select * from carti