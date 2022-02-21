# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 11:38:35 by gclausse          #+#    #+#              #
#    Updated: 2022/02/21 13:38:46 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    =    so_long

SRCS    = check_map_utils.c \
	  check_files.c \
	  get_valid_map.c \
	  manage_errors.c \
	  parse_map.c \
	  display.c \
	  init_textures.c \
	  direction.c \


OBJS    =    ${SRCS:.c=.o}


%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

CC        =    gcc
#CC        =    clang-9
RM        =    rm -f
CFLAGS    =    -Wall -Werror -Wextra
#-fsanitize=address -fsanitize=leak -g3

MLX        = ./mlx_linux

MLX_LIB = ./mlx_linux/libmlx_Linux.a

LIBFT= ./libft/libft.a

all:        ${NAME}

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(addprefix ,$(SRCS)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./mlx_linux -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -o $(NAME)	

$(MLX_LIB):
	cd ./mlx_linux && ./configure

$(LIBFT):
	make -C libft
	

clean:
	${RM} ${OBJS}
	make clean -C ${MLX}
	make clean -C libft

fclean:        clean
	${RM} ${NAME}
	make fclean -C libft
	${RM} ${NAME} ${MLX_LIB}

re:            fclean
	$(MAKE) all -j

.PHONY:        all clean fclean re


#-framework OpenGL -framework AppKit

