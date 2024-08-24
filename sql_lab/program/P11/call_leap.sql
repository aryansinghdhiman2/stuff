DECLARE
    INP NUMBER(4);
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter YEAR: ');
    INP := :INP;
    is_leap(INP);
END;