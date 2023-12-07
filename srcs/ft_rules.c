/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:57:44 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 01:19:54 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	sa(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	pa(b, a);
	write(1, "pb\n", 3);
}
