CREATE OR REPLACE PROCEDURE B_SORT (INPUT IN OUT NUM_VARRAY)
AS
    I NUMBER;
    J NUMBER;
BEGIN
    FOR I IN 1 .. INPUT.COUNT LOOP
        FOR J IN 1 .. (INPUT.COUNT-1) LOOP
            IF INPUT(J)>INPUT(J+1)
                THEN REPLACE_NUM(INPUT(J),INPUT(J+1));
            ELSE
                NULL;
            END IF;
        END LOOP;
    END LOOP;
END;
