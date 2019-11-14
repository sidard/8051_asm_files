delay_1ms_sub  segment code
rseg delay_1ms_sub
	delay_1ms:
	mov r3,#2
	rep:mov r2,#248
	djnz r2,$
	djnz r3,rep
	ret
public delay_1ms
	end
