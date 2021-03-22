# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 23:30:16 by aldubar           #+#    #+#              #
#    Updated: 2021/03/22 11:58:56 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; ssize_t	ft_read(int rdi, char *rsi, size_t rdx)


	global		ft_read

	extern		__errno_location

	section		.text

ft_read:
			mov	rax, 0				; read function in rax
			syscall
			cmp	rax, 0				; error ?
			jl	error
			ret

	error:
			neg	rax				; absolute value of rax
			mov	rdi, rax			; save rax in dri
			call	__errno_location wrt ..plt
			mov	[rax], rdi			; retrieve rax saved
			mov	rax, -1
			ret
