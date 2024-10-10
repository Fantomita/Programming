--a
select * from carti
--b
if exists(select * from carti where anapar>1990 and anapar<2010)
	select autor, titlu, anapar, nre from carti where anapar>1990 and anapar<2010
else
	select 'Nu exista carti aparute intre anii 1990 si 2010' as Mesaj
--c
delete from carti where nre=0
select * from carti