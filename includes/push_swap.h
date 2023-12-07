/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 08:39:36 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ****** includes ******
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"

// ****** linked list ******
typedef struct s_stack
{
	int				data;
	int				size;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// ****** utils ******
void				error_msg(void);
int					check_arg(int argc, char **argv);
t_stack				*create_stack(int *num, int i);
void				print_stack(t_stack *stack);
int					is_sorted(t_stack *a);
void				sort_stack(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
int					find_min(t_stack *stack);

// ****** rules ******
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// ****** multi_free ******
void				free_stack(t_stack *stack);
void				free_char_list(char **nbr_list);
void				free_all(t_stack *a, t_stack *b, char **nbr_list);
void    			free_num(int *num);

#endif