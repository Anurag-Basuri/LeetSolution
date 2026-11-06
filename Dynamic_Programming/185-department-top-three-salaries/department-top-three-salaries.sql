with rank as (
    select e.name, e.salary, d.name as dep,
    dense_rank() over 
    (partition by d.name order by e.salary desc) 
    as rnk from Employee e join Department d
    on e.departmentId = d.id
) select 
dep as Department, name as Employee, salary 
from rank where rnk <= 3;