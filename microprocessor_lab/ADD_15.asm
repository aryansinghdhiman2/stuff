MVI E,0FH
LXI H,2000H
MVI A,00H
LOOP:MOV B,M
ADD B
INX H
DCR E
JNZ LOOP
HLT