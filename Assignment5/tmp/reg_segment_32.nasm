;;
;ax has values for segment reg
set_seg_register:

    mov  ds,  ax                    
    mov  fs,  ax
    mov  gs,  ax
    mov  ss,  ax
    ret