WITH rnemail AS (
    SELECT id, ROW_NUMBER() OVER (
        PARTITION BY email
        ORDER BY id ASC
    ) AS rn FROM Person
) DELETE FROM Person WHERE id IN (
    SELECT id FROM rnemail WHERE rn > 1
);