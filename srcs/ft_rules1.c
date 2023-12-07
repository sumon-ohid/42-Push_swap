/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:39:30 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 01:04:25 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	ra(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
