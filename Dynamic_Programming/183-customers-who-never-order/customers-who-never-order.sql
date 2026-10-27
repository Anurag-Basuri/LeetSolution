-- Write your PostgreSQL query statement below
SELECT c.name as Customers from Customers c left join Orders o on c.id = o.customerid where o.customerId is NULL;