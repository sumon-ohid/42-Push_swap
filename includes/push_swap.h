/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 15:14:10 by msumon           ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					error_msg(void);
int					check_arg(int argc, char **argv);
t_stack				*create_stack(int *num, int i);
void				print_stack(t_stack *stack);
void				sa(t_stack *a);

#endif