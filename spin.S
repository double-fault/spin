.section .text

.global spin
.align 128
spin:
        jmp j1
j1:     jmp j2
j2:     jmp j3
j3:     jmp j4
j4:     jmp j5
j5:     jmp loop
.align 128
loop:
        sub $26,%rdi
        lfence
        jle end
        lfence
        jmp loop
end:
        ret
