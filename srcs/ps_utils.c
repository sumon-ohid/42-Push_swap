/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:28:31 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 15:13:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isrepeat(long num, int *arr, int size)
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
	int		*arr;
	long	num;
	int		i;
	int		j;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		error_msg();
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(('0' <= argv[i][j] && argv[i][j] <= '9') || (j == 0
						&& (argv[i][j] == '+' || argv[i][j] == '-'))))
			{
				free(arr);
				return (0);
			}
			j++;
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN || ft_isrepeat(num, arr, i - 1) == 0)
		{
			free(arr);
			return (0);
		}
		arr[i - 1] = num;
		i++;
	}
	free(arr);
	return (1);
}

t_stack	*create_stack(int *num, int i)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		len;

	len = i - 1;
	stack_a = NULL;
	while (len >= 0)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg();
		temp->data = num[len];
		temp->next = stack_a;
		temp->prev = NULL;
		if (stack_a != NULL)
			stack_a->prev = temp;
		stack_a = temp;
		len--;
	}
	return (stack_a);
}
