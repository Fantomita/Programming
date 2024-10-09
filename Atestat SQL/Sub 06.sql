--a
select * from examen
--b
select Nume, Clasa, Nota1, Nota2, (Nota1+Nota2)/2 as Medie from examen where nota1>=5 and nota2>=5
--c
if exists(select * from examen where nota1>=5 and nota2>=5)
	select * from examen where nota1>=5 and nota2>=5 order by nume
else
	select 'Nu exista elevi reusiti la examen' as Mesaj