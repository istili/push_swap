# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istili <istili@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 09:53:55 by istili            #+#    #+#              #
#    Updated: 2024/04/19 17:44:41 by istili           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -ggdb3
rm		=	rm -rf

HEADER	=	push_swap.h

FILE	=	algo.c ft_atoi.c ft_split.c helpers.c libc.c main.c push.c \
		reverse.c rotate.c chunks.c sort_stack.c stack_init.c swap.c \
		to_a.c to_b.c utils.c stack1.c stack2.c more_utils.c \

OBJS	=	$(FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
