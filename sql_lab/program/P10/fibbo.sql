DECLARE
    NUM_1 NUMBER:= 0;
    NUM_2 NUMBER:= 1;
    NUM_3 NUMBER;
    INP NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter number till which you want fibonacci series: ');
    INP := &INP;
    DBMS_OUTPUT.PUT(NUM_1 ||' '|| NUM_2 || ' ');
    LOOP
        NUM_3 := NUM_1 + NUM_2;
        EXIT WHEN NUM_3 > INP;
        DBMS_OUTPUT.PUT(NUM_3 || ' ');
        NUM_1 := NUM_2;
        NUM_2 := NUM_3;
    END LOOP;
    DBMS_OUTPUT.NEW_LINE();
END;