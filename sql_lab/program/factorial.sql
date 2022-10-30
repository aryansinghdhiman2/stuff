DECLARE
    INP NUMBER(1);
    FAC NUMBER(6);
    I NUMBER(1);
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter number for which you want factorial: ');
    INP:=&INP;
    FAC := 1;
    FOR I IN 1 .. INP
    LOOP
        FAC := FAC * I;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Factorial is : ' || FAC);
END;