/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 16:09:08 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_min_node(t_stack *a)
{
	int		min;
	t_stack	*min_node;
	t_stack	*current;

	min = INT_MAX;
	min_node = NULL;
	current = a;
	while (current)
	{
		if (!current->rank && current->data < min)
		{
			min = current->data;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	initiate_rank(t_stack **a)
{
	int		rank;
	int		size;
	int		i;
	t_stack	*min_node;

	i = 0;
	rank = 1;
	size = get_stack_size(a);
	if (!*a)
		return ;
	while (i < size)
	{
		min_node = find_min_node(*a);
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
