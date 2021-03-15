# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:31:14 by aldubar           #+#    #+#              #
#    Updated: 2021/03/15 11:09:10 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global 		ft_strlen

	section		.text

ft_strlen:
		xor	rax, rax
		xor	rdx, rdx

	_loop:
		mov	al, [rdi + rdx]
		cmp	al, 0
		je	_return
		inc	rdx
		jmp	_loop

	_return:
		mov	rax, rdx
		ret
