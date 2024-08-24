SQL> SELECT * FROM EMPLOYEE_20;

EMP_ EMP_NAME        JOB            SALARY MAN    DEPT_NO                       
---- --------------- ---------- ---------- --- ----------                       
E006 Amit            WORKER         100000 NO           2                       
E018 Ashish          WORKER          40000 NO           3                       
E010 Aniket          HR             130000 YES          4                       
E003 Akansha Jha     WORKER          20000 YNO          4                       
E012 Ankita Thakur   MANAGER        100000 YES          1                       
E001 Abhishek        MANAGER        130000 YES          2                       
E029 Ayush                         3000000                                      
E004 Akansha Sharma  MANAGER        100000 YES          4                       
E015 Anuj            HR             180000 YES          3                       
E016 Archit          MANAGER        140000 YES          3                       
E008 Ananya          HR             175000 YES          2                       

EMP_ EMP_NAME        JOB            SALARY MAN    DEPT_NO                       
---- --------------- ---------- ---------- --- ----------                       
E014 Anshal          HR             200000 YES          1                       
E007 Amrit           WORKER          60000 NO           1                       

13 rows selected.

--QUERY 5
SQL> SELECT EMP_NAME "NAME" , SALARY
  2  FROM EMPLOYEE_20
  3  WHERE SALARY>( SELECT MIN(SALARY) FROM EMPLOYEE_20 WHERE DEPT_NO = 2);

NAME                SALARY                                                      
--------------- ----------                                                      
Aniket              130000                                                      
Abhishek            130000                                                      
Ayush              3000000                                                      
Anuj                180000                                                      
Archit              140000                                                      
Ananya              175000                                                      
Anshal              200000                                                      

7 rows selected.

--QUERY 6
SQL> SELECT EMP_NAME "NAME" , SALARY
  2  FROM EMPLOYEE_20
  3  WHERE SALARY>( SELECT AVG(SALARY) FROM EMPLOYEE_20 WHERE DEPT_NO = 4);

NAME                SALARY                                                      
--------------- ----------                                                      
Amit                100000                                                      
Aniket              130000                                                      
Ankita Thakur       100000                                                      
Abhishek            130000                                                      
Ayush              3000000                                                      
Akansha Sharma      100000                                                      
Anuj                180000                                                      
Archit              140000                                                      
Ananya              175000                                                      
Anshal              200000                                                      

10 rows selected.
--QUERY 7
SQL> SELECT * FROM DEPARTMENT WHERE DEPTT_NO =ANY (SELECT DEPT_NO FROM EMPLOYEE_20 WHERE EMP_ID = 'E006');

  DEPTT_NO DEPTT_NAME DEPTT_LOCATION                                            
---------- ---------- ---------------                                           
         2 Research   Mumbai                                                    

--QUERY 8
SQL> SELECT * FROM EMPLOYEE_20 WHERE DEPT_NO = ANY (SELECT DEPTT_NO FROM DEPARTMENT WHERE DEPTT_NAME = 'Finance');

EMP_ EMP_NAME        JOB            SALARY MAN    DEPT_NO                       
---- --------------- ---------- ---------- --- ----------                       
E012 Ankita Thakur   MANAGER        100000 YES          1                       
E014 Anshal          HR             200000 YES          1                       
E007 Amrit           WORKER          60000 NO           1                       

--QUERY 9
SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20 WHERE JOB = (SELECT JOB FROM EMPLOYEE_20 WHERE EMP_ID = 'E008');

NAME                                                                            
---------------                                                                 
Aniket                                                                          
Anuj                                                                            
Ananya                                                                          
Anshal  
                                                                        
--QUERY 10
SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20 WHERE JOB = (SELECT JOB FROM EMPLOYEE_20 WHERE EMP_ID = 'E012') AND SALARY>(SELECT SALARY FROM EMPLOYEE_20 WHERE EMP_ID='E012');

