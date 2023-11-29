# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 08:14:24 by msumon            #+#    #+#              #
#    Updated: 2023/11/29 22:28:56 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			= 	ft_atoi.c ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_isdigit.c ft_strlen.c ft_toupper.c ft_tolower.c \
					ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_strchr.c ft_strrchr.c ft_memchr.c ft_strncmp.c ft_memcmp.c \
					ft_strnstr.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
					ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c
FTPRINTF		= ./ft_printf/
GNL				= ./get_next_line/
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a
GREEN			= $(shell tput -Txterm setaf 2)
BLUE			= $(shell tput -Txterm setaf 4)

all: gnl ftprintf $(NAME)

gnl:
	@$(MAKE) -C $(GNL) all
	@echo ${GREEN}======== get_next_line ========

ftprintf:
	@$(MAKE) -C $(FTPRINTF) all
	@echo ${GREEN}======== ft_printf =========

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): gnl ftprintf $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo ${GREEN}======== libft compiled ========
	@echo ${GREEN}======== libft.a Created! ========

clean:
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@$(RM) $(OBJS)
	@echo ${BLUE}======== Libft Object Files Removed! ========

fclean: clean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(RM) $(NAME)
	@echo ${BLUE}======== libft.a Removed! ========

re: fclean all

.PHONY: all clean fclean re
.SILENT:
