/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/06 15:19:12 by msumon           ###   ########.fr       */
=======
/*   Updated: 2023/12/05 20:32:19 by msumon           ###   ########.fr       */
>>>>>>> parent of 3a554d0 (OK)
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
<<<<<<< HEAD
=======
	int 			size;
>>>>>>> parent of 3a554d0 (OK)
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

<<<<<<< HEAD
int					error_msg(void);
int					check_arg(int argc, char **argv);
t_stack				*create_stack(int *num, int i);
void				print_stack(t_stack *stack);
void				sort_stack(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
=======
int			error_msg(void);
int			check_arg(int argc, char **argv);
t_stack		*create_stack(int argc, char **argv, t_stack *stack);
void		print_stack(t_stack *stack);
>>>>>>> parent of 3a554d0 (OK)

#endif