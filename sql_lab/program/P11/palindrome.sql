CREATE OR REPLACE PROCEDURE PALINDRO(INP VARCHAR2) AS
    REV VARCHAR2(10);
BEGIN
    REV := UTL_RAW.CAST_TO_VARCHAR2( UTL_RAW.REVERSE( UTL_RAW.CAST_TO_RAW(INP)));
    IF INP = REV THEN DBMS_OUTPUT.PUT_LINE('String is Palindrome');
    ELSE DBMS_OUTPUT.PUT_LINE('String is NOT Palindrome');
    END IF;
END;
        

