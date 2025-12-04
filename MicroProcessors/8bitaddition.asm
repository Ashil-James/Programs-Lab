ORG 100h      ; required for .COM program in emu8086

mov ax, 2000h
mov ds, ax

mov ax, 0010h
mov [0500h], ax
mov ax, 004h
mov [0550h], ax

mov ax, [0500h]
sub ax, [0550h]
mov [0600h], ax

mov ax,4ch
int 21h 