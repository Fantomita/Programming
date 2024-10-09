--a
select * from roma
--b
if exists(select * from roma where varsta>=3 and varsta<=10)
	select * from roma where varsta>=3 and varsta<=10
else
	select 'Nu exista copii cu varsta ceruta' as Mesaj
--c
select * from roma where varsta=(select max(varsta) from roma)