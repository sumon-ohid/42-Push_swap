# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/11/29 22:30:09 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/push_swap.c
CC			= cc
RM			= rm -f
NAME		= push_swap
OBJS		= $(SRCS:.c=.o)
LIBFT		= ./libft/
CFLAGS		= -Wall -Werror -Wextra

GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT) all
  
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a -o $(NAME)
	@echo ${GREEN}======== push_swap created! =========

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@echo ${BLUE}======== push_swap removed! ========

re: fclean all

.PHONY: all libft clean fclean re
.SILENT: