select max(salary) as SecondHighestSalary from (
    select distinct salary, dense_Rank() over (order by salary desc)
        as rnk from employee
    ) where rnk = 2;