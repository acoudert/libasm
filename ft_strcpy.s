section		.text
	global	ft_strcpy		; Start function declaration for linker

ft_strcpy:
	xor	rcx, rcx		; Nullify 4th argument
	mov	rax, rdi		; Return value set up

_loop:
	cmp	[rsi + rcx], byte 0	; Null character comparison
	jz	_exit			; Exit if zero flag
	mov	dl, [rsi + rcx]		; Put character into 8 bits dl (rdx)
	mov	[rdi + rcx], dl		; Put character into 8 bits rdi + rcx
	inc	rcx			; Increment counter
	jmp	_loop			; Restart loop

_exit:
	mov	[rdi + rcx], byte 0	; Copy null character
	ret				; Return rax
