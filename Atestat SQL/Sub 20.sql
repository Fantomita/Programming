--a
select * from elevi
--b
if exists(select * from elevi where profil='real')
	select * from elevi where profil='real'
else
	select 'Nu exista elevi la profil real' as Mesaj
--c
select avg(media) as 'Media clasei 12E' from elevi where clasa='12E'