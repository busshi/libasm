# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 14:47:41 by aldubar           #+#    #+#              #
#    Updated: 2021/03/15 18:02:20 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global		.ft_strcmp

section		.text

ft_strcmp:
		xor	rax, rax			; ret
		xor	rcx, rcx			; i

	loop:
		move	al, byte [rdi + rcx]		; al = s1[rcx]
		cmp	al, byte [rsi + rcx]		; s1[rcx] == s2[rcx] ?
		jne	diff				; if no, calculate diff
		cmp	byte [rsi + rcx], 0		; check if nul byte \0
		je	return				; if yes return value
		inc	rcx				; rcx++
		jmp	loop

	diff:
		move	cl, byte[rsi + rcx]		; cl = s2[rcx]
		sub	eax, ecx			; rax = diff
		ret

	return:
		move	rax, 0
		ret
