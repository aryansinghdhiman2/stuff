DECLARE
    INP NUMBER;
    FAC NUMBER;
    I NUMBER;
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