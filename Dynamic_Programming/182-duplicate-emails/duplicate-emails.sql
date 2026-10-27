-- Write your PostgreSQL query statement below
select p.email from Person p group by p.email having count(*) > 1;