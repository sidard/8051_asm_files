rs equ P3.4
rw equ P3.5
en equ P3.6
extrn code (delay_15ms)
extrn code (delay_5ms)
extrn code (delay_1ms)

cseg at 0h
	lcall delay_15ms
	
	mov a,#0x30
	lcall cmd
	lcall delay_5ms
	
	mov a,#0x30
	lcall cmd
	lcall delay_1ms
	
	mov a,#0x30
	lcall cmd
	lcall delay_1ms
		
	mov a,#0x38;
	lcall cmd
	
	mov a,#0x10;
	lcall cmd	
	
	mov a,#0x01;
	lcall cmd	
	
	mov a,#0x06;
	lcall cmd	
	
	mov a,#0x0f;
	lcall cmd	

	mov a,#0x80
	lcall cmd
	mov a,#'A'
	lcall display
	
	mov a,#0x81
	lcall cmd
	mov a,#'B'
	lcall display
	
	mov a,#0x82
	lcall cmd
	mov a,#'C'
	lcall display
	
	mov a,#0x83
	lcall cmd
	mov a,#'D'
	lcall display
	
	mov a,#0x84
	lcall cmd
	mov a,#'E'
	lcall display

	mov a,#0x85
	lcall cmd
	mov a,#'F'
	lcall display
	sjmp $
	
	cmd:
		clr rs;
		clr rw
		mov P0,a
		setb en;
		clr en;
		lcall delay_1ms
		ret
	display:
		setb rs
		clr rw
		mov P0,a
		setb en
		clr en
		lcall delay_1ms
		ret
	end