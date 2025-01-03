# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 15:13:25 by yel-bouk          #+#    #+#              #
#    Updated: 2025/01/02 16:33:45 by yel-bouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -g3
RM = rm -f

SRCS = \
    ./libft/ft_split.c \
    ./libft/ft_atoi.c \
    ./libft/ft_strncpy.c \
    ./libft/ft_bzero.c \
    ./libft/ft_isdigit.c \
    ./libft/ft_lstsize.c \
    ./libft/ft_calloc.c \
    ./src/operation_commands/push.c \
    ./src/operation_commands/reverse.c \
    ./src/operation_commands/rotate.c \
    ./src/operation_commands/swap.c \
    ./src/algorithm/sort_three.c \
    ./src/main.c \
    ./src/stack_manipulation.c \
    ./src/utils/utils.c \
    ./src/utility.c \
    ./src/input_handler.c 
OBJS = $(SRCS:.c=.o)

FT_PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re