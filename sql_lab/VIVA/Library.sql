CREATE TABLE BOOKS (BOOK_ID NUMBER,BOOK_NAME VARCHAR(30) CONSTRAINT BOOKS_BOOK_NAME_NN NOT NULL,AUTHOR VARCHAR(10),AMOUNT NUMBER,
                    CONSTRAINT BOOKS_BOOK_ID_PK PRIMARY KEY(BOOK_ID,AUTHOR)
);

ALTER TABLE BOOKS MODIFY (BOOK_ID CONSTRAINT BOOKS_ID_UQ UNIQUE);

ALTER TABLE BOOKS MODIFY (AUTHOR VARCHAR(15));

CREATE TABLE STUDENTS (STUDENT_ID NUMBER,STUDENT_NAME VARCHAR(10) CONSTRAINT STUDENTS_STUDENT_NAME_NN NOT NULL,
                        CONSTRAINT STUDENT_ID_PK PRIMARY KEY(STUDENT_ID)
);

ALTER TABLE STUDENTS MODIFY (STUDENT_NAME VARCHAR(25));

CREATE TABLE BOOKS_LENT (B_ID NUMBER REFERENCES BOOKS(BOOK_ID),S_ID NUMBER REFERENCES STUDENTS(STUDENT_ID));

CREATE VIEW BORROWED_VIEW AS 
        SELECT S.STUDENT_ID,S.STUDENT_NAME,B.BOOK_ID,B.BOOK_NAME,B.AUTHOR 
        FROM STUDENTS S,BOOKS B,BOOKS_LENT L
        WHERE S.STUDENT_ID = L.S_ID AND B.BOOK_ID = L.B_ID;
-- CREATE OR REPLACE PACKAGE LIBRARY AS 
DROP VIEW BORROWED_VIEW;


CREATE SEQUENCE BOOK_SEQ 
START WITH 1
INCREMENT BY 1
ORDER
NOCYCLE

DROP SEQUENCE BOOK_SEQ;

CREATE SEQUENCE STU_SEQ
START WITH 1
INCREMENT BY 1
ORDER
NOCYCLE

CREATE OR REPLACE TRIGGER CAPITALIZE
        BEFORE
        INSERT OR UPDATE ON BOOKS
        FOR EACH ROW
        BEGIN
        :NEW.BOOK_NAME := UPPER(:NEW.BOOK_NAME);
        :NEW.AUTHOR := UPPER(:NEW.AUTHOR);
END CAPITALIZE;

CREATE TABLE AUDIT_TABLE_B(ID NUMBER,ACTION VARCHAR(7),TIME_STAMP TIMESTAMP);

CREATE OR REPLACE TRIGGER AUDIT_BOOK
        AFTER
        INSERT OR UPDATE OR DELETE ON BOOKS
        FOR EACH ROW
        BEGIN
        IF INSERTING THEN INSERT INTO AUDIT_TABLE_B VALUES(:NEW.BOOK_ID,'INSERT',SYSTIMESTAMP);
        ELSIF UPDATING THEN INSERT INTO AUDIT_TABLE_B VALUES(:NEW.BOOK_ID,'UPDATE',SYSTIMESTAMP);
        ELSIF DELETING THEN INSERT INTO AUDIT_TABLE_B VALUES(:OLD.BOOK_ID,'DELETE',SYSTIMESTAMP);
        END IF;
END AUDIT_BOOK;
ALTER TRIGGER CAPITALIZE ENABLE;

INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'DBMS','Korth',15);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'DATA STRUCTURES','CORMEN',20);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'Microprocessor','Gaonkar',15);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'Discrete mathematics','Schaum',16);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'economics','Jain',10);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'cpp','balaguswamy',25);
INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,'c lan','balaguswamy',5);
DELETE FROM BOOKS;
-- SELECT * FROM BOOKS;

INSERT INTO STUDENTS VALUES(STU_SEQ.NEXTVAL,'Aryan Singh Dhiman');
INSERT INTO STUDENTS VALUES(STU_SEQ.NEXTVAL,'Aryan Raj');
INSERT INTO STUDENTS VALUES(STU_SEQ.NEXTVAL,'Ayush Gautam');

INSERT INTO BOOKS_LENT VALUES(8,1);
INSERT INTO BOOKS_LENT VALUES(8,2);
INSERT INTO BOOKS_LENT VALUES(9,2);
DELETE FROM BOOKS_LENT;
SELECT * FROM BORROWED_VIEW;

CREATE INDEX B_IDX ON BOOKS(BOOK_NAME);





CREATE OR REPLACE PACKAGE LIBRARY_B AS
PROCEDURE INSERT_BOOK(BOOK_NAME IN VARCHAR,AUTHOR IN VARCHAR,AMOUNT IN NUMBER);
PROCEDURE INSERT_STUDENT(STUDENT_NAME IN VARCHAR);
PROCEDURE BORROW(BOOK_ID IN NUMBER,STU_ID IN NUMBER);
FUNCTION CAN_BORROW(STU_ID IN NUMBER) RETURN BOOLEAN;
PROCEDURE RETURN_BOOK(B_ID IN NUMBER);
PROCEDURE REMOVE_BOOK(B_ID IN NUMBER);
PROCEDURE REMOVE_STUDENT(S_ID IN NUMBER);
FUNCTION CHECK_AMOUNT(B_ID IN NUMBER) RETURN BOOLEAN;
PROCEDURE DECREASE_AMOUNT(B_ID IN NUMBER);
PROCEDURE INCREASE_AMOUNT(B_ID IN NUMBER);
PROCEDURE NUM_OF_BOOKS_BY_AUTHOR;
PROCEDURE ALL_BORROWED;
END LIBRARY_B;
/

