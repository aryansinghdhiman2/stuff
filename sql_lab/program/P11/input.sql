DECLARE
X NUMBER(2);
BEGIN
X:=&X;
DBMS_OUTPUT.PUT_LINE('The number you entered is:'|| X);
END;