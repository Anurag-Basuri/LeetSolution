-- Write your PostgreSQL query statement below
select e.name as Employee from employee e join employee p on e.managerId = p.id where e.salary > p.salary;