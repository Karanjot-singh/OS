;NASM Program to check greater
;nasm -felf64 Q1.asm && ld Q1.o && ./a.out
          global    _start
          global checkGreater

          section   .text
_start:             
          call      checkGreater
          
checkGreater:
          mov       rdi, num1               ;3
          mov       rax, num2               ;5
          cmp       rax, rdi                ;5
          jg        _Greater
          jmp       _notGreater

_Greater:
          mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, messag1            ; address of string to output
          mov       rdx, 1                  ; number of bytes
          syscall                           ; invoke operating system to do the write
          jmp       exit
_notGreater:   
          mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, messag0            ; address of string to output
          mov       rdx, 1                  ; number of bytes
          syscall                           ; invoke operating system to do the write
          jmp       exit
exit:
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0
          syscall                           ; invoke operating system to exit

          section   .data
messag1:  db        "1", 10      ;
messag0:  db        "0", 10      ;
num1:     dq        3
num2:     dq        5      