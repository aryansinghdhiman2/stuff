DECLARE
    INP NUMBER;
    I NUMBER;
    REMAIN NUMBER;

BEGIN
    -- DBMS_OUTPUT.PUT_LINE('Enter Number you want checked: ');
    INP := &INP;

    IF INP <= 1 THEN 
        DBMS_OUTPUT.PUT_LINE('Number should be greater than 1');
    ELSE
        -- DBMS_OUTPUT.PUT_LINE('ENTERED LOOP');
        I := 2;
        WHILE I < INP
        LOOP
            REMAIN := MOD(INP , I);
            -- DBMS_OUTPUT.PUT_LINE('CALCULATED REMAIN : '||REMAIN);
            EXIT WHEN REMAIN = 0;
            -- DBMS_OUTPUT.PUT_LINE('CONDITION CHECK');
            I := I + 1;
            -- DBMS_OUTPUT.PUT_LINE('I INCREMENT '|| I);
        END LOOP;

        -- DBMS_OUTPUT.PUT_LINE(INP || ' ' || REMAIN || ' ' || I);
        IF REMAIN <> 0 OR INP = 2 THEN
            DBMS_OUTPUT.PUT_LINE(INP||' is prime');
        ELSE
            DBMS_OUTPUT.PUT_LINE(INP||' is not prime');
        END IF;
    END IF;
END;

