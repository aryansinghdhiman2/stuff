CREATE OR REPLACE PROCEDURE is_leap (YEAR IN NUMBER)  
IS
BEGIN
IF MOD(YEAR,4)=0 THEN 
    DBMS_OUTPUT.PUT_LINE('Year '||YEAR||' is leap year');
ELSE 
    DBMS_OUTPUT.PUT_LINE('Year '||YEAR||' is not leap year');
END IF;
END IS_LEAP;