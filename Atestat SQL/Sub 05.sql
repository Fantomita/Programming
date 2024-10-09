--a
select * from examen
--b
update examen set media=(Nota1+Nota2)/2 where Nota1>=5 and Nota2>=5
select * from examen
--c
if exists(select * from examen where Nota1>=5 and Nota2>=5)
	select * from examen where Nota1>=5 and Nota2>=5 order by Nume
else
	select 'Nu exista elevi reusiti la examen' as Mesaj