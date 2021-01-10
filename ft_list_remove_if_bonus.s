extern			free

section			.text
	global		ft_list_remove_if	; Start function declaration for linker

ft_list_remove_if:
	cmp		[rdi], byte 0		; Check if empty list
	je		exit			; Exit if empty list

list_free_begin:
	xor		rax, rax		; Set to 0
	mov		r8, [rdi]		; r8 = elem = &elem->data = *begin_list
	push		rdi			; 1st arg
	push		rsi			; 2nd arg
	push		rdx			; 3rd arg
	push		rcx			; 4th arg
	mov		rdi, [r8]		; 1st arg = elem->data
	mov		rsi, rsi		; 2nd arg = data_ref (Useless)
	call		rdx			; Call cmp
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi
	cmp		rax, 0			; Remove elem if = 0
	je		remove_elem_begin
	jmp		ft_list_remove_if_p2	; End of loop if elem not to remove

remove_elem_begin:
	mov             r8, [rdi]               ; r8 = (*begin_list) = elem
	add		r8, 8			; r8 = &elem->next
	mov		r9, [r8]		; For next instruction
	mov		[rdi], r9		; *begin_list = (*begin_list)->next
	sub		r8, 8			; r8 = elem = &elem->data
        push            rdi                     ; 1st arg
        push            rsi                     ; 2nd arg
        push            rdx                     ; 3rd arg
        push            rcx                     ; 4th arg
	mov		rdi, [r8]		; 1st arg = elem->data
	call		rcx			; Call free_fct
	mov		rdi, r8			; 1st arg = elem
	call		free			; Call free
        pop             rcx
        pop             rdx
        pop             rsi
        pop             rdi
	cmp		[rdi], byte 0		; Check if *begin_list = 0
	je		exit
	jmp		list_free_begin

ft_list_remove_if_p2:
	mov		r8, [rdi]		; r8 = (*begin_list) = elem = &elem->data

loop:
	cmp		r8, 0			; Check elem = 0
	je		exit
	xor		r9, r9			; Set up to store &elem->next
	mov		r9, r8			; r9 = elem = &elem->data
	add		r9, 8			; r9 = &elem->next
	mov		r9, [r9]		; r9 = elem->next = &elem->next->data
	cmp		r9, byte 0		; Check if elem->next = 0
	je		exit
	xor		r10, r10		; Set up to store &elem->next->next
	mov		r10, r9			; r10 = elem->next = &elem->next->data
	add		r10, 8			; r10 = &elem->next->next
	mov		r10, [r10]		; r10 = elem->next->next = &elem->next->next->data
	push		r8
	push		r9
        push		r10
	push            rdi                     ; 1st arg = **begin_list
        push            rsi                     ; 2nd arg = *data_ref
        push            rdx                     ; 3rd arg = (*cmp)()
        push            rcx                     ; 4th arg = (*free_fct)()
	mov		rdi, [r9]		; 1st arg = elem->next->data
	mov		rsi, rsi		; 2nd arg = data_ref (useless)
	call		rdx			; Call (*cmp)(elem->next->data, data_ref)
        pop             rcx
        pop             rdx
        pop             rsi
        pop             rdi
	pop		r10
	pop		r9
	pop		r8
	cmp		rax, 0			; If return value = 0
	je		remove_elem		; Remove elem
	jmp		loop_end

remove_elem:
	push		r8
	push		r9
	push		r10
        push            rdi                     ; 1st arg = **begin_list
        push            rsi                     ; 2nd arg = *data_ref
        push            rdx                     ; 3rd arg = (*cmp)()
        push            rcx                     ; 4th arg = (*free_fct)()
	mov		rdi, [r9]		; 1st arg = elem->next->data
	call		rcx			; Call free_fct: Free elem->next->data
	mov		rdi, r9			; 1st arg = elem->next
	call		free			; Call free
        pop             rcx
        pop             rdx
        pop             rsi
        pop             rdi
	pop		r10
	pop		r9
	pop		r8
	xor		r9, r9			; Set up to store &elem->next
	mov		r9, r8			; r9 = elem = &elem->data
	add		r9, 8			; r9 = &elem->next
	mov		[r9], r10		; elem->next = r10 = (previous)elem->next->next
	mov		r9, r8			; Avoid skipping elem because elem->next removed
	jmp		loop_end

loop_end:
	mov		r8, r9			;  elem = elem->next
	jmp		loop

exit:
	ret
