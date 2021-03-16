# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:12:59 by aldubar           #+#    #+#              #
#    Updated: 2021/03/16 10:53:22 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

TEST		=	libasm

SRCS		=	strlen.s \
			strcmp.s \
			strcpy.s \
			strdup.s

SRCS_TEST	=	main.c \
			check_strdup.c

OK		=	[ \033[0;32mok\033[0m ]

ASM		=	@nasm

CC		=	@clang

AFLAGS		=	-felf64

CFLAGS		=	-Wall -Wextra -Werror

RM		=	@rm -f

OBJS		=	$(addprefix srcs/ft_, $(SRCS:.s=.o))

OBJS_TEST	=	$(addprefix tests/, $(SRCS_TEST:.c=.o))

.s.o:
		$(ASM) $(AFLAGS) $<

.c.o:
		$(CC) $(CFLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJS_TEST)
		@echo "Compiling libasm..."
		@ar rcs $(NAME) $(OBJS)
		@echo "$(OK) libasm build !"
		@echo "Compiling tests..."
		$(CC) $(CFLAGS) $(OBJS_TEST) -L. -lasm -o $(TEST)
		@echo "$(OK) Tests build ! ==> Run ./$(TEST)"

all:		$(NAME)

clean:
		@echo "Cleaning..."
		$(RM) $(OBJS) $(OBJS_TEST) $(TEST)
		@echo "$(OK) Cleaned !"

fclean:		clean
		$(RM) $(NAME)
		@echo "$(OK) Fcleaned!"

re:		fclean all

.PHONY:		all clean fclean re bonus
