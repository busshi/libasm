# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:12:59 by aldubar           #+#    #+#              #
#    Updated: 2021/03/21 18:04:17 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

TEST		=	libasm

SRCS		=	strlen.s \
			strcmp.s \
			strcpy.s \
			strdup.s \
			write.s \
			read.s

SRCS_BONUS	=	list_size_bonus.s \
			list_push_front_bonus.s

SRCS_TEST	=	main.c \
			check_strdup.c \
			check_write.c \
			check_read.c \
			error_read.c \
			utils.c

SRCS_TEST_BONUS	=	main_bonus.c \
			check_strdup.c \
			check_write.c \
			check_read.c \
			error_read.c \
			utils_bonus.c

OK		=	[ \033[0;32mok\033[0m ]

ASM		=	@nasm

CC		=	@clang

AFLAGS		=	-felf64

CFLAGS		=	-Wall -Wextra -Werror

RM		=	@rm -f

OBJS		=	$(addprefix srcs/ft_, $(SRCS:.s=.o))

OBJS_BONUS	=	$(addprefix srcs/ft_, $(SRCS_BONUS:.s=.o))

OBJS_TEST	=	$(addprefix tests/, $(SRCS_TEST:.c=.o))

OBJS_TEST_BONUS	=	$(addprefix tests/, $(SRCS_TEST_BONUS:.c=.o))

.s.o:
		$(ASM) $(AFLAGS) $<

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJS_TEST)
		@echo "Compiling libasm..."
		@ar rcs $(NAME) $(OBJS)
		@echo "$(OK) libasm build !"
		@echo "Compiling tests..."
		$(CC) $(CFLAGS) $(OBJS_TEST) -L. -lasm -o $(TEST)
		@echo "$(OK) Tests build ! ==> Run ./$(TEST)"

all:		$(NAME)

bonus:		$(OBJS) $(OBJS_BONUS) $(OBJS_TEST_BONUS)
		@echo "Compiling libasm..."
		@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
		@echo "$(OK) libasm with bonus build !"
		@echo "Compiling bonus tests..."
		$(CC) $(CFLAGS) $(OBJS_TEST_BONUS) -L. -lasm -o $(TEST)
		@echo "$(OK) Bonus tests build ! ==> Run ./$(TEST)"
clean:
		@echo "Cleaning..."
		$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_TEST) $(OBJS_TEST_BONUS) $(TEST)
		@echo "$(OK) Cleaned !"

fclean:		clean
		$(RM) $(NAME)
		@echo "$(OK) Fcleaned!"

re:		fclean all

.PHONY:		all clean fclean re bonus
