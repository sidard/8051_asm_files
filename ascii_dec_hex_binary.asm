//WALP WHOSE:
//			INPUT:65
//			OUTPUT:6 5 A 4 1 . 0 1 0 0 . 0 0 0 1
//    38H 39H 3AH 3BH 3CH 3DH 3EH 3FH
//		B7 B6  B5  B4  B3  B2  B1  B0
	CSEG AT 0H
	MOV 30H,#65
	MOV A,#65
	MOV 33H,A;33H=A
	
	MOV B,#10
	DIV AB
	ADD A,#48
	MOV 30H,A;30H=6
	
	MOV A,B
	ADD A,#48
	MOV 31H,A;31H=5
	
	MOV A,#65
	MOV B,#16
	DIV AB
	ADD A,#48
	MOV 35H,A;35H=4
	
	MOV A,B
	ADD A,#48
	MOV 36H,A;36H=1
	
	MOV A,#41H//FOR HEXA CONVERSION
	REP:
		MOV R1,#8
		MOV R0,#3FH
	LOOP:
		RRC A
		JC MAKE_1 ; FOR C=1
		MOV 20H.0,C ; FOR C=0
		MOV @R0,20H
		DEC R0
		DJNZ R1,LOOP
		SJMP CONV_ASCII
		MAKE_1:
				MOV 20H.0,C
				MOV @R0,20H
				DEC R0
				DJNZ R1,LOOP		
	CONV_ASCII:
				MOV R0,#8
				MOV R1,#3FH
	LOOP_1:
				MOV A,@R1
				ADD A,#48
				MOV @R1,A
				DEC R1  ///TRAVERSING THE LOCATION BY LOCATION
				DJNZ R0,LOOP_1 //CONVERSION BYTE BY BYTE INTO ASCII CHARACTER
				EXIT:
					END