DECLARE
num_of_rows NUMBER(3);
CURSOR curs IS SELECT * FROM EMPLOYEE_20;
temp curs%ROWTYPE;
BEGIN
OPEN curs;
LOOP
FETCH curs INTO temp;
EXIT WHEN curs%NOTFOUND;
END LOOP;
num_of_rows :=curs%ROWCOUNT;
-- SELECT * INTO temp FROM STUDENT_20;
-- num_of_rows :=SQL%ROWCOUNT;
DBMS_OUTPUT.PUT_LINE('Number of rows in EMPLOYEE_20 are : ' || num_of_rows);
CLOSE curs;
END;