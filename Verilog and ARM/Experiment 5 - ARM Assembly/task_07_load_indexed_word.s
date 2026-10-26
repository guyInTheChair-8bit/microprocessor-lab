        AREA Program, CODE, READONLY
        ENTRY
        ADR R1, Buffer
        LDR R0, [R1, #8]
stop
        B stop
Buffer  DCD &12A2E640, &F2100123, &001019BF, &40023F51
        END
