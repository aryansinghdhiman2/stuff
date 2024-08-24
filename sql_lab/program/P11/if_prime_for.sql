CREATE OR REPLACE PROCEDURE PRIME_FOR (INP IN NUMBER)
AS
    I NUMBER;
    REMAIN NUMBER;
BEGIN
    IF INP <= 1 THEN 
        DBMS_OUTPUT.PUT_LINE('Number should be greater than 1');
    ELSE
        I := 2;
        FOR  I IN 2 .. (INP-1)
        LOOP
            REMAIN := MOD(INP , I);
            EXIT WHEN REMAIN = 0;
        END LOOP;

        IF REMAIN <> 0 OR INP = 2 THEN
            DBMS_OUTPUT.PUT_LINE(INP||' is prime');
        ELSE
            DBMS_OUTPUT.PUT_LINE(INP||' is not prime');
        END IF;
    END IF;
END PRIME_FOR;

