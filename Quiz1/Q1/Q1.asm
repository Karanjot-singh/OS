;NASM Program to check greater
;nasm -felf64 Q1.asm && ld Q1.o && ./a.out
          global    _start
          global checkGreater

          section   .text
_start:   
          push      rbp                     ;
          mov       rbp, rsp                ;
          ;sub       rsp, 8                  
          ;mov       [rbp - 4], [num1]       
          ;mov       [rbp - 8], [num2]       
          ;push      [rbp - 4]                  ;
          ;push      [rbp - 8]                  ;
          push       5
          push       3                           ;call(3,5)
          call      checkGreater
          
checkGreater:   
          push      rbp                     ;
          ;mov       rbp, rsp               
          mov       rax, [rbp+8]            ;3
          cmp       rax, [rbp+12]           ;5
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
;num1:     dq        3
;num2:     dq        5      
