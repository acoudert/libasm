section		.text
	global	ft_strcmp		; Start function declaration for linker

ft_strcmp:
	xor	rcx, rcx		; Nullify 4th argument

_loop:
	mov	r8b, [rdi + rcx]	; Store pointed char
	mov	r9b, [rsi + rcx]	; Store pointed char
	cmp	r8b, 0			; Compare null char
	je	_exit			; Jump if null
	cmp	r9b, 0			; Compare null char
	je	_exit			; Jump if null
	cmp	r8b, r9b		; Check if same char
	jne	_exit			; Exit if not equal
	inc	rcx			; Increment counter
	jmp	_loop			; Restart loop

_exit:
	sub	r8b, r9b		; Store sub result into 8 bits register
	movsx	rax, r8b		; Sign extension mov to keep sign
	ret				; Return rax
