# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/12/20 13:58:44 by msumon           ###   ########.fr        #
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

all: $(NAME)
  
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT) all
	@$(MAKE) --no-print-directory -C $(FTPRINTF) all
	@$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF)libftprintf.a $(LIBFT)libft.a -o $(NAME)
	@echo ======== push_swap created! =========

clean:
	@$(RM) $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@$(MAKE) --no-print-directory -C $(FTPRINTF) clean
	@echo ======== Object files removed! ========

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@$(MAKE) --no-print-directory -C $(FTPRINTF) fclean
	@echo ======== push_swap removed! ========

re: fclean all

.PHONY: all clean fclean re