--a
select * from hotel
--b
update hotel set pret_cam = nr_pat * pret_pat
select * from hotel
--c
select * from hotel where pret_cam = (select max (pret_cam) from hotel)