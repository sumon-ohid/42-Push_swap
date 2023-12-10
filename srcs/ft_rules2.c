/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:54:40 by msumon            #+#    #+#             */
/*   Updated: 2023/12/10 22:08:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
