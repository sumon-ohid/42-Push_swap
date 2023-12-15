/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:57:44 by msumon            #+#    #+#             */
/*   Updated: 2023/12/15 10:08:51 by msumon           ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		temp->next = *a;
		if (*a)
			(*a)->prev = temp;
		*a = temp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		temp->next = *b;
		if (*b)
			(*b)->prev = temp;
		*b = temp;
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *a;
	*a = temp;
	write(1, "rra\n", 4);
}
