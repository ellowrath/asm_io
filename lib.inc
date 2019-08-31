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
    push rdi
    mov rdi, rsp
    call print_string
    pop rdi
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
    push rdi
    push rsi
    push rdx
    call string_length
    pop rdx
    pop rsi
    pop rdi

    cmp rax, rdx
    jae .short_buffer

    push rsi

    .loop:
        mov dl, byte[rdi]
        mov byte[rsi], dl
        inc rdi
        inc rsi
        test dl, dl
        jnz .loop

    pop rax
    ret

    .short_buffer:
        xor rax, rax
        ret
    