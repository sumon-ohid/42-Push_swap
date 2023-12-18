# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 08:14:24 by msumon            #+#    #+#              #
#    Updated: 2023/12/18 20:00:25 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			= 	ft_atoi.c ft_isdigit.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
					ft_strchr.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_split.c ft_atol.c
OBJS			= $(SRCS:.c=.o)

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re