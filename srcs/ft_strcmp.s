# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 14:47:41 by aldubar           #+#    #+#              #
#    Updated: 2021/03/22 11:55:02 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; int	ft_strcmp(const char *rdi, const char *rsi)


		global		ft_strcmp

		section		.text

ft_strcmp:
		xor	rax, rax			; ret
		xor	rcx, rcx			; i

	loop:
		mov	al, byte [rdi + rcx]		; al = s1[rcx]
		cmp	al, byte [rsi + rcx]		; s1[rcx] == s2[rcx] ?
		jne	diff				; if no, calculate diff
		cmp	al, 0				; s1[rcx] == \0 ?
		je	return				; if yes return value
		mov	al, byte [rsi + rcx]		; al = s2[rcx]
		cmp	al, 0				; s2[rcx] == \0 ?
		je	return				; if yes return value
		inc	rcx				; rcx++
		jmp	loop

	diff:
		mov	cl, byte[rsi + rcx]		; cl = s2[rcx]
		sub	eax, ecx			; rax -= cl
		ret

	return:
		mov	rax, 0
		ret
