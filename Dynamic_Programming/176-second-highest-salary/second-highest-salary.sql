WITH ranked AS (
    SELECT
        salary,
        DENSE_RANK() OVER (
            ORDER BY salary DESC
        ) AS salary_rank
    FROM Employee
    WHERE salary IS NOT NULL
)
SELECT MAX(salary) as SecondHighestSalary 
FROM ranked
WHERE salary_rank = 2;