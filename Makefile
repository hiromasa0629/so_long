# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 13:05:02 by hyap              #+#    #+#              #
#    Updated: 2022/07/07 13:43:07 by hyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard srcs/*.c} ${wildcard gnl/*.c}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBMLX = libmlx.dylib

LIBFTPRINTF = libftprintf.a

FSANITIZE = -fsanitize=address 

NAME = so_long

RM = rm -f

all: ${NAME}

${NAME}: ${SRCS}
	${CC} ${CFLAGS} -I includes ${SRCS} ${LIBMLX} ${LIBFTPRINTF} -o ${NAME}

clean:
	${RM} ${NAME}

fclean:
	${RM} ${NAME}

re: clean all

.PHONY: all clean re