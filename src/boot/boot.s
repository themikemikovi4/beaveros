.section    .text
.globl      start
.type       start,      @function

start:
    cli
    mov     $3,         %rdi
    call    get_cr
    mov     %rax,       0xb8000
.Lhlt:
    hlt
    jmp     .Lhlt
