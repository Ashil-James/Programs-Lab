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
    mov bl, [si]
    mov bh, [si+1]
    cmp bl, bh
    jbe no_swap
    
 
    mov [si], bh
    mov [si+1], bl
 
no_swap:
    inc si
    dec ch
    jnz inner_loop
    
    dec cl
    jnz outer_loop
    
    
finish: 
    mov ah, 4Ch
    int 21h
