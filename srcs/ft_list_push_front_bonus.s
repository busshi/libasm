# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front_bonus.s                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 14:16:18 by aldubar           #+#    #+#              #
#    Updated: 2021/03/19 14:50:03 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global 		ft_list_push_front

	extern		malloc
	extern		__errno_location

	section		.text

ft_list_push_front:
			push	rsp
			xor	rax, rax			; rax = 0
			push 	rdi				; save **begin_list
			push 	rsi 				; save *data
			mov	rdi, 16				; size t_list
			call	malloc wrt ..plt
			cmp	rax, 0				; malloc failed ?
			je	error
			pop 	QWORD [rax]			; retrieve *data in rax [0-8]
			pop 	rdi				; retrieve **begin_list
			mov	rdx, [rdi]			; put begin_list in rdx
			mov	[rax + 8], rdx			; put rdx [8-15] ->next
			mov	[rdi], rax			; put new data at begin_list
			pop	rsp
			ret

	error:
			call	__errno_location wrt ..plt
			mov	QWORD [rax], 12
			pop	rax
			xor	rax, rax
			ret
