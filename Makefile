# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:26:21 by tnguyen-          #+#    #+#              #
#    Updated: 2022/01/15 18:43:45 by tnguyen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCS	= ft_strncmp.c main.c ft_putstr_fd.c ft_strlen.c fractol_utils.c \
	mandelbrot.c mandelbrot_utils.c ft_fracmove.c Julia.c julia_utils.c \
	fractol_utils2.c

OBJ	= ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra -Ofast -I.

LIB = libmlx.dylib
LIB_CHECK = mlx/libmlx.dylib

all: ${NAME}

%.o: %.c fractol.h
	$(CC) ${FLAGS} -Imlx -c $< -o $@

${NAME}: $(LIB) ${OBJ} 
	$(CC) ${FLAGS} $(OBJ) -framework OpenGL -framework AppKit -o $(NAME) mlx/libmlx.dylib

${LIB}: $(LIB_CHECK)
	cp $(LIB_CHECK) .

$(LIB_CHECK):
	make -C mlx

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all