	global	main
	extern printf

	section .text
main:
LFB0:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	mov	eax, LC0
	mov	[esp], eax
	call	printf
	mov	eax, 0
	leave
	ret
	
LC0:
	db	"Hello, World"
	
	