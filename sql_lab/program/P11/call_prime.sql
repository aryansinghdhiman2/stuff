DECLARE 
    INPUT NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter number you want checked: ');
    INPUT :=:INPUT;
    PRIME_FOR(INPUT);
    PRIME_WHILE(INPUT);
END;