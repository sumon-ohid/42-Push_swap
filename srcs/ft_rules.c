/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:39:30 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 16:29:28 by msumon           ###   ########.fr       */
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
		last->next = *a;
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

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

void	rotate_until_min(t_stack **stack, int min)
{
	while ((*stack)->data != min)
		ra(stack);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	min;

	while (*a)
	{
		min = find_min(*a);
		rotate_until_min(a, min);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
