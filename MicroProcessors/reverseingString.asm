org 100h

msg db 'ASHIL$',0
rev db 20 dup('$')

mov si, offset msg
mov cx, 0

count_loop:
    mov al, [si]
    cmp al, '$'
    je reverse_start
    inc si
    inc cx
    jmp count_loop

reverse_start:
    dec si
    mov di, offset rev 

reverse_loop:
    mov al, [si]
    mov [di], al
    inc di
    dec si
    loop reverse_loop
    
    mov byte ptr [di], '$'
    
    mov dx, offset rev
    mov ah, 09h
    int 21h
    
    mov ah, 4Ch
    int 21h 