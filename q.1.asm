//PLACE THE NUMBER IN 3BH IN INTERNAL RAM LOCATIONS 30H TO 32H
// OUTPUT: 30H 31H 32H -> MEMORY ADDRESS
//         3BH 3BH 3BH -> DATA TO BE STORED        
CSEG AT 0H
	MOV A,#0X3B
	MOV R0,#0X32
	MOV R1,#3
	REP:
	MOV @R0,A
	DEC R0
	DJNZ R1,REP
	END