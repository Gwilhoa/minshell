# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:35:56 by gchatain          #+#    #+#              #
#    Updated: 2022/06/28 14:40:57 by gchatain         ###   ########lyon.fr    #
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

NAME		:= libft.a
FLAGS		:= -Werror -Wall -Wextra -g3 #-fsanitize=address
CC			:= gcc

LST_CONVERT		:= ft_atoi.c ft_itoa.c ft_split.c
LST_GNL			:= get_next_line.c
LST_ISCHAR		:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c
LST_LST_FUNC	:= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
LST_MATRIX_FUNC	:= ft_disp_matrix.c ft_free_matrix.c ft_matrix_dup.c ft_matrix_size.c ft_push_back_matrix.c ft_push_matrix.c
LST_MEM			:= ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
LST_MODIFY_STR	:= ft_delchar.c
LST_PRINT		:= ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c printf_function.c
LST_STR			:= ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c


LST_SRCS		:=	$(addprefix conversion/,$(LST_CONVERT)) \
					$(addprefix get_next_line/,$(LST_GNL)) \
					$(addprefix ischar/,$(LST_ISCHAR)) \
					$(addprefix lst_function/,$(LST_LST_FUNC)) \
					$(addprefix matrix_function/,$(LST_MATRIX_FUNC)) \
					$(addprefix memory/,$(LST_MEM)) \
					$(addprefix modify_string/,$(LST_MODIFY_STR)) \
					$(addprefix print/,$(LST_PRINT)) \
					$(addprefix string/,$(LST_STR))

LST_OBJS		:= $(LST_SRCS:.c=.o)
OBJS			:= $(addprefix .objects/,$(LST_OBJS))
SRCS			:= $(addprefix sources/,$(LST_SRCS))

INCLUDES		:= includes/libft.h includes/get_next_line.h
DIR_INCLUDES	:= $(sort $(addprefix -I, $(dir $(INCLUDES))))

NORM		:= $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "$(ERASE)$(GREEN)[DONE]$(END) $(NAME)\n"
else
	NORM_RET = "$(ERASE)$(RED)[NORM]$(END) $(NAME)\n"
endif

all: $(NAME)

.objects/%.o:	sources/%.c ${INCLUDES} | .objects
			${CC} ${FLAGS} -c $< -o $@ ${DIR_INCLUDES}
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

${NAME}:	${OBJS} ${INCLUDES} Makefile
		ar -rcs ${NAME} ${OBJS} $(LIB)
		printf ${NORM_RET}

clean:
			${RM} ${OBJS}
			printf "${RED}[DELETE]${END} directory .objects"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:			fclean all

.objects:
			mkdir -p .objects
			mkdir -p .objects/conversion
			mkdir -p .objects/get_next_line
			mkdir -p .objects/ischar
			mkdir -p .objects/lst_function
			mkdir -p .objects/matrix_function
			mkdir -p .objects/memory
			mkdir -p .objects/modify_string
			mkdir -p .objects/print
			mkdir -p .objects/string

.PHONY: all re fclean clean compilation
.SILENT: