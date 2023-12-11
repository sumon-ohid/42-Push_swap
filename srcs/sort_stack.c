/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 15:58:40 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra_until_min(t_stack **stack, int num)
{
	int	cost;

	cost = 0;
	while ((*stack)->data != num)
	{
		rra(stack);
		cost++;
	}
	return (cost);
}

int	get_min_position(t_stack *arr, int min)
{
	int	position;

	position = 0;
	while (arr)
	{
		if (arr->data == min)
			return (position);
		position++;
		arr = arr->next;
	}
	return (position);
}

void	initiate_rank(t_stack **a)
{
	int		rank;
	int		size;
	int		min;
	int		i;
	t_stack	*min_node;
	t_stack	*current;

	i = 0;
	if (!*a)
		return ;
	rank = 1;
	size = get_stack_size(a);
	while (i < size)
	{
		min = INT_MAX;
		min_node = NULL;
		current = *a;
		while (current)
		{
			if (!current->rank && current->data < min)
			{
				min = current->data;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->rank = rank++;
		i++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*proxy;
	int		counter;
	int		twos;

	initiate_rank(a);
	twos = 1;
	while (is_sorted(*a) == 0)
	{
		counter = get_stack_size(a);
		while (counter)
		{
			proxy = *a;
			if (!(proxy->rank & twos))
				pb(a, b);
			else
				ra(a);
			counter--;
		}
		while (*b)
			pa(a, b);
		twos = twos * 2;
	}
}