DROP PACKAGE BODY LIBRARY_B;
/
CREATE OR REPLACE PACKAGE BODY LIBRARY_B AS
PROCEDURE INSERT_BOOK(BOOK_NAME IN VARCHAR,AUTHOR IN VARCHAR,AMOUNT IN NUMBER)
        AS
        BEGIN
        INSERT INTO BOOKS VALUES(BOOK_SEQ.NEXTVAL,BOOK_NAME,AUTHOR,AMOUNT);
END INSERT_BOOK;
PROCEDURE INSERT_STUDENT(STUDENT_NAME IN VARCHAR)
        AS
        BEGIN
        INSERT INTO STUDENTS VALUES(STU_SEQ.NEXTVAL,STUDENT_NAME);
END INSERT_STUDENT;
PROCEDURE BORROW(BOOK_ID IN NUMBER,STU_ID IN NUMBER)
        AS
        BEGIN
        IF LIBRARY_B.CHECK_AMOUNT(BOOK_ID) THEN
                IF LIBRARY_B.CAN_BORROW(STU_ID) THEN 
                        INSERT INTO BOOKS_LENT VALUES(BOOK_ID,STU_ID);
                        LIBRARY_B.DECREASE_AMOUNT(BOOK_ID);
                END IF;
        END IF;
END BORROW; 
FUNCTION CAN_BORROW(STU_ID IN NUMBER) RETURN BOOLEAN
        AS
        CT NUMBER;
        BEGIN
        SELECT COUNT(*) INTO CT FROM BOOKS_LENT WHERE S_ID = STU_ID;
        IF CT >=4 THEN RETURN FALSE;
        END IF;
        RETURN TRUE;
END CAN_BORROW;
PROCEDURE RETURN_BOOK(B_ID IN NUMBER)
        AS
        BEGIN
        DELETE FROM BOOKS_LENT L WHERE L.B_ID = B_ID;
        LIBRARY_B.INCREASE_AMOUNT(B_ID);
END RETURN_BOOK;
PROCEDURE REMOVE_BOOK(B_ID IN NUMBER)
        AS
        BEGIN
        DELETE FROM BOOKS WHERE BOOK_ID = B_ID;
        LIBRARY_B.INCREASE_AMOUNT(B_ID);
END REMOVE_BOOK;
PROCEDURE REMOVE_STUDENT(S_ID IN NUMBER)
        AS
        BEGIN
        DELETE FROM STUDENTS WHERE S_ID = STUDENT_ID;
END REMOVE_STUDENT;
PROCEDURE NUM_OF_BOOKS_BY_AUTHOR
        AS
        CURSOR CUR IS SELECT AUTHOR,COUNT(BOOK_ID) "CNT" FROM BOOKS GROUP BY AUTHOR ORDER BY COUNT(BOOK_ID) DESC;
        RES CUR%ROWTYPE;
        BEGIN
        OPEN CUR;
        LOOP
        FETCH CUR INTO RES;
        EXIT WHEN CUR%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(RES.AUTHOR ||' '||RES.CNT);
        EXIT WHEN CUR%NOTFOUND;
        END LOOP;
        CLOSE CUR;
END NUM_OF_BOOKS_BY_AUTHOR;
PROCEDURE ALL_BORROWED
        AS
        CURSOR CR IS SELECT * FROM BORROWED_VIEW;
        RES CR%ROWTYPE;
        BEGIN
        OPEN CR;
        LOOP
        FETCH CR INTO RES;
        EXIT WHEN CR%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(RES.STUDENT_ID || ' ' || RES.STUDENT_NAME || ' ' || RES.BOOK_ID || ' ' || RES.BOOK_NAME || RES.AUTHOR);
        END LOOP;
        CLOSE CR;
END ALL_BORROWED;
FUNCTION CHECK_AMOUNT(B_ID IN NUMBER) RETURN BOOLEAN 
        AS
        AM NUMBER;
        BEGIN
        SELECT AMOUNT INTO AM FROM BOOKS WHERE BOOKS.BOOK_ID = B_ID;
        IF AM > 0 THEN RETURN TRUE;
        ELSE RETURN FALSE;
        END IF;
        END CHECK_AMOUNT;
PROCEDURE DECREASE_AMOUNT(B_ID IN NUMBER)
        AS
        AM NUMBER;
        BEGIN
        IF(CHECK_AMOUNT(B_ID)) THEN
                SELECT AMOUNT INTO AM FROM BOOKS WHERE BOOKS.BOOK_ID = B_ID; 
                UPDATE BOOKS SET AMOUNT = (AM-1) WHERE BOOKS.BOOK_ID = B_ID;
        END IF;
        END;
PROCEDURE INCREASE_AMOUNT(B_ID IN NUMBER)
        AS
        AM NUMBER;
        BEGIN
        SELECT AMOUNT INTO AM FROM BOOKS WHERE BOOKS.BOOK_ID = B_ID; 
        UPDATE BOOKS SET AMOUNT = (AM+1) WHERE BOOKS.BOOK_ID = B_ID;
        END;
END;

-- BEGIN
EXEC LIBRARY_B.ALL_BORROWED;
-- END;

-- DROP PACKAGE LIBRARY;