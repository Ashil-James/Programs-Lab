org 100h

mov ax, 0400h
mov ds, ax

mov cl, [0000h]
dec cl
jz finish

outer_loop:
    mov si, 0001h
    mov ch, cl
    
inner_loop:
    mov ax, [si]
    mov bx, [si+2]
    cmp ax, bx
    jbe no_swap
    
    
    mov [si], bx
    mov [si+2], ax
    
no_swap:
    add si, 2
    dec ch
    jnz inner_loop
    
    dec cl
    jnz outer_loop
 
 
finish:
    mov ah, 4Ch
    int 21h