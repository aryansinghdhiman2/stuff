//INDEX
SQL> CREATE INDEX STU_IDX ON
  2  STUDENT_20(NAME);

Index created.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                                                                                                                      
---------- -------------------- ----- ---------- --------- --------------------------------------------------                                                                                           
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                                                                                                   
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                                                                                                      
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               


SQL> INSERT INTO STUDENT_20 COLUMNS(RNO,NAME,ADDRESS) VALUES('UE212121','REAL_NAME','DELHI');

1 row created.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                                                                                                                      
---------- -------------------- ----- ---------- --------- --------------------------------------------------                                                                                           
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                                                                                                   
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                                                                                                      
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               
UE212121   REAL_NAME            CSE                        DELHI                                                                                                                                        

6 rows selected.

SQL> DELETE FROM STUDENT_20 WHERE RNO = 'UE212121';

1 row deleted.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                                                                                                                      
---------- -------------------- ----- ---------- --------- --------------------------------------------------                                                                                           
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                                                                                                   
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                                                                                                      
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               

SQL> DROP INDEX STU_IDX;

Index dropped.

SQL> CREATE UNIQUE INDEX STU_IDX ON
  2  STUDENT_20(NAME);

Index created.

SQL> INSERT INTO STUDENT_20 COLUMNS(RNO,NAME,ADDRESS) VALUES('UE212121','REAL_NAME','DELHI');
INSERT INTO STUDENT_20 COLUMNS(RNO,NAME,ADDRESS) VALUES('UE212121','REAL_NAME','DELHI')
*
ERROR at line 1:
ORA-00001: unique constraint (SYS.STU_IDX) violated 


//SEQUENCE
SQL> ALTER TABLE STUDENT_20 ADD (STU_INDEX NUMBER(3));

Table altered.

SQL> CREATE SEQUENCE STU_SEQ
  2  INCREMENT BY 1
  3  START WITH 1
  4  MAXVALUE 100
  5  NOCYCLE
  6  NOCACHE
  7  ORDER;

Sequence created.

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.CURRVAL WHERE RNO = 'UE213020';
UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.CURRVAL WHERE RNO = 'UE213020'
                                   *
ERROR at line 1:
ORA-08002: sequence STU_SEQ.CURRVAL is not yet defined in this session 


SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.NEXTVAL WHERE RNO = 'UE213020';

1 row updated.

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.NEXTVAL WHERE RNO = 'UE213019';

1 row updated.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                             STU_INDEX                                                                                
---------- -------------------- ----- ---------- --------- -------------------------------------------------- ----------                                                                                
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                  1                                                                                
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                     2                                                                                
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                                                                                                        
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.CURRVAL WHERE RNO = 'UE999999';

1 row updated.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                             STU_INDEX                                                                                
---------- -------------------- ----- ---------- --------- -------------------------------------------------- ----------                                                                                
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                  1                                                                                
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                     2                                                                                
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                       2                                                                                
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                                                                                                       
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                                                                                                               

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.NEXTVAL WHERE RNO = 'UE999999';

1 row updated.

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.NEXTVAL WHERE RNO = 'UE213089';

1 row updated.

SQL> UPDATE STUDENT_20  SET STU_INDEX = STU_SEQ.NEXTVAL WHERE RNO = 'UE213060';

1 row updated.

SQL> SELECT * FROM STUDENT_20;

RNO        NAME                 DEPT      MOB_NO DOB       ADDRESS                                             STU_INDEX                                                                                
---------- -------------------- ----- ---------- --------- -------------------------------------------------- ----------                                                                                
UE213020   Aryan Singh Dhiman   CSE   9779906441 01-FEB-03 CHANDIGARH                                                  1                                                                                
UE213019   Aryan Raj            CSE   7355285828 27-MAR-02 LUCKNOW                                                     2                                                                                
UE999999   REAL_NAME            CSE   9999999999 01-JAN-03 DELHI                                                       3                                                                                
UE213089   ANOTHER_NAME         BIO   8888888888 31-DEC-03 MUMBAI                                                      4                                                                                
UE213060   HIMANSHU KAUSHAL     CSE   8427916557 09-NOV-03 ANANDPUR SAHIB                                              5                                                                                

SQL> ALTER SEQUENCE STU_SEQ CACHE 10;

Sequence altered.

SQL> SPOOL OFF;

SQL> DROP SEQUENCE STU_SEQ;

Sequence dropped.