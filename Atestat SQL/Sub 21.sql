--a
select * from elevi21
--b
update elevi21 set rezultat='Admis' where nota1>=5 and nota2>=5
update elevi21 set rezultat='Respins' where nota1<5 or nota2<5
select * from elevi21
--c
if exists(select * from INFORMATION_SCHEMA.tables where TABLE_NAME = 'Admis')
	drop table Admis
if exists(select * from INFORMATION_SCHEMA.tables where TABLE_NAME = 'Respins')
	drop table Respins
create table Admis(Nume nchar(15), Nota1 decimal(5,2), Nota2 decimal(5,2), Rezultat nchar(7))
create table Respins(Nume nchar(15), Nota1 decimal(5,2), Nota2 decimal(5,2), Rezultat nchar(7))
insert into Admis(nume, nota1, nota2, rezultat) select nume, nota1, nota2, rezultat from elevi21 where nota1>=5 and nota2>=5
insert into Respins(nume, nota1, nota2, rezultat) select nume, nota1, nota2, rezultat from elevi21 where nota1<5 and nota2<5
select * from Admis order by nume
select * from Respins order by nume