NAME                                                                            
---------------                                                                 
Abhishek                                                                        
Archit

--QUERY 11
SQL> SELECT EMP_NAME "NAME",SALARY FROM EMPLOYEE_20 E1
  2  WHERE SALARY> ALL (SELECT SALARY FROM EMPLOYEE_20
  3  WHERE DEPT_NO = (SELECT DEPTT_NO FROM DEPARTMENT WHERE DEPTT_NAME = 'Research'));

NAME                SALARY                                                      
--------------- ----------                                                      
Anuj                180000                                                      
Anshal              200000                                                      
Ayush              3000000                                                      

--QUERY 12
SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20 E1
  2  WHERE MANAGERID = 'NO';

NAME                                                                            
---------------                                                                 
Amit                                                                            
Ashish                                                                          
Amrit                                                                           

SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20 E1
  2  WHERE EMP_NAME = ANY ( SELECT EMP_NAME FROM EMPLOYEE_20 WHERE MANAGERID = 'NO');

NAME                                                                            
---------------                                                                 
Amit                                                                            
Ashish                                                                          
Amrit                                                                           


SQL> SELECT * FROM EMPLOYEE_20;

EMP_ EMP_NAME        JOB            SALARY MAN    DEPT_NO                       
---- --------------- ---------- ---------- --- ----------                       
E006 Amit            WORKER         100000 NO           2                       
E018 Ashish          WORKER          40000 NO           3                       
E010 Aniket          HR             130000 YES          4                       
E003 Akansha Jha     WORKER          20000 YNO          4                       
E012 Ankita Thakur   MANAGER        100000 YES          1                       
E001 Abhishek        MANAGER        130000 YES          2                       
E029 Ayush                         3000000                                      
E004 Akansha Sharma  MANAGER        100000 YES          4                       
E015 Anuj            HR             180000 YES          3                       
E016 Archit          MANAGER        140000 YES          3                       
E008 Ananya          HR             175000 YES          2                       

EMP_ EMP_NAME        JOB            SALARY MAN    DEPT_NO                       
---- --------------- ---------- ---------- --- ----------                       
E014 Anshal          HR             200000 YES          1                       
E007 Amrit           WORKER          60000 NO           1                       

13 rows selected.

--QUERY 14
SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20
  2  WHERE SALARY > (SELECT MIN(SALARY) FROM EMPLOYEE_20 WHERE DEPT_NO = 4)
  3  AND
  4  DEPT_NO <> 4;

NAME                                                                            
---------------                                                                 
Amit                                                                            
Ashish                                                                          
Ankita Thakur                                                                   
Abhishek                                                                        
Anuj                                                                            
Archit                                                                          
Ananya                                                                          
Anshal                                                                          
Amrit                                                                           

9 rows selected.

SQL> SELECT EMP_NAME "NAME" FROM EMPLOYEE_20
  2  WHERE SALARY < (SELECT MIN(SALARY) FROM EMPLOYEE_20 WHERE DEPT_NO = 4)
  3  AND
  4  DEPT_NO <> 4;

no rows selected                                                                         

--QUERY 15
SQL> SELECT EMP_NAME "NAME",SALARY "HIGHEST SALARY" FROM EMPLOYEE_20
  2  WHERE SALARY >= ALL (SELECT SALARY FROM EMPLOYEE_20);

NAME            HIGHEST SALARY                                                  
--------------- --------------                                                  
Ayush                  3000000                                                  

--QUERY 16
SQL> SELECT EMP_NAME "NAME",SALARY "LOWEST SALARY" FROM EMPLOYEE_20
  2  WHERE SALARY <= ALL (SELECT SALARY FROM EMPLOYEE_20);

NAME            LOWEST SALARY                                                   
--------------- -------------                                                   
Akansha Jha             20000                                                   

SQL> SPOOL OFF;

SELECT EMP_NAME FROM EMPLOYEE_20 ORDER BY EMP_NAME LIMIT 4;