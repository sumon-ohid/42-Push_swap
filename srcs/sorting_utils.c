/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:21:51 by msumon            #+#    #+#             */
/*   Updated: 2023/12/20 13:51:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack_min)
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

int	is_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
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

int	get_stack_size(t_stack **stack_1)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = *stack_1;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
