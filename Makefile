# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/12/04 17:19:55 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/push_swap.c ./srcs/utils.c ./srcs/error_msg.c
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
	@printf "${GREEN}"
	@echo "╔════════════════════════════════════════════════════╗"
	@echo "║                     Welcome to                     ║"
	@echo "║                  Push Swap Compiler                ║"
	@echo "╚════════════════════════════════════════════════════╝"
	@echo "${BLUE}Compiling: "
	@for i in $$(seq 0 2 100); do \
		sleep 0.1; \
		printf "\033[1;33m#"; \
	done
	@printf " 100%%\n"
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