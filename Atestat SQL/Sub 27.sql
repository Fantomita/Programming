--a
select * from locatar
--b
select * from locatar order by bloc, ap, nume
--c
if exists(select * from locatar where nume='Pop Ion')
	select plata as 'Suma de plata a locatarului Pop Ion' from locatar where nume='Pop Ion'
else
	select 'Nu exista locatarul Pop Ion' as Mesaj