LXI H,2000H
MOV E,M
LXI H,3000H
LXI B,4000H
LOOP:MOV A,M
CMA
INR A
STAX B
INX B
INX H
DCR E
JNZ LOOP
HLT