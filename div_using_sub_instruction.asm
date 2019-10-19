//DO DIV WITHOUT USING ITS AVAILABLE INSTRUCTION
CSEG AT 0H
	MOV A,#56//NUMERATOR
	MOV B,#8//DENOMINATOR
	REP:
		SUBB A,B
		INC R7;FOR QUOTIENT
		JNC REP
		DEC R7//TO DECREMENT TO GET THE ACTUAL ANSWER FOR QUOTIENT
		
		ADD A,B//ADDING TO GET THE PREVIOUS RESULT
		
		MOV B,A//FOR STRORING THE REMAINDER
		
		MOV A,R7//FOR STORING THE QUOTIENT
	END
		
//FOR DIVISION BY ZERO
//Note:
	//When ever we divide by zero always there has to be CY=0 and OV=1 to indicate by processor indicating the infinity
CSEG AT 0H
	MOV A,#6//DENOMINATOR
	MOV A,B
	JZ SKIP//IF DENOMINATOR IS ZERO
	MOV A,#56
	REP:
		SUBB A,B
		INC R7
		JNC REP 
		DEC R7
		ADD A,B
		MOV B,A//	REMAINDER
		MOV A,R7// QUOTIENT
		SJMP EXIT
		SKIP:
			SETB OV
		EXIT:
			CLR C
			END