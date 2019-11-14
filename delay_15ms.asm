extrn code (delay_1ms)
delay_15ms_sub  segment code
rseg delay_15ms_sub
	delay_15ms:
	mov r1,#15
	rep2:lcall delay_1ms
	djnz r1,rep2
	ret
public delay_15ms
	end