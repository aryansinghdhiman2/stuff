DECLARE 
    RADIUS NUMBER;
    INP NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter Radius:');
    RADIUS := :RADIUS;

    DBMS_OUTPUT.PUT_LINE('Enter 1 if you want circumference else enter 2 if you want area:');
    INP:=:INP;

    AREA_CIRC(RADIUS,INP);
END;