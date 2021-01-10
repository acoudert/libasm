extern		ft_strlen
extern		ft_write

section		.text
	global		ft_atoi_base		; Start function declaration for linker

ft_atoi_base:
	push		rdi			; Store str
	mov		rdi, rsi		; Store base into rdi
	call		base_not_ok		; Call base_not_ok function
	pop		rdi			; Retrieve stored rdi
	cmp		rax, 1			; Check if base ok
	je		exit_zero		; Exit if base not ok
	xor		rcx, rcx		; Nullify counter
	jmp		remove_tnrvf_s		; Remove 9 to 13 and spaces

remove_tnrvf_s:
	cmp		[rdi + rcx], byte 32	; increment if space
	je		inc_rcx
	cmp		[rdi + rcx], byte 9	; Checks for tnrvf
	je		inc_rcx
	cmp		[rdi + rcx], byte 10	; Checks for tnrvf
	je		inc_rcx
	cmp		[rdi + rcx], byte 11	; Checks for tnrvf
	je		inc_rcx
	cmp		[rdi + rcx], byte 12	; Checks for tnrvf
	je		inc_rcx
	cmp		[rdi + rcx], byte 13	; Checks for tnrvf
	je		inc_rcx			; Inc str index
	xor		rax, rax
	mov		al, 1			; Init sign storing place
	xor		r9, r9	
	mov		r9, -1			; Sign multiplier
	jmp		sign_def		; Check sign

inc_rcx:
	inc		rcx			; Inc str index
	jmp		remove_tnrvf_s		; Restart with next index

sign_def:
	cmp		[rdi + rcx], byte 43	; Check '+' sign
	je		plus_sign
	cmp		[rdi + rcx], byte 45	; Check '-' sign
	je		minus_sign
	xor		r8, r8			; Set r8 to 0
	mov		r8, rax			; Sign stored in r8
	jmp		calculate_int		; Time to calculate the int

plus_sign:
	inc		rcx
	jmp		sign_def

minus_sign:
	inc		rcx
	imul		r9b			; rax = rax * r9b
	jmp		sign_def

calculate_int:
	push		rcx			; Store counter value
	push		rdi			; Store rdi
	mov		rdi, rsi		; ft_strlen call set up
	call		ft_strlen
	pop		rdi			; Recover str ptr
	pop		rcx			; Recover str index
	xor		r9, r9			; Set up base length
	mov		r9, rax			; Base length into r9
	xor		rax, rax		; Set up res
	xor		r11, r11		; Nullify for byte comparison
	xor		r12, r12		; Nullify for byte comparison

int_loop1:
	xor		r10, r10		; Init base index

int_loop2:
	mov		r11b, [rdi + rcx]	; Store str char
	mov		r12b, [rsi + r10]	; Store base char
	cmp		r11b, r12b		; Is it the base character
	je		int_loop1_2nd_part
	inc		r10			; Inc base index
	cmp		[rsi + r10], byte 0	; End of base
	je		exit_res
	jmp		int_loop2		; Check next base index
	
int_loop1_2nd_part:
	imul		r9			; res * base_len
	add		rax, r10		; Add index to res
	inc		rcx			; Inc str index
	jmp		int_loop1		; Restart loop for new index


exit_zero:
	mov		rax, 0
	ret

exit_res:
	cmp		r8, 1			; If positive sign return
	je		exit
	xor		r8, r8			; Put r8 to -1
	mov		r8, -1			; Put r8 to -1
	imul		r8			; Integer multiplication
	ret

exit:
	ret

base_not_ok:
	xor		r8, r8			; Nullify counter1

base_not_ok_loop1:
	cmp		[rdi + r8], byte 0	; Check if end of base
	je		base_not_ok_loop1_end	; End of loop
	mov		r9b, [rdi + r8]		; Store pointed char into r9b
	xor		r10, r10		; Nullify counter2
	cmp		r10, r8			; Check if needed to enter loop 2
	jl		base_not_ok_loop2	; Jmp to base_not_ok loop 2

base_not_ok_checks:
	cmp		r9b, 43			; Check if '+' sign
	je		exit_invalid_base	; Exit invalid base
	cmp		r9b, 45			; Check if '-' sign
	je		exit_invalid_base	; Exit invalid base
	cmp		r9b, 32			; Check if ' '
	je		exit_invalid_base	; Exit invalid base
	cmp		r9b, 8			; Jmp if greater
	ja		tnrvf_check		; Jmp for tnrvf check
	inc		r8			; Increment counter 1
	cmp		[rdi + r8], byte 0	; Check if end of base
	je		base_not_ok_loop1_end	; End of loop
	jmp		base_not_ok_loop1	; Continue loop 1

tnrvf_check:
	cmp		r9b, 14			; Exit if lower
	jl		exit_invalid_base	; 9 <= char <= 13
	inc		r8			; Increment counter 1
	jmp		base_not_ok_loop1	; Continue loop 1

base_not_ok_loop2:
	mov		r11b, [rdi + r10]	; Store pointed char into r11b
	cmp		r9b, r11b		; Check if invalid base
	je		exit_invalid_base	; Exit invalid base
	inc		r10			; Increment counter2
	cmp		r10, r8			; Check if loop 2 continues
	jl		base_not_ok_loop2	; Continue loop 2
	jmp		base_not_ok_checks

base_not_ok_loop1_end:
	cmp		r8, 1			; Check base length
	jle		exit_invalid_base	; Exit invalid base
	jmp		exit_valid_base		; Base is valid

exit_invalid_base:
	mov		rax, 1			; Assign return value
	ret

exit_valid_base:
	mov		rax, 0			; Assign return value
	ret
