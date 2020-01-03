# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:45:58 by pcuadrad          #+#    #+#              #
#    Updated: 2019/12/04 14:42:26 by pcuadrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_split.c ft_strcat.c \
	ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c ft_swap.c \
	ft_tolower.c ft_toupper.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstclear_bonus.c get_next_line.c \
	destructor.c initialize.c processline.c ft_printf.c reinitialize.c check_flags.c \
	check_width.c check_precisition.c check_conversion.c executer.c putspaces.c \
	ft_putnstr.c putstr_printf.c ft_strldup.c putchar_printf.c putpercent_printf.c putzeros.c \
	putnbr_printf.c ft_nbrlen.c putnbr_printf_aux.c putnbr_printf_aux2.c \
	putunsigned_printf.c putunsigned_printf_aux.c puthex_printf.c puthex_printf_aux.c \
	putmemory_printf.c putmemory_printf_aux.c putmemory_printf.c putmemory_printf_aux.c \
	putnbr_plus_space.c putintpointer_printf.c \

NAME = libft.a

COMMAND = ar rc ${NAME} ${OBJS}

COMMAND2 = ranlib ${NAME}

GCC = gcc -Wall -Werror -Wextra -g

OBJS = ${SRCS:.c=.o}

RM = rm -f

.c.o:
			@${GCC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} libft.h
			@${COMMAND}
			@${COMMAND2}

all:		$(NAME)

re:			fclean all

clean:
			@${RM} ${OBJS}

fclean:
			@${RM} ${NAME}
