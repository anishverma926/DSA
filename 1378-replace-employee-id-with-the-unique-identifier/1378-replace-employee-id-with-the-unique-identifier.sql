# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name
FROM Employees
LEFT join EmployeeUNI
on Employees.id = EmployeeUNI.id;