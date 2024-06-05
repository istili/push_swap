# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istili <istili@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 09:53:55 by istili            #+#    #+#              #
#    Updated: 2024/06/04 16:08:42 by istili           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -ggdb3

RM				=	rm -rf

HEADER			=	mandatory/push_swap.h

HEADER_2		=	mandatory/mandatory.h

HEADER_BONUS	=	bonus/push_swap_bonus.h bonus/get_next_line/get_next_line.h

FILE			=	mandatory/sort_small.c mandatory/ft_atoi.c mandatory/ft_split.c mandatory/helpers.c \
		mandatory/libc.c mandatory/main.c mandatory/action_push.c mandatory/action_reverse.c mandatory/action_rotate.c \
		mandatory/action_swap.c mandatory/free.c mandatory/chunks.c mandatory/sort_stack.c mandatory/stack_init.c mandatory/to_a.c \
		mandatory/main_utils.c	mandatory/stack.c mandatory/sort_utils.c mandatory/ac_checks.c\

FILE_BONUS		=	bonus/cmp_bonus.c	bonus/parsing_bonus.c	bonus/reverse_bonus.c \
		bonus/ft_atoi_bonus.c	bonus/libc_bonus.c	bonus/checks_bonus.c	bonus/rotate_bonus.c \
		bonus/ft_split_bonus.c	bonus/main_bonus.c		bonus/swap_bonus.c			bonus/push_bonus.c\
		bonus/main_utils_bonus.c bonus/get_next_line/get_next_line.c		bonus/get_next_line/get_next_line_utils.c \

OBJS			=	$(FILE:.c=.o)

OBJS_BONUS		=	$(FILE_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -fsanitize=address -ggdb3 $(OBJS) -o $(NAME)

%.o : %.c $(HEADER) $(HEADER_2) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
