# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 11:38:35 by gclausse          #+#    #+#              #
#    Updated: 2022/01/31 12:45:13 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    =    so_long

SRCS    = so_long.c

OBJS    =    ${SRCS:.c=.o}

CC        =    clang
#CC        =    clang-9
RM        =    rm -f
CFLAGS    =    -Wall -Werror -Wextra
#-fsanitize=address -fsanitize=leak -g3

MLX        = ./mlx_linux

MLX_LIB = ./mlx_linux/libmlx_Linux.a

INCL    =    includes

.c.o:
	${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
	${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
	make -C ${MLX} -j


all:        ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ${MLX}

fclean:        clean
	${RM} ${NAME}
	${RM} ${NAME} ${MLX_LIB}

re:            fclean
	$(MAKE) all -j

.PHONY:        all clean fclean re


#-framework OpenGL -framework AppKit

