/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:20:50 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 16:02:28 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_last_element(t_stack *stack_last)
{
	while (stack_last->next)
		stack_last = stack_last->next;
	return (stack_last);
}

int	rotate_until_min(t_stack **stack, int num)
{
	int	cost;

	cost = 0;
	while ((*stack)->data != num)
	{
		ra(stack);
		cost++;
	}
	return (cost);
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

void	sort_four(t_stack **a, t_stack **b, int size)
{
	int		min;
	t_stack	*last;

	last = get_last_element(*a);
	while (size > 3)
	{
		min = find_min(*a);
		if (last->data == min)
		{
			rra(a);
			pb(a, b);
		}
		else
		{
			rotate_until_min(a, min);
			pb(a, b);
		}
		size--;
	}
	if (size == 3 && is_sorted(*a) == 0)
		sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int		min;
	t_stack	*last;

	last = get_last_element(*a);
	while (size > 4)
	{
		min = find_min(*a);
		if (last->data == min)
		{
			rra(a);
			pb(a, b);
		}
		else
		{
			rotate_until_min(a, min);
			pb(a, b);
		}
		size--;
	}
	if (size == 4 && is_sorted(*a) == 0)
		sort_four(a, b, size);
	while (*b)
		pa(a, b);
}
