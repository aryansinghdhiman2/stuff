--query 1
SQL> SELECT DEPT_NO "DEPARTMENT NO",SUM(SALARY) "Sum of Salary" FROM EMPLOYEE_20 GROUP BY DEPT_NO ORDER BY DEPT_NO;

DEPARTMENT NO Sum of Salary
------------- -------------
            1        360000
            2        405000
            3        360000
            4        250000  
					 3000000
					 
SQL> SELECT JOB "JOB",AVG(SALARY) "Average Salary" FROM EMPLOYEE_20 GROUP BY JOB ORDER BY JOB;

JOB        Average Salary
---------- --------------
HR                 171250
MANAGER            117500
WORKER              55000
                  3000000  	 
				
--query 3
SELECT DEPT_NO "DEPARTMENT",JOB "JOB",AVG(SALARY) "Average Salary" FROM EMPLOYEE_20 GROUP BY JOB,DEPT_NO ORDER BY DEPT_NO;

DEPARTMENT JOB        Average Salary
---------- ---------- --------------
         1 HR                 200000
         1 MANAGER            100000
         1 WORKER              60000
         2 HR                 175000
         2 MANAGER            130000
         2 WORKER             100000
         3 HR                 180000
         3 MANAGER            140000
         3 WORKER              40000
         4 HR                 130000
         4 MANAGER            100000

DEPARTMENT JOB        Average Salary
---------- ---------- --------------
         4 WORKER              20000
                             3000000

13 rows selected.

--QUERY 4

SQL> SELECT JOB,SUM(SALARY) "TOTAL",MIN(SALARY) "MINIMUM",MAX(SALARY) "MAXIMUM",AVG(SALARY) "AVERAGE" FROM EMPLOYEE_20 WHERE DEPT_NO = 1 OR DEPT_NO = 2 HAVING AVG(SALARY)>100000 GROUP BY JOB;

JOB             TOTAL    MINIMUM    MAXIMUM    AVERAGE
---------- ---------- ---------- ---------- ----------
MANAGER        230000     100000     130000     115000
HR             375000     175000     200000     187500 

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