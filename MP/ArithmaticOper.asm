section .data
	num1 dq 0000000000000014
	num2 dq 0000000000000003
	msg db 10,"1) Addition 2) Subtraction 3) Multiplication 4) Division"
	len: equ $-msg
	choice db 00h
	
%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .bss
	var resb 16
	inp resb 16
	
section .text
global _start
_start:
	rw 01,01,msg,len
	rw 00,00,choice,1
	
	cmp byte[choice],31h
	JE one
	cmp byte[choice],32h
	JE two
	cmp byte[choice],33h
	JE three
	cmp byte[choice],34h
	JE four
	JMP exit
	
one:
call Addition
JMP exit

two:
call Subtraction
JMP exit

three:
call Multiplication
JMP exit

four:
call Division
JMP exit
	
	exit:
	mov rax,60
	mov rdi,0
	syscall
	

Addition:
	mov rax,[num1]
	mov rbx,[num2]
	add rax,rbx
	ret
	
Subtraction:
	mov rax,[num1]	
	mov rbx,[num2]
	sub rax,rbx
	ret
	
Multiplication:
	mov rax,[num1]
	mov rbx,[num2]
	
