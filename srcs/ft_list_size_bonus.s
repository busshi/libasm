# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 10:37:31 by aldubar           #+#    #+#              #
#    Updated: 2021/03/19 14:23:08 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


		global		ft_list_size

		section		.text

ft_list_size:
		xor	rax, rax			; i = 0

	loop:
		cmp	rdi, 0				; begin_list = NULL ?
		je	return
		inc	rax				; i++
		mov	rdi, [rdi + 8]			; ->next
		jmp	loop

	return:
		ret					; return i
