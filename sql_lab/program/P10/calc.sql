DECLARE
    NUM_1 NUMBER;
    NUM_2 NUMBER;
    INP NUMBER(1);
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter first number: ');
    NUM_1 := &NUM_1;
    DBMS_OUTPUT.PUT_LINE('Enter second number: ');
    NUM_2 := &NUM_2;
    DBMS_OUTPUT.PUT_LINE('Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division');
    INP := &INP;

    CASE INP
        WHEN 1 THEN DBMS_OUTPUT.PUT_LINE('Addition: '|| (NUM_1+NUM_2));
        WHEN 2 THEN DBMS_OUTPUT.PUT_LINE('Subtraction: '|| (NUM_1-NUM_2));
        WHEN 3 THEN DBMS_OUTPUT.PUT_LINE('Multiplication: '|| (NUM_1*NUM_2));
        WHEN 4 THEN DBMS_OUTPUT.PUT_LINE('Division: '|| (NUM_1/NUM_2));
    END CASE;
END;