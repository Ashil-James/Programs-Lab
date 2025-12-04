; simple add-bytes-at-offsets.asm  (EMU8086 / .COM style)
org 100h            ; standard for .COM program

start:
    ; set DS = 2000h
    mov ax, 2000h
    mov ds, ax

    ; load byte from offset 0500h into AL
    mov si, 0500h
    mov al, [si]

    ; load byte from offset 0600h into BL
    mov si, 0600h
    mov bl, [si]

    ; add them (AL = AL + BL). Carry (if any) goes to CF; result truncated to byte.
    add al, bl

    ; store result at offset 0700h
    mov si, 0700h
    mov [si], al

    ; terminate program (DOS)
    mov ax, 4C00h
    int 21h
