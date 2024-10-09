--a
select * from bibliot
--b
if exists(select * from bibliot where titlu='Pe culmile disperarii')
	select autor, editura from bibliot where titlu='Pe culmile diserarii'
else
	select 'Cartea cu titlu cerut nu exista in biblioteca' as Mesaj
--c
select * from bibliot where editura='All'
