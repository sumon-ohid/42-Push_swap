/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/05 12:56:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = temp;
	ft_printf("sa\n");
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->data > stack_a->next->data)
		sa(stack_a);
	else
		error_msg();
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_putnbr_fd(stack->data, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	ft_operations(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	if (check_arg(argc, argv) == 1)
	{
		stack_b = create_stack(argc, argv);
		stack_a = create_stack(argc, argv);
		sort_two(stack_a);
	}
	else
		error_msg();
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	else
	{
		ft_operations(argc, argv, stack_a, stack_b);
	}
	return (0);
}
