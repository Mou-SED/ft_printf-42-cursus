# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 15:46:36 by moseddik          #+#    #+#              #
#    Updated: 2021/12/11 18:27:22 by moseddik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

HEADER = ft_printf.h

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar -rcs $@ $^

all: $(NAME) 

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: clean fclean re
