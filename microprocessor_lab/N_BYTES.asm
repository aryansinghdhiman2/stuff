LXI H,4000H
MOV E,M
LXI B,3000H
LXI H,2000H
LOOP: MOV A,M
STAX B
INX H
INX B
DCR E
JNZ LOOP
HLT