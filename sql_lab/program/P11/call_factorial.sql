DECLARE 
    INPUT NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter number for which you want factorial: ');
    INPUT:=&INPUT;
    FACTO(INPUT);
END;