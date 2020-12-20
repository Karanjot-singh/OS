;
;
;AX has values for segments
;32 mode
set_seg_register:

    mov   ds , ax                    
    mov   fs , ax
    mov   gs , ax
    mov   ss , ax
    ret