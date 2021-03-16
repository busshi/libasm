# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 22:16:57 by aldubar           #+#    #+#              #
#    Updated: 2021/03/16 10:16:06 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global		ft_strcpy

		section		.text

ft_strcpy:
		xor	rax, rax			; init rax
		xor	rdx, rdx			; i = 0

	loop:
		cmp	byte [rsi + rdx], 0		; src[rdx] == '\0' ?
		je	return
		mov	cl, byte [rsi + rdx]		; cl = src[rdx]
		mov	byte [rdi + rdx], cl		; dest[rdx] = cl
		inc	rdx				; rdx++
		jmp	loop

	return:
		mov	byte [rdi + rdx], 0		; dest[rdx] = '\0'
		mov	rax, rdi
		ret
