DECLARE
    TYPE NUM_ARRAY IS VARRAY(10) OF NUMBER;
    INPUT NUM_ARRAY;
    I NUMBER;
    J NUMBER;
    TEMP NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('ENTER ARRAY: ');
    INPUT:= NUM_ARRAY(&ARRAY);
    FOR I IN 1 .. INPUT.COUNT LOOP
        FOR J IN 1 .. (INPUT.COUNT-1) LOOP
            IF INPUT(J)>INPUT(J+1)
                THEN 
                    TEMP := INPUT(J);
                    INPUT(J) := INPUT(J+1);
                    INPUT(J+1) := TEMP;
            ELSE
                NULL;
            END IF;
        END LOOP;
    END LOOP;

    FOR I IN 1 .. INPUT.COUNT LOOP
        DBMS_OUTPUT.PUT(INPUT(I) || ', ');
    END LOOP;
    DBMS_OUTPUT.NEW_LINE();
END;
