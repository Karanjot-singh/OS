;NASM Program to check greater integer out of two numbers
          global    _start
          global checkGreater

          section   .text
_start:   
          mov       rdi, num1               ;3
          mov       rsi, num2               ;5         
          call      checkGreater
          
checkGreater:
          mov       rax, rsi                ;main: 7  _start: 5 
          cmp       rax, rdi                ;main: 13 _start : 3
          jg        _Greater                ;if rsi> rdi : 1 else 0
          jmp       _notGreater

_Greater:
          mov       rax, 1                  ; system call write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, messag1            ; 
          mov       rdx, 1                  ; 
          syscall                           ; invoke  write
          jmp       exit
_notGreater:   
          mov       rax, 1                  ; system call write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, messag0            ; 
          mov       rdx, 1                  ; number of bytes
          syscall                           ; invoke write
          jmp       exit
exit:
          mov       rax, 60                 ; system call exit
          xor       rdi, rdi                ; exit code 0
          syscall                           ; invoke  exit

          section   .data
messag1:  db        "1", 10      ;
messag0:  db        "0", 10      ;
num1:     dq        3
num2:     dq        5      