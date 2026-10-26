.include "m8def.inc"
.CSEG
LDI R16, 0xD3
LDI R17, 0x5F
ADD R16, R17
STOP:
    RJMP STOP
