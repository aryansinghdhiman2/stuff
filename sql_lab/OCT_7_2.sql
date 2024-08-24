SQL> CREATE VIEW STU_V AS
  2  SELECT RNO,NAME,DEPT
  3  FROM STUDENT_20;

View created.

SQL> SELECT * FROM STU_V;

RNO        NAME                 DEPT                                            
---------- -------------------- -----                                           
UE213020   Aryan Singh Dhiman   CSE                                             
UE213019   Aryan Raj            CSE                                             
UE999999   REAL_NAME            CSE                                             
UE213089   ANOTHER_NAME         BIO                                             
UE213060   HIMANSHU KAUSHAL     CSE                                             

SQL> INSERT INTO STU_V VALUES('UE212121','Arjun','EEE');

1 row created.

SQL> UPDATE STU_V
  2  SET DEPT = 'IT'
  3  WHERE RNO = 'UE212121';

1 row updated.

SQL> SELECT * FROM STU_V;

RNO        NAME                 DEPT                                            
---------- -------------------- -----                                           
UE213020   Aryan Singh Dhiman   CSE                                             
UE213019   Aryan Raj            CSE                                             
UE999999   REAL_NAME            CSE                                             
UE212121   Arjun                IT                                              
UE213089   ANOTHER_NAME         BIO                                             
UE213060   HIMANSHU KAUSHAL     CSE                                             

6 rows selected.


SQL> SET LINESIZE 200;
SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                                                                                                                      
---------- -------------------- ----- ---------- --------- --------------------------------------------------                                                                                           
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                                                                                                   
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                                                                                                      
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE212121   Arjun                IT                                                                                                                                                                      
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               

6 rows selected.

SQL> DELETE FROM STU_V
  2  WHERE RNO = 'UE212121';

1 row deleted.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                                                                                                                      
---------- -------------------- ----- ---------- --------- --------------------------------------------------                                                                                           
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                                                                                                   
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                                                                                                      
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               

SQL> SELECT * FROM STU_V;

RNO        NAME                 DEPT                                                                                                                                                                    
---------- -------------------- -----                                                                                                                                                                   
UE213020   Aryan Singh Dhiman   CSE                                                                                                                                                                     
UE213019   Aryan Raj            CSE                                                                                                                                                                     
UE999999   REAL_NAME            CSE                                                                                                                                                                     
UE213089   ANOTHER_NAME         BIO                                                                                                                                                                     
UE213060   HIMANSHU KAUSHAL     CSE                                                                                                                                                                     

SQL> CREATE INDEX STU_IDX
  2  ON STUDENT_20(RNO);
ON STUDENT_20(RNO)
              *
ERROR at line 2:
ORA-01408: such column list already indexed 


SQL> SPOOL OFF;
