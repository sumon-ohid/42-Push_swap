/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
/*   Updated: 2023/12/05 20:32:19 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int 			size;
	struct s_stack	*next;
}					t_stack;

int			error_msg(void);
int			check_arg(int argc, char **argv);
t_stack		*create_stack(int argc, char **argv, t_stack *stack);
void		print_stack(t_stack *stack);

#endif