org 100h

mov ax, 0400h
mov ds, ax

mov cx, [0000h]
cmp cx ,0
jz not_found

mov si, 0002h

mov bx, [0010h]

search_loop:
    mov ax, [si]
    cmp ax, bx
    je found
    
    add si,2
    loop search_loop
    
not_found:
    mov si, 0020h
    mov al, 0
    mov [si], al
    jmp end_program
    
found: 
    mov si, 0020h
    mov al, 1
    mov [si], al

end_program:
    mov ah, 4Ch
    int 21h