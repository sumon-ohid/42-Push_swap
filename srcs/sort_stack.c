/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/09 20:36:29 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_min(t_stack *stack_min)
{
	int	min;

	min = stack_min->data;
	while (stack_min)
	{
		if (stack_min->data < min)
			min = stack_min->data;
		stack_min = stack_min->next;
	}
	return (min);

}

int	find_max(t_stack *stack_max)
{
	int	max;

	max = stack_max->data;
	while (stack_max)
	{
		if (stack_max->data > max)
			max = stack_max->data;
		stack_max = stack_max->next;
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

int		stack_size(t_stack **stack_1)
{
	int	size;

	size = 0;
	while (*stack_1)
	{
		size++;
		*stack_1 = (*stack_1)->next;
	}
	return (size);
}


void sort_four(t_stack **a, t_stack **b, int size)
{
	int	min;

	while (size > 3)
	{
		min = find_min(*a);
		if ((*a)->data == min)
			pb(a, b);
		else if ((*a)->next->data == min)
		{
			sa(a);
			pb(a, b);
		}
		else if ((*a)->next->next->data == min)
		{
			rra(a);
			rra(a);
			pb(a, b);
		}
		else if((*a)->next->next->next->data == min)
		{
			rra(a);
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
	int	min;

	while (size > 4)
	{
		min = find_min(*a);
		if ((*a)->data == min)
			pb(a, b);
		else if ((*a)->next->data == min)
		{
			ra(a);
			pb(a, b);
		}
		else if ((*a)->next->next->data == min)
		{
			ra(a);
			ra(a);
			pb(a, b);
		}
		else if((*a)->next->next->next->data == min)
		{
			rra(a);
			rra(a);
			pb(a, b);
		}
		else
		{
			rra(a);
			pb(a, b);
		}
		size--;
	}
	if (size == 4 && is_sorted(*a) == 0)
		sort_four(a, b, size);
	while (*b)
		pa(a, b);
}

t_stack *get_last_element(t_stack *stack_last)
{
	while (stack_last->next)
		stack_last = stack_last->next;
	return (stack_last);
}

void sort_stack(t_stack **a, t_stack **b, int size)
{
	int	min;
	t_stack *last;

	while ((*a) && size > 5 && is_sorted(*a) == 0)
	{
		last = get_last_element(*a);
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
	if (size == 5 && is_sorted(*a) == 0)
		sort_five(a, b, size);
	while (*b)
		pa(a, b);
}
