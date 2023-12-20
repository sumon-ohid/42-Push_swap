# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/12/20 10:30:41 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/push_swap.c ./srcs/ps_utils.c ./srcs/multi_free.c ./srcs/ft_rules.c \
				./srcs/sort_stack.c ./srcs/sort_small.c ./srcs/sorting_utils.c \
				./srcs/multi_free1.c
CC			= cc
RM			= rm -f
NAME		= push_swap
OBJS		= $(SRCS:.c=.o)
LIBFT		= ./libft/
FTPRINTF	= ./libft/ft_printf/
CFLAGS		= -Wall -Werror -Wextra -g

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
	@echo ======== push_swap created! =========

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@echo ======== Object files removed! ========

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@echo ======== push_swap removed! ========

re: fclean all

.PHONY: all libft ft_printf clean fclean re