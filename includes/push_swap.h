/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
/*   Updated: 2023/12/01 14:38:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
    int				data;
    struct s_stack	*next;
}			   t_stack;

void        error_msg(char *msg);
int         check_arg(int argc, char **argv);
t_stack	    *create_stack(int argc, char **argv);

#endif