section			.text
	global		ft_list_size

ft_list_size:
	xor		rcx, rcx		; Set up counter

loop:
	cmp		rdi, 0			; Check if end of list
	je		exit
	mov		rdi, [rdi + 8]		; elem = elem->next
	inc		rcx			; Inc counter
	jmp		loop			; Restart loop

exit:
	mov		rax, rcx		; Assign return value
	ret
