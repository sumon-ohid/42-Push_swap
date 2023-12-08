/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 23:48:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}
void	sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = find_min(*a);
	max = find_max(*a);
	if ((*a)->data != max && (*a)->next->data == min)
		sa(a);
	else if ((*a)->data != min && (*a)->next->data == max)
		rra(a);
	else if ((*a)->data == max && (*a)->next->data != min)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->data == max && (*a)->next->data == min)
		ra(a);
	else
	{
		sa(a);
		ra(a);
	}
}

int	is_d_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data < a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	rotate_until_min(t_stack **stack, int min)
{
	while ((*stack)->data != min)
		ra(stack);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	min;

	while (*a && !is_sorted(*a))
	{
		min = find_min(*a);
		rotate_until_min(a, min);
		pb(a, b);
	}
	while (*b && !is_d_sorted(*b))
		pa(a, b);
}
