# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:14:34 by aldubar           #+#    #+#              #
#    Updated: 2021/03/22 11:59:07 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; ssize_t	ft_write(int rdi, void *rsi, size_t rdx)


	global		ft_write

	extern		__errno_location

	section		.text

ft_write:
			mov	rax, 1				; write function in rax
			syscall					; call write
			cmp	rax, 0				; error ?
			jl	error
			ret

	error:
			neg	rax				; absolute value of rax
			mov	rdi, rax			; save rax in rdi
			call	__errno_location wrt ..plt
			mov	[rax], rdi			; retrieve rax saved in rdi
			mov	rax, -1
			ret
