# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:35:56 by gchatain          #+#    #+#              #
#    Updated: 2022/02/02 14:51:59 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

LST_SRCS =   ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c\
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c\
ft_printf.c printf_function.c

LST_OBJS = ${LST_SRCS:.c=.o}
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/libft.h
DIR_INCLUDES = $(sort $(addprefix -I, $(dir $(INCLUDES))))
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = libft.a
RM          = rm -f

all:        ${NAME}

.objects/%.o:		sources/%.c ${INCLUDES} | .objects
		${CC} ${CFLAGS} -c $< -o $@ ${DIR_INCLUDES}
		printf "${ERASE}${YELLOW}[BUILD]${END} $@"

${NAME}:	${OBJS} ${INCLUDES} Makefile
		ar -rcs ${NAME} ${OBJS}
		printf "${ERASE}${GREEN}[DONE]${END} ${NAME}\n"

clean:
		${RM} ${OBJS}
		printf "${RED}[DELETE]${END} objects directory"

fclean:	clean
		${RM} -r ${NAME} .objects
		printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:		fclean all

.objects:
		mkdir -p .objects

.PHONY:	all clean fclean re

.SILENT:
