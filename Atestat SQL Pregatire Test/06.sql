--a
select nume, clasa, nota1, nota2 from examen
--b
select nume, clasa, nota1, nota2, (nota1+nota2)/2 as Medie from examen where nota1>=5 and nota2>=5
--c
if exists(select * from examen where nota1>=5 and nota2>=5)
	select nume, clasa, nota1, nota2 from examen where nota1>=5 and nota2>=5 order by nume
else
	select 'Nu exista elevi reusiti la examen' as Mesaj