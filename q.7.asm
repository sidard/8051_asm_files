//EXCHANGE BOTH LOWER NIBBLES OF REGISTERS R0 AND R1: PUT THE LOWER NIBBLE OF R0 AND R1, AND THE LOWER NIBBLE OF R1 IN R0
//INPUT:
//DATA IN R0= 0XEF
//DATA IN R1=0X15
//OUTPUT:
//DATA IN R0= 0XE5
//DATA IN R1=OX1F
CSEG AT 0H
	MOV R0,#0XEF//DATA 1
	MOV R1,#0X15// DATA 2
	MOV A,R0 
	MOV R0,#0X01
	XCHD A,@R0 //XHANGE THE LOWER NIBBLES BETWEEN THE OPERAND
	MOV R0,A
	END
