        AREA Program, CODE, READONLY
        ENTRY
        MOV R0, #0
        MOV R1, #1
        MOV R3, #8
REPEAT
        ADD R2, R0, R1
        MOV R0, R1
        MOV R1, R2
        SUB R3, R3, #1
        CMP R3, #0
        BEQ DONE
        B REPEAT
DONE
        B DONE
        END
