LXI SP,20FFH;//ANAVI BIRTHDAY 20/10/03
MVI B,14H; //20, digits of birth day 
MVI A,16H; //22, digits of current day
SUB B;//number of days between birth day and today
STA 2000H;//[2000H] = 2
MVI B,0AH;// birth month
MVI A,0BH;// current month
SUB B;//number of months between birth month and current month
STA 2001H;//[2001H] = 1
MVI B,03H;//last digit of birth year
MVI A,16H;//last digits of current year
SUB B;//number of years between today and birthday
STA 2002H;/[2002h] = 19
CALL DAYS;
SHLD 3000H;//store result at 3000H
HLT;
DAYS: LDA 2002H;//load number of years into accumulator
MOV D,A;//use number of years as loop counter
LXI B,016DH;//BE=365
LXI H,0000H;//HL = 0
LOOP1: DAD B;//add 365 days for each year
DCR D;//decrement loop counter
JNZ LOOP1;
PUSH H;//push hl onto stack
LDA 2001H;//load number of months into accumulator
MOV D,A;//use number of months as loop counter
LXI B, 001EH;//BE=31
LXI H, 0000H;//HL=0
LOOP2: DAD B;//add 31 days for each month
DCR D;// decrement counter
JNZ LOOP2;
LXI D,0000H;//DE = 0000H
XCHG;// HL <-> DE
POP H;//Pop HL off stack ,HL = number of days between years
DAD D;//HL = HL + DE ,add both pairs of days
PUSH H;//push H onto stack
LDA 2000H;//load number of days
MVI H,00H;//zero H
MOV L,A;//move number
LXI D,0000H;//DE = 0000H
XCHG;//Exchange DE and HL
POP H;//pop HL off stack
DAD D;//add remaining days
RET;//return