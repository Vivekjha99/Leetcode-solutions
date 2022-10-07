# Write your MySQL query statement below
select s1.score ,
(select count(distinct(score)) from scores where score>=s1.score)
as "rank"
from scores as s1 
order by s1.score desc;