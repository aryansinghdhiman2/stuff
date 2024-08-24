DECLARE
    NUM_1 NUMBER;
    NUM_2 NUMBER;
    INP NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter first number: ');
    NUM_1 := :NUM_1;
    DBMS_OUTPUT.PUT_LINE('Enter second number: ');
    NUM_2 := :NUM_2;
    DBMS_OUTPUT.PUT_LINE('Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division');
    INP := :INP;

    CALC(NUM_1,NUM_2,INP);
END;