#!/bin/sh

nasm -l test.lst -f elf -o test.o test.asm
gcc -o test test.o