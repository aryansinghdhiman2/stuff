MVI D,00H
LXI H,0010H
MOV A,M
NEXT: INX H
CMP M
JZ LOOP
JNC LOOP
MOV A,M
LOOP: INR D
MOV E,A
MOV A,D
CPI 04H
MOV A,E
JZ STORE
JMP NEXT

STORE: INX H
MOV M,A
HLT