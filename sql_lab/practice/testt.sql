/* Write your PL/SQL query statement below */

SELECT
    (SELECT NAME FROM DEPARTMENT WHERE ID = D.DEPARTMENTID) AS "Department",
    NAME AS "Employee",
    SALARY AS "Salary"
FROM
    (
    SELECT 
        DEPARTMENTID,
        NAME,
        SALARY,
        DENSE_RANK() OVER(PARTITION BY DEPARTMENTID ORDER BY SALARY DESC) AS "rnk"
    FROM 
        EMPLOYEE
    ORDER BY DEPARTMENTID ASC,SALARY DESC
    ) D
WHERE "rnk" IN (1,2,3);