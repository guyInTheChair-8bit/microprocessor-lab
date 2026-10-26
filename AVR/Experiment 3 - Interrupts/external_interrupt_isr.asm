.org 0x0000
rjmp reset

.org 0x0004
rjmp int1_ISR

.org 0x0100

reset:
      LDI R16,0x70
	  OUT SPL,R16
	  LDI R16,0x00
	  OUT SPH,R16

	  LDI R16,0x01
	  OUT DDRB,R16

	  LDI R16,0x00
	  OUT DDRD,R16

	  IN R16, mcucr
	  ORI R16, 0x08
	  OUT mcucr, r16

	  IN R16, gicr
	  ORI R16, 0x80
	  OUT gicr, r16

	  LDI R16,0x00
	  OUT PORTB,R16

	  SEI

ind_loop:rjmp ind_loop

int1_ISR:IN R16,SREG
		 push R16

         LDI R16, 0x0A
		 MOV R0,R16

	c1:	 LDI R16, 0x01
		 OUT PORTB,R16

		 LDI R16,0xFF
	a1:	 LDI R17,0xFF
	a2:	 DEC R17
		 BRNE a2
		 DEC R16
		 BRNE a1

		 LDI R16,0x00
		 OUT PORTB,R16

		 LDI R16,0xFF
	b1:	 LDI R17,0xFF
	b2:	 DEC R17
		 BRNE b2
		 DEC R16
		 BRNE b1

		 DEC R0
		 BRNE c1
		 pop  R16
		 OUT SREG,R16

    reti
