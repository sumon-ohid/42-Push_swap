/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 22:39:20 by msumon           ###   ########.fr       */
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
	else if ((*a)->data == min && (*a)->next->data == max)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->data == max && (*a)->next->data == min)
		ra(a);
	else if ((*a)->data != max && (*a)->next->data != min)
	{
		sa(a);
		ra(a);
	}
}

void	quicksort(t_stack **stack_a, t_stack **stack_b)
{
	int min, max;
	while (*stack_a && !is_sorted(*stack_a))
	{
		min = find_min(*stack_a);
		max = find_max(*stack_a);
		while (*stack_a && ((*stack_a)->data != min && (*stack_a)->data != max))
		{
			if ((*stack_a)->data > max)
				pb(stack_a, stack_b);
			else
			{
				ra(stack_a);
				min = find_min(*stack_a);
			}
		}
		if (*stack_a && (*stack_a)->data == min)
		{
			pb(stack_a, stack_b);
			min = find_min(*stack_a);
		}
		else if (*stack_a && (*stack_a)->data == max)
			ra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
