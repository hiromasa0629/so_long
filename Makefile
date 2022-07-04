# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 13:05:02 by hyap              #+#    #+#              #
#    Updated: 2022/07/04 14:47:02 by hyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.c

CLIENT = client.c

SRCS = ${wildcard srcs/*.c} ${wildcard gnl/*.c}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBMLX = libmlx.dylib

LIBFTPRINTF = libftprintf.a

FSANITIZE = -fsanitize=address 

NAME = so_long

RM = rm -f

all:
	${CC} ${CFLAGS} -I includes ${SRCS} ${LIBMLX} ${LIBFTPRINTF} -o ${NAME}

clean:
	${RM} ${NAME}

fclean:
	${RM} ${NAME}

run:
	./${NAME}

re: clean all

.PHONY: all clean re