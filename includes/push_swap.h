/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:33 by msumon            #+#    #+#             */
/*   Updated: 2023/12/15 10:07:53 by msumon           ###   ########.fr       */
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
	int				rank;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// ****** utils ******
void				error_msg(void);
int					num_validator(char **str, int *arr);
void				print_stack(t_stack *stack);
int					is_sorted(t_stack *a);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					rotate_until_min(t_stack **stack, int num);
int					rra_until_min(t_stack **a, int min);
int					argv_lenght(char **argv);
int					arr_size_count(int *arr);
int					get_stack_size(t_stack **stack_1);
t_stack				*create_stack(int *num, int i, int len);
t_stack				*get_last_element(t_stack *stack_last);

// ****** sorts ******
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b, int size);
void				sort_five(t_stack **a, t_stack **b, int size);
void				sort_stack(t_stack **a, t_stack **b);

// ****** rules ******
void				sa(t_stack **a);
void				sb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rra(t_stack **a);

// ****** multi_free ******
void				free_stack(t_stack *stack);
void				free_char_list(char **nbr_list);
void				free_all(char *str, int *arr, char **nbr_list);
void				free_void(void *ptr);

#endif