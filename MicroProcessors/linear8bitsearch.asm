org 100h

mov ax, 0400h 
mov ds, ax

xor ch,ch
; FIX 1: Added brackets to read the value '05' from memory
mov al, [0000h] 
mov cl, al 

; Safety check: If count is 0, skip directly to not_found
cmp cl, 0
jz not_found
           
mov si, [0001h]   ; Starting address of the array
mov al, [0010h] ; Element to be searched (2D)
mov dl, al

; FIX 2: Removed 'dec cl'. The loop instruction handles the count logic.

search_loop:
    mov al, [si]
    cmp al,dl
    je found
    inc si
    loop search_loop
    
not_found:
    mov si, 0020h
    mov al, 0h
    mov [si], al
    jmp end_program
    
found:
    mov si, 0020h
    mov al, 1
    mov [si], al

end_program:
    mov ah, 4Ch
    int 21h