/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:54:40 by msumon            #+#    #+#             */
/*   Updated: 2023/12/08 18:17:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		last = *a;
		while (last->next)
			last = last->next;
		temp = last->prev;
		temp->next = NULL;
		last->prev = NULL;
		last->next = *a;
		(*a)->prev = last;
		*a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	rra(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
