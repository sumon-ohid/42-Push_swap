/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:28:31 by msumon            #+#    #+#             */
/*   Updated: 2023/12/01 14:47:51 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isrepeat(int num, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	arr[argc - 1];
	int	num;

	int i, j;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != '+')
				return (0);
			j++;
		}
		num = ft_atoi(argv[i]);
		if (ft_isrepeat(num, arr, i - 1) == 0)
		{
			error_msg("Repeated numbers not allowed\n");
			//return (0);
		}
		arr[i - 1] = num;
		i++;
	}
	return (1);
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg("Malloc Failed\n");
		temp->data = ft_atoi(argv[i]);
		temp->next = stack;
		stack = temp;
		i++;
	}
	return (stack);
}
