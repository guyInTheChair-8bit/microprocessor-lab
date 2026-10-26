        AREA Program, CODE, READONLY
        ENTRY
        ADR R0, Value1
        LDMIA R0, {R1, R2}
        ADR R3, Value2
        LDMIA R3, {R4, R5}
stop
        B stop
Value1  DCD &12A2E640, &F2100123
Value2  DCD &001019BF, &40023F51
        END
