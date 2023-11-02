# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 11:08:27 by aakhtab           #+#    #+#              #
#    Updated: 2023/10/22 17:28:05 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
#================

CC			=	cc

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c        \
					ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c     \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strncmp.c        \
					ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c         \
					ft_strlcat.c ft_striteri.c ft_strlcpy.c ft_strlen.c       \
					ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c     \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c         \
					ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c    \
					ft_putendl_fd.c ft_putnbr_fd.c 	ft_lstnew.c  \
					ft_lstadd_front.c ft_lstsize.c	ft_lstadd_back.c 	\
					ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
					ft_putunbr.c ft_puthex.c ft_putadd.c	\
					get_next_line.c get_next_line_utils.c ft_strcmp.c


OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libft.a


all:	${NAME}


${NAME}:	${OBJS}
	@ar -rc ${NAME} ${OBJS}
	@printf "$(GREEN)\r======> YOUR LIB IS READY ✅\n$(RESET)"

${OBJS}:
	@printf "$(GRAY)\r======> MAKING YOUR LIB ...$(RESET)"
	@${CC} ${CFLAGS} -c ${SRCS}

clean:	
	@rm -f $(OBJS)

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
