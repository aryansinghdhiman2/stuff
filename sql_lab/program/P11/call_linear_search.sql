DECLARE
    INPUT NUM_VARRAY;
    TO_FIND NUMBER;
    RES NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter array: ');
    INPUT := NUM_VARRAY(&LIST);
    DBMS_OUTPUT.PUT_LINE(A  => 'Enter number to be found: ');
    TO_FIND := &TO_FIND;

    LINEAR_SEARCH(INPUT,TO_FIND,RES);

    IF RES = -1 THEN DBMS_OUTPUT.PUT_LINE('NOT FOUND');
    ELSE
        DBMS_OUTPUT.PUT_LINE('FOUND AT ' || RES);
    END IF;
END;