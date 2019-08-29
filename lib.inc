section .text

string_length:
    xor rax, rax

    .loop:
        cmp byte [rdi + rax], 0
        je .end
        inc rax
        jmp .loop
    .end:
        ret


print_string:
    xor rax, rax

    .loop:
        cmp byte [rdi + rax], 0
        je .end
        push rax
        push rdi
        push rcx
        lea rsi, [rdi + rax]
        mov rax, 1
        mov rdi, 1
        mov rdx, 1
        syscall
        pop rcx
        pop rdi
        pop rax
        inc rax
        jmp .loop
    
    .end:
        ret


print_char:
    xor rax, rax
    ret

print_newline:
    xor rax, rax
    ret


print_uint:
    xor rax, rax
    ret


print_int:
    xor rax, rax
    ret

string_equals:
    xor rax, rax
    ret


read_char:
    xor rax, rax
    ret 

read_word:
    ret

; rdi points to a string
; returns rax: number, rdx : length
parse_uint:
    xor rax, rax
    ret

; rdi points to a string
; returns rax: number, rdx : length
parse_int:
    xor rax, rax
    ret 


string_copy:
    ; arguments come in through rdi, rsi, rdx
    ; before continuing, review callee and caller saved registers
    ; also memorize default argument registers for functions and syscalls

    ; call string_length
    ; compare value to buffer length (rdx)
    ; if buffer length is shorter than string length, return zero
    ; (should I pad zeros if string is shorter?)
    ; loop to move characters into buffer
    xor rax, rax

    push rdi
    call string_length
    cmp rdx, rdi
    jl .short_buffer
    mov rcx, 0
    pop rdi
    push rsi
    je .loop

    .short_buffer:
        mov rax, 0
        ret

     .loop:
        mov rsi, [rdi + rcx]
        cmp rcx, rdx
        inc rcx
        inc rsi
        jl .loop

    pop rsi
    mov rax, rsi
    ret
    