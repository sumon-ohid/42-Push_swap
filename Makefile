# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/12/07 08:33:51 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/push_swap.c ./srcs/ps_utils.c ./srcs/multi_free.c ./srcs/ft_rules.c \
				./srcs/ft_rules1.c ./srcs/ft_rules2.c ./srcs/sort_stack.c
CC			= cc
RM			= rm -f
NAME		= push_swap
OBJS		= $(SRCS:.c=.o)
LIBFT		= ./libft/
FTPRINTF	= ./libft/ft_printf/
GNL			= ./libft/get_next_line/
CFLAGS		= -g -Wall -Werror -Wextra

GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)
RED 		= $(shell tput -Txterm setaf 1)

all: libft gnl ft_printf $(NAME)

libft:
	@$(MAKE) -C $(LIBFT) all

ft_printf:
	@$(MAKE) -C $(FTPRINTF) all

gnl:
	@$(MAKE) -C $(GNL) all
  
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF)libftprintf.a $(GNL)gnl.a $(LIBFT)libft.a -o $(NAME)
	@printf "${GREEN}"
	@echo "╔════════════════════════════════════════════════════╗"
	@echo "║                     Welcome to                     ║"
	@echo "║                  Push Swap Compiler                ║"
	@echo "╚════════════════════════════════════════════════════╝"
	@echo "${BLUE}Compiling: "
	@for i in $$(seq 0 2 100); do \
		sleep 0.01; \
		printf "\033[1;33m#"; \
	done
	@printf " 100%%\n"
	@echo ${GREEN}======== push_swap created! =========

clean:
	@echo ${RED}
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@echo ${RED}======== Object files removed! ========

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@echo ${RED}======== push_swap removed! ========

re: fclean all

.PHONY: all libft ft_printf gnl clean fclean re
.SILENT: