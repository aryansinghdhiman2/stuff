DECLARE
RADIUS NUMBER;
INP NUMBER(1);
PI NUMBER(3,2):=3.14;
BEGIN
DBMS_OUTPUT.PUT_LINE('Enter Radius:');
RADIUS := :RADIUS;

DBMS_OUTPUT.PUT_LINE('Enter 1 if you want circumference else enter 2 if you want area:');
INP:=:INP;

CASE INP
    WHEN 1 THEN DBMS_OUTPUT.PUT_LINE('Circumference is: '||((2*PI)*(RADIUS)));
    WHEN 2 THEN DBMS_OUTPUT.PUT_LINE('Area is: '||(PI*(RADIUS**2)));
    ELSE DBMS_OUTPUT.PUT_LINE('Invalid Option');
    END CASE;

END;