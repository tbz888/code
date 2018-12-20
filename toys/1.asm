	mov ax,0xb800	;display memory
	mov es,ax
	
	;show my name and id
	mov byte [es:2*68], '1'
	mov byte [es:2*69], '3'
	mov byte [es:2*70], '3'
	mov byte [es:2*71], '4'	
	mov byte [es:2*72], '9'
	mov byte [es:2*73], '1'
	mov byte [es:2*74], '0'
	mov byte [es:2*75], '6'
	mov byte [es:2*80+2*70], 't'
	mov byte [es:2*80+2*71], 'b'
	mov byte [es:2*80+2*72], 'z'
									
	;init								;demo collision
	mov ax,0 				;x-axis, [0,79]
	mov cx,1				;y-axis, [0,24]
	mov dx,3				;direction
							;left-top=1, right-top=2, left-down=4, right-down=3
	mov byte [es:160], '$'

loop:
	;choose branch
	cmp dx, 3
	je right_down
	cmp dx, 2
	je right_top
	cmp dx, 1
	je left_top
	cmp dx, 4
	je left_down
	
right_down:
	;ususal
	add ax,1		
	add cx,1
	
	;edge
	cmp cx,25
	jne outD
	mov cx,23
	mov dx,2
	outD:
	cmp ax,80
	jne outR
	mov ax,78
	mov dx,4
	outR:
	
	jmp finally
right_top:
	add ax,1		
	sub cx,1
	
	;edge
	cmp cx,-1
	jne out1D
	mov cx,1
	mov dx,3
	out1D:
	cmp ax,80
	jne out1R
	mov ax,78
	mov dx,1
	out1R:

	jmp finally
left_down:
	sub ax,1
	add cx,1
	
	;edge
	cmp cx,25
	jne out2D
	mov cx,23
	mov dx,1
	out2D:
	cmp ax,-1
	jne out2R
	mov ax,1
	mov dx,3
	out2R:
	
	jmp finally
left_top:
	sub ax,1
	sub cx,1
	
	;edge
	cmp cx,-1
	jne out3D
	mov cx,1
	mov dx,4
	out3D:
	cmp ax,-1
	jne out3R
	mov ax,1
	mov dx,2
	out3R:
	
	jmp finally

finally:
		mov bx,0				;compute address
		mov di,160
	l:
		add bx, cx
		dec di
		cmp di,0
		jz bye
		jmp l
	bye:
		add bx,ax
		add bx,ax				;end computation
	
	;delay
	mov di,0xcccc
	wasteTime:
		dec di
		mov si,0xccc
		wasteTime1:
			dec si
			cmp si,0
			jne wasteTime1
		cmp di,0
		jne wasteTime
	mov byte [es:bx], '$'
	jmp loop
	
abc:	times 162 db 0
		db 0x55,0xaa