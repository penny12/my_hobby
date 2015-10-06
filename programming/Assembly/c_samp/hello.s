	global main

main:
	
	mov edx, 12		; operand size prefix : 66
				; e.g.) 66 BA 0C : mov edx, len
				;     ) len : "hello, world" -> 0C
				; address size prefix : 67
	mov ecx, hello
	mov ebx, 1		; file discriptor number : int fd
	mov eax, 4		; syscall number : 4 -> sys_write
				; sys_write : ebx -> unsigned int 
				;           : ecx -> const char *
				;           : edx -> size_t
	int 0x80		; execute instruction
	ret

hello:
	db "Hello, World"