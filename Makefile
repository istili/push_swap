# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istili <istili@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 09:53:55 by istili            #+#    #+#              #
#    Updated: 2024/04/26 18:00:48 by istili           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BONUS	=	checker
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
rm			=	rm -rf

HEADER		=	push_swap.h

HEADER_BONUS	=	push_swap_bonus.h

FILE	=	mandatory/algo.c mandatory/ft_atoi.c mandatory/ft_split.c mandatory/helpers.c \
	mandatory/libc.c mandatory/main.c mandatory/push.c mandatory/reverse.c mandatory/rotate.c \
	mandatory/chunks.c mandatory/sort_stack.c mandatory/stack_init.c mandatory/swap.c mandatory/to_a.c \
	mandatory/to_b.c mandatory/utils.c mandatory/stack1.c mandatory/stack2.c mandatory/more_utils.c mandatory/parsing.c\

FILE_BONUS	=	bonus/cheker_bonus.c	bonus/parsing_bonus.c	bonus/reverse_bonus.c \
	bonus/ft_atoi_bonus.c	bonus/libc_bonus.c	bonus/checks_bonus.c	bonus/rotate_bonus.c \
	bonus/ft_split_bonus.c	bonus/main_bonus.c	bonus/swap_bonus.c	bonus/push_bonus.c\
	bonus/get_next_line/get_next_line.c		bonus/get_next_line/get_next_line_utils.c \

OBJS	=	$(FILE:.c=.o)

OBJS_BONUS	=	$(FILE_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re