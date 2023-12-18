# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/12/18 19:57:49 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/push_swap.c ./srcs/ps_utils.c ./srcs/multi_free.c ./srcs/ft_rules.c \
				./srcs/sort_stack.c ./srcs/sort_small.c ./srcs/sorting_utils.c
CC			= cc
RM			= rm -f
NAME		= push_swap
OBJS		= $(SRCS:.c=.o)
LIBFT		= ./libft/
FTPRINTF	= ./libft/ft_printf/
CFLAGS		= -Wall -Werror -Wextra

GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)
RED 		= $(shell tput -Txterm setaf 1)

all: libft ft_printf $(NAME)

libft:
	@$(MAKE) -C $(LIBFT) all

ft_printf:
	@$(MAKE) -C $(FTPRINTF) all
  
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF)libftprintf.a $(LIBFT)libft.a -o $(NAME)
	@echo ${GREEN}======== push_swap created! =========

clean:
	@echo ${RED}
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@echo ${RED}======== Object files removed! ========

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@echo ${RED}======== push_swap removed! ========

re: fclean all

.PHONY: all libft ft_printf clean fclean re