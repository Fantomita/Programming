--a
select * from elevi26
--b
select * from elevi26 order by clasa, nume, prenume
--c
if exists(select * from INFORMATION_SCHEMA.tables where TABLE_NAME='alocatii')
	drop table alocatii
create table alocatii (Nume nchar(10), Prenume nchar(10), Datan date, Adresa nchar(30), Clasa nchar(3))
insert into alocatii (Nume, Prenume, Datan, Adresa, Clasa) select * from elevi26 where year(datan) >= 1993
select * from alocatii