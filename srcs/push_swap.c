/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/05 09:20:29 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->next->data;
	stack_a->next->data = stack_a->data;
	stack_a->data = temp;
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->data < stack_a->next->data)
	{
		ft_printf("sa\n");
		sa(stack_a);
	}
	else
		error_msg("Already Sorted!!\n");
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (check_arg(argc, argv) == 0)
			error_msg("Only numbers are allowed\n");
		else
			error_msg("Mininum two numbers are required\n");
	}
	else
	{
		if (check_arg(argc, argv) == 0)
			error_msg("Only numbers are allowed\n");
		if (argc < 5)
		{
			if (check_arg(argc, argv) == 0)
				error_msg("Invalid Argument\n");
			stack_a = create_stack(argc, argv);
			sort_two(stack_a);
			print_stack(stack_a);
		}
		else
			error_msg("Too many arguments\n");
	}
	return (0);
}
