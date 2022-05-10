# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 10:03:39 by gchatain          #+#    #+#              #
#    Updated: 2022/05/10 14:24:50 by gchatain         ###   ########lyon.fr    #
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

NAME		:= minishell
FLAGS		:= -Werror -Wall -Wextra
CC			:= gcc

LST_BUILT_IN	:= cd.c exit.c export.c pwd.c unset.c echo.c
LST_SRCS		:= env_utils.c execute_path.c main.c signal.c $(addprefix built-in/,$(LST_BUILT_IN))

LST_OBJS		:= $(LST_SRCS:.c=.o)
OBJS			:= $(addprefix .objects/,$(LST_OBJS))
SRCS			:= $(addprefix sources/,$(LST_SRCS))
LIBFT			:= libft/libft.a

INCLUDES		:= includes/ libft/includes/libft.h $(shell brew --prefix readline)/include/
DIR_INCLUDES	:= $(sort $(addprefix -I, $(dir $(INCLUDES))))

NORM		:= $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "$(ERASE)$(GREEN)[DONE]$(END) $(NAME)\n"
else
	NORM_RET = "$(ERASE)$(RED)[NORM]$(END) $(NAME)\n"
endif

all: compilation $(NAME)

.objects/%.o:	sources/%.c ${INCLUDES} | .objects
			${CC} ${FLAGS} -c $< -o $@ ${DIR_INCLUDES}
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

$(NAME): $(OBJS) Makefile $(INCLUDES)
		${CC} ${FLAGS} -o ${NAME} -lreadline -L$(shell brew --prefix readline)/lib ${OBJS} ${LIBFT} ${DIR_INCLUDES}
		printf $(NORM_RET)

clean:
			${RM} ${OBJS}
			@make fclean -s -C libft
			printf "${RED}[DELETE]${END} directory .objects"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:			fclean all

.objects:
			mkdir -p .objects
			mkdir -p .objects/built-in
	

compilation:
	make -s -C libft
.PHONY: all re fclean clean compilation
.SILENT: