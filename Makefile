# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 17:27:13 by pablo             #+#    #+#              #
#    Updated: 2020/01/10 14:00:05 by pcuadrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------Paths----------------------------#

SRCS_PATH = srcs/

OBJS_PATH = objs/

INCLUDES_PATH = includes/

LIBFT_PATH = srcs/libft

MINILIBX_PATH = minilibx

#--------------------Sources---------------------------#

SRCS = main.c keys.c print_graph.c raycasting.c \
		initialize.c check_map.c move_player.c bmp.c \
		free.c raycasting_sprites.c utilities.c \
		check_map_param.c check_map_param2.c get_options.c \
		get_options_utils.c charge_textures.c print_minimap.c \
		print_hud.c shot.c floorceilling.c animate_sprite.c attack.c \
		fuck_norminnete.c utilities_2.c fuck_norminnete2.c print_hud2.c \

INCLUDES = cub3d.h

NAME = cub3d

LIB_LIBFT = libft.a

#--------------------Shortcouts---------------------------#

GCC = gcc -Wall -Werror -Wextra

FLAGS = -L ${LIBFT_PATH} -lft -L ${MINILIBX_PATH} -lmlx -framework OpenGL -framework Appkit

CREATEMKDIR = @mkdir -p objs

OBJS = ${addprefix ${SRCS_PATH}, ${SRCS:.c=.o}}

RM = rm -f

#---------------------Commands---------------------------#

.c.o:
			${CREATEMKDIR}
			@${GCC} -c $< -o ${addprefix ${OBJS_PATH}, ${notdir ${<:.c=.o}}}

$(NAME):	${OBJS} ${addprefix ${INCLUDES_PATH}, ${INCLUDE}}
			@make -C ${LIBFT_PATH}
			@make -C ${MINILIBX_PATH}
			${GCC} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}} ${FLAGS} -o ${NAME}

all:		$(NAME)

re:			fclean all

clean:
			@${RM} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}}
			@make -C ${LIBFT_PATH} clean

fclean:
			@${RM} ${NAME}
			@make -C ${LIBFT_PATH} fclean
