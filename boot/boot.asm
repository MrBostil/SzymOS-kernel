; boot.asm - Multiboot header and entry point for SzymOS
section .multiboot
    MULTIBOOT_MAGIC equ 0x1BADB002
    MULTIBOOT_FLAGS equ 0x0
    MULTIBOOT_CHECKSUM equ -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)
    
    align 4
    dd MULTIBOOT_MAGIC
    dd MULTIBOOT_FLAGS
    dd MULTIBOOT_CHECKSUM

section .bss
    align 16
stack_bottom:
    resb 16384  ; 16 KB stack
stack_top:

section .text
global _start
extern kernel_main

_start:
    mov esp, stack_top
    
    ; Push multiboot info
    push ebx
    push eax
    
    call kernel_main
    
    ; Hang if kernel returns
    cli
.hang:
    hlt
    jmp .hang

; Mark stack as non-executable (fixes ld warning)
section .note.GNU-stack noalloc noexec nowrite progbits