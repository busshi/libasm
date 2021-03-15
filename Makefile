# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:12:59 by aldubar           #+#    #+#              #
#    Updated: 2021/03/15 11:08:13 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

HEADER	=	includes/libasm.h

SRCS	=	strlen.s

OK	=	[ \e[0;32mok\e[0m ]

ASM	=	@nasm

CC	=	@clang

AFLAGS	=	-f elf64

CFLAGS	=	-Wall -Wextra -Werror

RM	=	@rm -f

OBJS	=	$(addprefix srcs/ft_, $(SRCS:.s=.o))

.s.o:
		$(ASM) $(AFLAGS) $<

$(NAME):	$(OBJS)
		@echo "Compiling libasm..."
		@ar rcs $(NAME) $(OBJS)
		@echo "$(OK) libasm build !"

all:		$(NAME)

clean:
		@echo "Cleaning..."
		$(RM) $(OBJS)
		@echo "$(OK) Cleaned !"

fclean:		clean
		$(RM) $(NAME)
		@echo "$(OK) Fcleaned!"

.PHONY:		all clean fclean re bonus
