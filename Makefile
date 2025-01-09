# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 15:13:25 by yel-bouk          #+#    #+#              #
#    Updated: 2025/01/09 15:16:32 by yel-bouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = \
    ./libft/ft_split.c \
    ./libft/ft_atoi.c \
    ./libft/ft_strncpy.c \
    ./libft/ft_bzero.c \
    ./libft/ft_isdigit.c \
    ./libft/ft_lstsize.c \
    ./libft/ft_calloc.c \
    ./libft/ft_strdup.c \
    ./libft/ft_strjoin.c \
    ./libft/ft_strlcat.c \
    ./libft/ft_strlcpy.c \
    ./src/value_finder.c \
    ./src/push_swap.c \
    ./src/error_handler.c \
    ./src/sorting_algo.c \
    ./src/helper_functions.c \
    ./src/main.c \
    ./src/Input_handler/argc_to_str.c \
    ./src/commands/push.c \
    ./src/commands/swap.c \
    ./src/commands/reverse.c \
    ./src/commands/rotate.c \
    ./src/utility.c \
    ./src/stack_manipulation.c \
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