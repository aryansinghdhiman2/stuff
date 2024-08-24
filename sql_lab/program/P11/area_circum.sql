CREATE OR REPLACE PROCEDURE area_circ (RADIUS IN NUMBER, INP IN NUMBER)
IS
PI NUMBER(3,2):=3.14;
BEGIN

CASE INP
    WHEN 1 THEN DBMS_OUTPUT.PUT_LINE('Circumference is: '||((2*PI)*(RADIUS)));
    WHEN 2 THEN DBMS_OUTPUT.PUT_LINE('Area is: '||(PI*(RADIUS**2)));
    ELSE DBMS_OUTPUT.PUT_LINE('Invalid Option');
    END CASE;

END;