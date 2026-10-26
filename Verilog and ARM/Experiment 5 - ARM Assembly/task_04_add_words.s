        AREA Program, CODE, READONLY
        ENTRY
        LDR R0, NUM1
        LDR R1, NUM2
        ADD R2, R0, R1
stop
        B stop
        AREA Data, DATA, READONLY
NUM1    DCD &12345678
NUM2    DCD &00000002
        END
