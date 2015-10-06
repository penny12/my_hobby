CR	equ 0x0d
LF	equ 0x0a
EOS	equ 00
EXIT	equ 0x01
READ	equ 0x03
WRITE	equ 0x04

	;; org 0xbfcc6000
	;; dd msg
	
	global main
main:

;; keyin:
;; 	;; call chrin
;; 	;; mov eax, [edi]
;; 	cmp eax, '1'
;; 	jz job1
;; 	cmp edi, '2'
;; 	jz job2
;; 	cmp edi, '3'
;; 	jz job3
;; 	cmp edi, '4'
;; 	jz job4

;; 	mov ebp, qst
;; 	call msgout

;; 	jmp keyin
	

;; job1:
;; 	mov edx, job1_len	; size_t 1
;; 	mov ecx, job1_msg
;; 	mov ebx, 1		; absolutry 1
;; 	mov eax, WRITE		; syscall 4 : sys_write
;; 	int 0x80

;; 	jmp keyin
	
;; job2:	
;; job3:	
;; job4:
	push ebp
	mov ebp, msg
	call msgout
	pop ebp
	call quit
	
chrin:
	mov edx, 1		; size_t
	mov ecx, [edi]
	mov ebx, 0		; 0 : STDIN_COMMANDLINE
				; 1 : STDOUT_COMMANDLINE
				; 2 : STDERR_COMMANDLINE
	mov eax, READ
	int 0x80
	ret

msgout:
	mov eax, [ebp]
	cmp eax, EOS
	je  back
	call chrout
	inc ebp
	jmp msgout		; loop meg
	
back:	
	call quit

chrout:	
	
	mov edx, 1		; operand size prefix : 66
				; e.g.) 66 BA 0C : mov edx, len
				;     ) len : "hello, world" -> 0C
				; address size prefix : 67
	mov ecx, ebp
	mov ebx, 1		; file discriptor number : int fd
	mov eax, 4		; syscall number : 4 -> sys_write
				; sys_write : ebx -> unsigned int 
				;           : ecx -> const char *
				;           : edx -> size_t
	int 0x80		; execute instruction
	ret

quit:	
	mov ebx, 0
	mov eax, EXIT
	int 0x80
	ret

msg:
	db "hello, world", EOS

qst:
	db "?", EOS
	
job1_msg:
	db "job1 called", EOS
