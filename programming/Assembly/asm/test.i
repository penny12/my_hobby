%line 1+1 test.asm
CR equ 0dh
LF equ 0ah
EOS equ 00

 org 0xbfcc6000
 dd msg

msg:
 db "hello, world"

len: equ $-msg


[global main]
main:
 mov edx, len
 mov ecx, msg
 mov ebx, 1
 mov eax, 4
 int 0x80

 mov ebx, 0
 mov eax, 1
 int 0x80
