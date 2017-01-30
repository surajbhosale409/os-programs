bits 16




main: 
    cli
    mov ax,0x7c0 	;setting the start address of bootsector
    mov ds,ax 		;move start address in ax to data segment
    mov es,ax
    mov ss,ax
    sti
  

 

    mov si,msg  	;mov msg in source index
    call print  	;call to print routine
    call println 	;call to println routine

  
    mov si,author       ; now move string author in si
    call print         
    call println  
 
 
    mov si,rollno       
    call print 
 
    jmp $		;jump here i.e execute this instrunction again and again
 
print:
    
  nextchar:
     lodsb           	;loads 1byte of string in al

     or al,al           ;checks whether string is empty or not by checking character in al. it will return 1 if there is character in al loaded by lodsb at end it will load 0 in al at that time this instrunction will give output 0

     jz return		;if above instrunction gives o/p 0 then jump if zero to return label
     mov ah,0x0E        ;move 0e for to type character on screen
     int 0x10           ;int 10h to perform action specified in ah
     jmp nextchar       ;jump to nextchar label

  return:
     ret                ;return to instrunction next to calling instrunction

println:
     mov ah,0x0E  	;print character mode
     mov al,0x0D        ; move 0d in al to move cursor to left most position of screen i.e. start of line
     int 0x10           ; print character specified by 0d
     mov al,0x0A        ; move 0a in al to move cursor to next line
     int 0x10           ; print character specified by 0a ,,, 0d and 0a combinely works as \n that is goto new line
     ret



	
msg db 'My First Operating System    ', 0x0       ;define byte string
author db 'By Suraj Rajendra Bhosale   ', 0x0     
rollno db 'Rollno - 16205  ', 0x0
times 510 - ($-$$) db 0                           ;my bootloader is short i.e. not 512Bytes so pad remaining bytes upto 510bytes with 0
dw 0xAA55                                         ; now the remaining 2bytes will be 55AA i.e. bootloader signature
