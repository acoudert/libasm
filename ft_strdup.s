extern			malloc
extern			ft_strlen
extern			ft_strcpy

section			.text
	global		ft_strdup		; Start function declaration for linker

ft_strdup:
	push		rdi			; Store src ptr
	call		ft_strlen		; Get string len
	inc		rax			; Consider null character
	mov		rdi, rax		; Set up for malloc call
	call		malloc			; Retrieve dest ptr
	cmp		rax, 0			; Check if malloc failed
	je		_error_exit		; Jump if error
	mov		rdi, rax		; Set up for ft_strcpy call
	pop		rsi			; Set up for ft_strcpy call
	call		ft_strcpy		; Ret string in rax
	ret

_error_exit:
	mov		rax, 0			; Assign return value
	ret
