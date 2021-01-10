section		.text
	global	ft_strlen	; Start function declaration for linker

ft_strlen:
	xor	rcx, rcx	; Nullify 4th argument

_loop:
	cmp	[rdi], byte 0	; Null character comparison
	jz	_exit		; Exit if zero flag
	inc	rcx		; Increment counter
	inc	rdi		; Increment string character
	jmp	_loop		; Restart loop

_exit:
	mov	rax, rcx	; Put counter value into return value
	ret			; Return rax
