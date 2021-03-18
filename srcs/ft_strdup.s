# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 10:19:55 by aldubar           #+#    #+#              #
#    Updated: 2021/03/17 17:03:53 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global		ft_strdup

	extern		ft_strlen
	extern		ft_strcpy
	extern		malloc
	extern		__errno_location

	section		.text

ft_strdup:
			push	rdi				; save dest
			call	ft_strlen			; rax = ft_strlen
			inc	rax				; rax++
			mov	rdi, rax			; rdi = rax
			call	malloc wrt ..plt		; rax = malloc(rdi)
			cmp	rax, 0				; malloc failed ?
			je	return
			mov	rdi, rax			; dest = rax
			pop	rsi				; retrieve dest into src
			call	ft_strcpy			; rax = dest	
			ret

	return:
			call	__errno_location wrt ..plt
			mov	QWORD [rax], 12			; errno value of 'out of memory'
			pop	rax
			xor	rax, rax
			ret
