--a
select * from olimp
--b
if exists(select * from olimp where fel='B' and marime=42)
	select * from olimp where fel='B' and marime=42
else
	select 'Nu exista articole barbatesti de marime 42' as mesaj
--c
select * from olimp where pret=(select max(pret) from olimp where fel='F') and fel='F'
