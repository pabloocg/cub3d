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

# --------------------Rutas----------------------------#

SRCS_PATH = srcs/

BONUS_PATH = bonus/

OBJS_PATH = objs/

INCLUDES_PATH = includes/

LIBFT_PATH = srcs/libft

#--------------------Recursos---------------------------#

SRCS =	main.c keys.c print_graph.c raycasting.c initialize.c \
		check_map.c move_player.c bmp.c free.c raycasting_sprites.c utilities.c \
		check_map_param.c check_map_param2.c get_options.c get_options_utils.c \
		charge_textures.c \

BONUS_SRCS = main_bonus.c keys_bonus.c print_graph_bonus.c raycasting_bonus.c \
		initialize_bonus.c check_map_bonus.c move_player_bonus.c bmp_bonus.c \
		free_bonus.c raycasting_sprites_bonus.c utilities_bonus.c \
		check_map_param_bonus.c check_map_param2_bonus.c get_options_bonus.c \
		get_options_utils_bonus.c charge_textures_bonus.c print_minimap_bonus.c \
		print_hud_bonus.c shot.c floorceilling.c animate_sprite.c attack.c \
		fuck_norminnete.c utilities_bonus_2.c fuck_norminnete2.c print_hud2_bonus.c \

INCLUDES = cub3d.h

INCLUDE_BONUS = cub3d_bonus.h

NAME = cub3d

LIB_LIBFT = libft.a

#--------------------Comandos---------------------------#

GCC = gcc -Wall -Werror -Wextra

FLAGS = -L ${LIBFT_PATH} -lft -lmlx -framework OpenGL -framework Appkit

#FLAGS = -L ${LIBFT_PATH} -lft -Lminilibx -lmlx -framework OpenGL -framework Appkit

CREATEMKDIR = @mkdir -p objs

OBJS = ${addprefix ${SRCS_PATH}, ${SRCS:.c=.o}}

OBJSBONUS = ${addprefix ${BONUS_PATH}, ${BONUS_SRCS:.c=.o}}

TEST = ${addprefix ${TEST_PATH}, ${TESTS:.c=.o}}

RM = rm -f

#---------------------Ordenes---------------------------#

.c.o:
			${CREATEMKDIR}
			@${GCC} -c $< -o ${addprefix ${OBJS_PATH}, ${notdir ${<:.c=.o}}}

$(NAME):	${OBJS} ${addprefix ${INCLUDES_PATH}, ${INCLUDE}}
			@make -C ${LIBFT_PATH}
			${GCC} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}} ${FLAGS} -o ${NAME}

bonus:		${OBJSBONUS} ${addprefix ${INCLUDES_PATH}, ${INCLUDE_BONUS}}
			@make -C ${LIBFT_PATH}
			${GCC} ${addprefix ${OBJS_PATH}, ${notdir ${OBJSBONUS}}} ${FLAGS} -o ${NAME}

all:		$(NAME)

re:			fclean all

clean:
			@${RM} ${addprefix ${OBJS_PATH}, ${notdir ${OBJS}}}

fclean:
			@${RM} ${NAME}
