bits 16
org 0x7c00


main: 
    cli
    mov ax,cs
    mov ds,ax
    mov es,ax
    mov ss,ax
    sti

    mov si,msg
    call print
    call println
    
    mov si,author
    call print
    call println  

    mov si,rollno
    call print

    jmp $
 
print:
    
  nextchar:
     lodsb
     or al,al
     jz return
     mov ah,0x0E
     int 0x10
     jmp nextchar

  return:
     ret

println:
     mov al,0
     stosb
     mov ah,0x0E
     mov al,0x0D
     int 0x10
     mov al,0x0A
     int 0x10
     ret

      

msg db 'My First Bootloader    ', 0x0
author db 'By Suraj Rajendra Bhosale   ', 0x0
rollno db 'Rollno - 16205  ', 0x0
times 510 - ($-$$) db 0
dw 0xAA55
