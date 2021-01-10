extern				malloc

section				.text
	global			ft_list_push_front

ft_list_push_front:
	push			rdi			; Store **begin_list
	mov			rdi, rsi		; Set up function call
	jmp			ft_create_elem		; rax = elem

ft_list_push_front_p2:
	pop			rdi			; Recover **begin_list
	cmp			[rdi], byte 0		; Check if list was empty
	je			exit_empty_list
	mov			r8, [rdi]		; r8 = *begin_list
	mov			[rax + 8], r8		; elem->next = *begin_list
	mov			[rdi], rax		; *begin_list = elem

exit_empty_list:
	mov			[rdi], rax		; Assign new elem ptr to *begin_list
	ret

ft_create_elem:
	push		rdi			; Store *data
	mov		rdi, 16			; List elem size for malloc
	call		malloc			; rax contains elem ptr
	cmp		rax, 0			; Check if malloc failed
	je		exit_malloc_failure	; Exit if failure
	pop		rdi			; Recover *data
	mov		[rax], rdi		; elem->data = data
	mov		[rax + 8], byte 0	; elem->next = 0
	jmp		ft_list_push_front_p2

exit_malloc_failure:
	mov		rax, 0			; Useless but for exhaustivity
	jmp		ft_list_push_front_p2
