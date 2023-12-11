/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 14:07:52 by msumon           ###   ########.fr       */
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

int get_min_position(t_stack *arr, int min)
{
	int position;

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

void sort_stack(t_stack **a, t_stack **b, int *arr)
{
	int position;
	int min;
    int size;
	t_stack *last;
	(void)arr;

	min = find_min(*a);
	position = get_min_position(*a, min);
    last = get_last_element(*a);
    size = get_stack_size(a);
    while (size > 2)
    {
		last = get_last_element(*a);
        min = find_min(*a);
		position = get_min_position(*a, min);
        if (last->data == min)
        {
            rra(a);
            pb(a, b);
        }
		else if (position < size / 2)
        {
            rotate_until_min(a, min);
            pb(a, b);
        }
		else
		{
			rra_until_min(a, min);
			pb(a, b);
		}
        size--;
    }
    if (size == 2 && is_sorted(*a) == 0)
        sort_three(a);
    while (*b)
        pa(a, b);
}
