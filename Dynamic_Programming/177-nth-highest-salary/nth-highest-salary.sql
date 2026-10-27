CREATE OR REPLACE FUNCTION NthHighestSalary(N INT)
RETURNS TABLE (Salary INT) AS $$
BEGIN
    RETURN QUERY
    SELECT MAX(ranked.salary) AS Salary
    FROM (
        SELECT
            e.salary,
            DENSE_RANK() OVER (
                ORDER BY e.salary DESC
            ) AS rnk
        FROM Employee e
        WHERE e.salary IS NOT NULL
    ) AS ranked
    WHERE ranked.rnk = N;
END;
$$ LANGUAGE plpgsql;