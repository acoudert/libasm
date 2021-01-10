section			.text
	global		ft_list_sort		; Start function declaration for linker

ft_list_sort:
	cmp		[rdi], byte 0		; Check if empty list
	je		exit			; Exit if empty list
	mov		r8, [rdi]		; r8 = (*begin_list) = elem = &elem->data

loop:
	mov		r9, r8			; r9 = r8 = elem = &elem->data
	add		r9, 8			; r9 = &elem->next
	cmp		[r9], byte 0		; Check if elem->next = 0
	je		exit
	mov		r9, [r9]		; r9 = elem->next = &elem->next->data
	xor		rcx, rcx		; rcx used for swap
	push		rdi			; Store begin_list
	push		rsi			; Store &cmp_fct
	mov		r12, rsi		; Put &cmp_fct into r12
	mov		rdi, [r8]		; rdi = elem->data
	mov		rsi, [r9]		; rsi = elem->next->data
	call		r12			; Call cmp_fct
	pop		rsi			; Retrieve &cmp_fct
	pop		rdi			; Retrieve begin_list
	cmp		al, byte 0		; Check if swap required
	ja		swap_data		; Swap data

swap_if:
	cmp		rcx, 1			; Check if swapped
	jne		swap_else		; Go to else if not swapped
	mov		r8, [rdi]		; elem = *begin_list
	jmp		loop

swap_else:
	mov		r8, r9			; elem = elem->next
	jmp		loop

exit:
	ret

swap_data:
	mov		r10, [r8]		; r10 = elem->data
	mov		r11, [r9]		; r11 = elem->next->data
	mov		[r8], r11		; elem->data = elem->next->data
	mov		[r9], r10		; elem->next->data = (previous)elem->data
	inc		rcx
	jmp		swap_if
