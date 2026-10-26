        AREA Program, CODE, READONLY
        ENTRY
        LDR R0, NUM1
Stop
        B Stop
        AREA Data, DATA, READONLY
NUM1    DCD &12345678
        END
