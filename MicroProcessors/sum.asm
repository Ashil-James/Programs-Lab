org 100h

; ----- Example: 25h + 37h -----
mov al, 25h      ; first 8-bit operand
mov bl, 37h      ; second 8-bit operand

add al, bl       ; AL = AL + BL
jc  add_carry    ; if carry set, jump

mov [result], al ; store result (no carry)
mov [carry], 0
jmp done

add_carry:
mov [result], al ; low 8 bits stored
mov [carry], 1   ; indicate carry = 1

done:
hlt

result db 0
carry  db 0
