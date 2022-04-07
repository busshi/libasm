[![aldubar's 42 libasm Score](https://badge42.vercel.app/api/v2/cl1p4dvqu002109k1x3fvx39n/project/2129614)](https://github.com/JaeSeoKim/badge42)

# LIBASM

### Description
Write ASM 64 bits:
• no inline asm but ’.s’ filese
• compile with nasm
• use Intel syntax not AT&T

### Mandatory part
The library must be named libasm.a
• Give a test main to compile and test our library.
• iRewrite following functions:
◦ ft_strlen (man 3 strlen)
◦ ft_strcpy (man 3 strcpy)
◦ ft_strcmp (man 3 strcmp)
◦ ft_write (man 2 write)
◦ ft_read (man 2 read)
◦ ft_strdup (man 3 strdup, malloc autorisé)
• Check syscalls errors
• Permit the read of the variable errno (<errno.h>) from a .c file (using extern ___error is allowed)
