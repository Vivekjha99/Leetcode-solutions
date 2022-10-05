CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare M INT;
set M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary from employee order by salary DESC limit M,1
      
  );
END