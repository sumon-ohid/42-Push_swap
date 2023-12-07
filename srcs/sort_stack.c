/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 01:21:16 by msumon           ###   ########.fr       */
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
	int	max;

	max = find_max(*a);
	if ((*a)->data == max)
		ra(a);
	else if ((*a)->next->data == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		while ((*a)->data != min)
			ra(a);
		pb(a, b);
		i++;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	rotate_until_min(t_stack **stack, int min)
{
	while ((*stack)->data != min)
		ra(stack);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	min;

	while (*a)
	{
		min = find_min(*a);
		rotate_until_min(a, min);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
