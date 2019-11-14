extrn code (delay_1ms)
delay_5ms_sub  segment code
rseg delay_5ms_sub
	delay_5ms:
	mov r1,#5
	rep2:lcall delay_1ms
	djnz r1,rep2
	ret
public delay_5ms
	end