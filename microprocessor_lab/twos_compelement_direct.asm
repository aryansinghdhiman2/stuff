LDA 0040H
MOV B,A 
LDA 0041H
CMA 
INR A
ADD B

JC ONCAR
CMA
INR A
STA 0042H
MVI A,01H
STA 0043H
HLT

ONCAR:
STA 0042H
MVI A,00H
STA 0043H
HLT