# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 22:16:57 by aldubar           #+#    #+#              #
#    Updated: 2021/03/15 22:28:49 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global		ft_strcpy

		section		.data

ft_strcpy:
		xor	rcx, rcx			; i
		xor	rax, rax

	loop:
		cmp	byte [rsi + rcx], 0		; src[rcx] == '\0' ?
		je	return
		mov	cl, byte [rsi + rcx]		; cl = src[rcx]
		mov	byte [rdi + rcx], cl		; dest[rcx] = cl
		inc	rcx				; rcx++
		jmp	loop

	return:
		mov	byte [rdi + rcx], 0		; dest[rcx] = '\0'
		mov	rax, rdi
		ret
