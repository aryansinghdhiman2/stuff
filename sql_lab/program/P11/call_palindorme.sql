DECLARE
    INPUT VARCHAR2(10);
BEGIN
    DBMS_OUTPUT.PUT_LINE('ENTER STRING FOR CHECKING PALINDROME');
    INPUT:=:INPUT;
    PALINDRO(INPUT);
END;