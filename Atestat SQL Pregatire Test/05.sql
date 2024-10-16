--a
select * from examen
--b
update examen set media=(nota1 + nota2)/2 where nota1>=5 and nota2>=5
select * from examen
--c
if exists(select * from examen where nota1>=5 and nota2>=5)
	select * from examen where nota1>=5 and nota2>=5 order by nume
else
	select 'Nu exista elevi reusiti la examen' as Mesaj