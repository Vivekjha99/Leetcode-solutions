# Write your MySQL query statement below
select T.employee_id from
(select * from employees left join salaries using (employee_id)
union 
select * from employees right join salaries using (employee_id))
as T
where T.name is NULL or T.salary is NULL
order by T.employee_id;