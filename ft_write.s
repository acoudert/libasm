extern			__errno_location

section			.text
	global		ft_write		; Start function declaration for linker

ft_write:
	mov		rax, 1			; System call definition - syswrite
	syscall					; Call the kernel
	cmp		rax, 0			; Error if less than 0
	jl		_error_exit		; Jump if error
	ret

_error_exit:
	push		rax			; Push stack to store rax
	call		__errno_location	; Get errno ptr
	pop		r8			; Retrieve stored rax into r8
	neg		r8			; Convert neg error nb to positive
	mov		[rax], r8		; Assign errno to errno ptr
	mov		rax, -1			; Assign return value
	ret
