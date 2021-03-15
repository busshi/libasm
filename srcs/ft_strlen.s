# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:31:14 by aldubar           #+#    #+#              #
#    Updated: 2021/03/15 22:21:10 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global 		ft_strlen

		section		.text

ft_strlen:
		xor	rax, rax			; return value

	loop:
		cmp	byte [rdi + rax], 0		; s[rax] == 0 ?
		je	return				; yes return rax
		inc	rax				; rax++
		jmp	loop

	return:
		ret
