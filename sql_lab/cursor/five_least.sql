DECLARE
CURSOR CUR IS SELECT * FROM EMPLOYEE_20 ORDER BY EMPLOYEE_20.SALARY ASC;
RES CUR%ROWTYPE;
BEGIN
OPEN CUR;
FOR I IN 1 .. 5
LOOP
FETCH CUR INTO RES;
DBMS_OUTPUT.PUT_LINE(RES.EMP_ID||' '||RES.EMP_NAME||' '||RES.JOB||' '||RES.SALARY||' '||RES.MANAGERID||' '||RES.DEPT_NO);
END LOOP;
CLOSE CUR;
END;